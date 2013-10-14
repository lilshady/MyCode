/**
 * Created with IntelliJ IDEA.
 * User: hp
 * Date: 13-7-22
 * Time: 下午3:11
 * To change this template use File | Settings | File Templates.
 */
import java.awt.*;
import java.awt.event.*;
import java.util.*;
import java.net.*;
import java.io.*;
import java.nio.channels.*;
import javax.swing.*;
public class InterruptibleSocketTest {
    public static void main(String[] args)
    {
        EventQueue.invokeLater(new Runnable() {
            @Override
            public void run() {
                JFrame frame = new  InterruptibleSocketFrame();
                frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
                frame.setVisible(true);
            }
        });
    }
}
class  InterruptibleSocketFrame extends JFrame
{
    public InterruptibleSocketFrame()
    {
        setSize(WIDTH,HEIGHT);
        setTitle("InterruptibleSocketTest");

        JPanel northPanel = new JPanel();
        add(northPanel,BorderLayout.NORTH);

        messages = new JTextArea();
        add(new JScrollPane(messages));

        interruptibleButton = new JButton ("Interruptible");
        blockingButton = new JButton("Blocking");

        northPanel.add(interruptibleButton);
        northPanel.add( blockingButton);

        interruptibleButton.addActionListener(new ActionListener()
        {
            public void actionPerformed(ActionEvent event)
            {
                interruptibleButton.setEnabled(false);
                blockingButton.setEnabled(false);
                cancelButton.setEnabled(true);
                connectThread = new Thread(new Runnable() {
                    @Override
                    public void run() {
                        try {
                            connectInterruptibly();
                        }
                        catch (IOException e)
                        {
                            messages.append("\nInterruptibleSocketTest.connectInterruptibly:" + e);

                        }
                    }
                });
                connectThread.start();

            }
        }
        );
        blockingButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                interruptibleButton.setEnabled(false);
                blockingButton.setEnabled(false);
                cancelButton.setEnabled(true);
                connectThread = new Thread(new Runnable() {
                    @Override
                    public void run() {
                        try {
                            connectBlocking();
                        }
                        catch (IOException e)
                        {
                             messages.append("\nInterruptibleSocketTest.connectBlocking:" + e);
                        }
                    }
                });
                connectThread.start();
            }
        });

        cancelButton = new JButton("cancel");
        cancelButton.setEnabled(false);
        northPanel.add(cancelButton);
        cancelButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                connectThread.interrupt();
                cancelButton.setEnabled(false);
            }
        });
        server = new TestServer();
        new Thread(server).start();

    }
    public void connectInterruptibly() throws IOException
    {
        messages.append("Interruptible:\n");
        SocketChannel channel = SocketChannel.open(new InetSocketAddress("localhost",8189));
        try
        {
            in = new Scanner(channel);
            while(!Thread.currentThread().isInterrupted())
            {
                messages.append("Reading");
                if (in.hasNextLine())
                {
                    String line = in.nextLine();
                    messages.append(line);
                    messages.append("\n");
                }
            }

        }
        finally
        {
            channel.close();
            EventQueue.invokeLater(new Runnable() {
                @Override
                public void run() {
                    messages.append("channel closed");
                    interruptibleButton.setEnabled(true);
                    blockingButton.setEnabled(true);

                }
            });

        }
    }
    public void connectBlocking() throws IOException
    {
        messages.append("Blocking");
        Socket sock = new Socket("localhost",8189);
        try
        {
            in = new Scanner(sock.getInputStream());
            while(!Thread.currentThread().isInterrupted())
            {
                messages.append("Reading");
                if (in.hasNextLine())
                {
                    String line = in.nextLine();
                    messages.append(line);
                    messages.append("\n");
                }
            }

        }
        finally
        {
            sock.close();
            EventQueue.invokeLater(new Runnable() {
                @Override
                public void run() {
                    messages.append("socket closed");
                    interruptibleButton.setEnabled(true);
                    blockingButton.setEnabled(true);

                }
            });

        }
    }

    class TestServer implements Runnable
    {
        public void run()
        {
            try
            {
                ServerSocket s = new ServerSocket(8189);
                while(true)
                {
                    Socket incoming = s.accept();
                    Runnable r = new TestServerHandler(incoming);
                    Thread t = new Thread(r);
                    t.start();
                }


            }
            catch (IOException e)
            {
                messages.append("\nTestServer.run:" + e);
            }
        }
    }
    class TestServerHandler implements Runnable
    {
          public TestServerHandler(Socket i)
          {
              incoming = i;

          }
        public void run()
        {
            try
            {
                OutputStream outStream = incoming.getOutputStream();
                PrintWriter out = new PrintWriter(outStream,true);
                while (counter < 100)
                {
                    counter++;
                    if (counter <= 10)
                        out.println(counter);
                    Thread.sleep(100);
                }
                incoming.close();
                messages.append("Closing server");
            }
            catch (Exception e)
            {
                messages.append("\nTestServerHandler.run:" + e);
            }
        }
        private Socket incoming;
        private int counter;
    }
    private Scanner in;
    private JButton interruptibleButton;
    private JButton blockingButton;
    private JButton cancelButton;
    private JTextArea messages;
    private TestServer server;
    private Thread connectThread;

    public static final int WIDTH = 300;
    public static final int Height= 300;

}
