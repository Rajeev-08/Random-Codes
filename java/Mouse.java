import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

class Mouse extends JFrame implements MouseListener {
    
    JLabel label;

    public Mouse() {
       label = new JLabel("No mouse event yet");
        add(label);
        setTitle("Mouse Event Example");
        setSize(300, 200);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        addMouseListener(this);

        setVisible(true);
    }

    public void mouseClicked(MouseEvent e) {
        label.setText("Mouse Clicked at (" + e.getX() + ", " + e.getY() + ")");
    }

    public void mousePressed(MouseEvent e) {
        label.setText("Mouse Pressed at (" + e.getX() + ", " + e.getY() + ")");
    }

    public void mouseReleased(MouseEvent e) {
        label.setText("Mouse Released at (" + e.getX() + ", " + e.getY() + ")");
    }

    public void mouseEntered(MouseEvent e) {
        label.setText("Mouse Entered at (" + e.getX() + ", " + e.getY() + ")");
    }

    public void mouseExited(MouseEvent e) {
        label.setText("Mouse Exited at (" + e.getX() + ", " + e.getY() + ")");
    }

    public static void main(String[] args) {
         new Mouse();
    }
}
//adapter class
/*import javax.swing.*;
import java.awt.event.*;

public class Main {
    public static void main(String[] args) {
        JFrame frame = new JFrame("Mouse Event Demo");
        frame.setSize(300, 200);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        JLabel label = new JLabel("No mouse event yet");
        frame.add(label);

        frame.addMouseListener(new MouseAdapter() {
            public void mouseClicked(MouseEvent e) {
                label.setText("Mouse clicked at (" + e.getX() + ", " + e.getY() + ")");
            }

            public void mouseEntered(MouseEvent e) {
                label.setText("Mouse entered the frame");
            }

            public void mouseExited(MouseEvent e) {
                label.setText("Mouse exited the frame");
            }
        });

        frame.setVisible(true);
    }
}
 */