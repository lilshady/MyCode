/**
 * Created with IntelliJ IDEA.
 * User: hp
 * Date: 13-7-4
 * Time: 下午6:12
 * To change this template use File | Settings | File Templates.
 */
import java.awt.EventQueue;
import java.awt.event.*;
import javax.swing.*;
public class ActionTest
{
    public static void main(String[] args)
    {
        EventQueue.invokeLater(new Runnable() {
            @Override
            public void run() {
                MenuFrame frame = new MenuFrame();
                frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
                frame.setVisible(true);
            }
        });
    }
}
class MenuFrame extends JFrame
{
    public MenuFrame()
    {
       setTitle("MenuTest");
       setSize(DEFAULT_WIDTH,DEFAULT_HEIGHT);

       JMenu fileMenu = new JMenu("File");
       fileMenu.add(new TestAction("New"));

       JMenuItem openItem = fileMenu.add(new TestAction("Open"));
       openItem.setAccelerator(KeyStroke.getKeyStroke("ctrl o"));

       fileMenu.addSeparator();

       saveAction = new TestAction("Save");
       JMenuItem  saveItem = fileMenu.add(saveAction);
       saveItem.setAccelerator(KeyStroke.getKeyStroke("ctrl s"));

       saveAsAction =new TestAction("save as");
       fileMenu.add(saveAsAction);
       fileMenu.addSeparator();

       fileMenu.add(new AbstractAction("Exit")
       {
           public void actionPerformed(ActionEvent event)
           {
               System.exit(0);
           }
       }
       );

       readonlyItem = new JCheckBoxMenuItem("Read-Only");
       readonlyItem.addActionListener(new ActionListener() {
           @Override
           public void actionPerformed(ActionEvent e) {
               boolean saveOk = !readonlyItem.isSelected();
               saveAction.setEnabled(saveOk);
               saveAsAction.setEnabled(saveOk);
           }
       });

       ButtonGroup group = new ButtonGroup();

       JRadioButtonMenuItem insert = new JRadioButtonMenuItem("Insert");
       insert.setSelected(true);
       JRadioButtonMenuItem overtypeItem = new JRadioButtonMenuItem("Overtype");

       group.add(insert);
       group.add(overtypeItem);

       Action cutAction = new TestAction("cut");
       cutAction.putValue(Action.SMALL_ICON,new ImageIcon("cut.gif"));
       Action copyAction = new TestAction("copy");
       copyAction.putValue(Action.SMALL_ICON,new ImageIcon("copy.gif"));
       Action pasteAction = new TestAction("paste");
       pasteAction.putValue(Action.SMALL_ICON,new ImageIcon("paste.gif"));

       JMenu editMenu = new JMenu("Edit");
       editMenu.add(cutAction);
       editMenu.add(copyAction);
       editMenu.add(pasteAction);

       JMenu optionMenu = new JMenu("option");
       optionMenu.add(readonlyItem);
       optionMenu.addSeparator();
       optionMenu.add(insert);
       optionMenu.add(overtypeItem);

       editMenu.addSeparator();
       editMenu.add(optionMenu);

       JMenu helpMenu = new JMenu("help");
       helpMenu.setMnemonic('H');
       JMenuItem indexItem = new JMenuItem("Index");
       indexItem.setMnemonic('I');
       helpMenu.add(indexItem);

       Action aboutAction = new TestAction("About");
       aboutAction.putValue(Action.MNEMONIC_KEY,new Integer('A'));
       helpMenu.add(aboutAction);

       JMenuBar menuBar = new JMenuBar();
       setJMenuBar(menuBar);
       menuBar.add(fileMenu);
       menuBar.add(editMenu);

       menuBar.add(helpMenu);

       popup = new JPopupMenu();
       popup.add(copyAction);
       popup.add(cutAction);
       popup.add(pasteAction);

       JPanel panel = new JPanel();
       panel.setComponentPopupMenu(popup);
       add(panel);

       panel.addMouseListener(new MouseAdapter() {
       });





    }
    public static  final int DEFAULT_WIDTH = 300;
    public static  final int DEFAULT_HEIGHT = 200;

    private Action saveAction;
    private Action saveAsAction;
    private JCheckBoxMenuItem readonlyItem;
    private JPopupMenu popup;
}
class TestAction extends AbstractAction
{
    public TestAction(String name)
    {
        super(name);
    }
    public void actionPerformed(ActionEvent event)
    {
        System.out.println(getValue(Action.NAME) + "selected");
    }
}