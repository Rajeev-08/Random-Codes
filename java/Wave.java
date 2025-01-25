import javax.swing.*;
import java.awt.*;

public class Wave {
    public static void main(String[] args) {
        JFrame frame = new JFrame("Wave Form Demo");
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setSize(400, 200);
        frame.add(new WaveFormPanel());
        frame.setVisible(true);
    }
}

class WaveFormPanel extends JPanel {
    public void paintComponent(Graphics g) {
        super.paintComponent(g);
        g.setColor(Color.RED);

        int middle = getHeight() / 2;
        int amplitude = middle - 10; // 10 for padding
        int frequency = 2; // number of waves

        for (int x = 0; x < getWidth(); x++) {
            int y = (int) (middle + amplitude * Math.sin(frequency * 2 * Math.PI * x / getWidth()));
            g.drawLine(x, y, x, y);
        }
    }
}

