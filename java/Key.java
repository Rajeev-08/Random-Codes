//Write a Java program for handling key events using Adapter classes (general)
import javax.swing.*;
import java.awt.event.*;

public class Key {
    public static void main(String[] args) {
        JFrame frame = new JFrame("Key Event Demo");
        frame.setSize(300, 200);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        JLabel label = new JLabel("No key event yet");
        label.setFocusable(true);
        frame.add(label);

        label.addKeyListener(new KeyAdapter() {
            public void keyPressed(KeyEvent e) {
                label.setText("Key pressed: " + KeyEvent.getKeyText(e.getKeyCode()));
            }

            public void keyReleased(KeyEvent e) {
                label.setText("Key released: " + KeyEvent.getKeyText(e.getKeyCode()));
            }
            public void keyTyped(KeyEvent e) {
                System.out.println("Key Typed: " + e.getKeyChar());
            }
        });

        frame.setVisible(true);
    }
}
