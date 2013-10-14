/**
 * Created with IntelliJ IDEA.
 * User: hp
 * Date: 13-7-7
 * Time: 上午9:32
 * To change this template use File | Settings | File Templates.
 */
import java.awt.*;
import javax.swing.*;
public class NotHelloWorld extends JApplet
{

    public void init()
    {
        EventQueue.invokeLater(new Runnable() {
            @Override
            public void run() {
                JLabel label = new JLabel("not a hello world",SwingConstants.CENTER);
                add(label);
            }
        });
    }

}
