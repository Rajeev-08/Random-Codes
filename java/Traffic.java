import javax.swing.*;
import java.awt.*;
import java.awt.event.*;
class Traffic extends JFrame implements ItemListener{
    Checkbox stop,ready,go;
    CheckboxGroup g;
    
Traffic(){
    g=new CheckboxGroup();
    stop=new Checkbox("stop",g,false);
    ready=new Checkbox("ready",g,false);
    go=new Checkbox("go",g,false);

    stop.addItemListener(this);
    ready.addItemListener(this);
    go.addItemListener(this);
    
    add(stop);
    add(ready);
    add(go);

    setLayout(new FlowLayout());
    setTitle("TrafficLight");
    setSize(600,600);
    setDefaultCloseOperation(EXIT_ON_CLOSE);
    setVisible(true);
}
public void itemStateChanged(ItemEvent e){
    repaint();
}
public void paint(Graphics g){
    g.drawOval(165,40,50,50);
    g.drawOval(165,100,50,50);
    g.drawOval(165,160,50,50);

    if(stop.getState()){
        g.setColor(Color.red);
        g.fillOval(165,40,50,50);
    }
     if(ready.getState()){
        g.setColor(Color.orange);
        g.fillOval(165,100,50,50);
    }
    if(go.getState()){
        g.setColor(Color.green);
        g.fillOval(165,160,50,50);
    }

    
    if (!stop.getState()) {
        g.setColor(Color.WHITE);
        g.fillOval(165, 40, 50, 50);
    }
    if (!ready.getState()) {
        g.setColor(Color.WHITE);
        g.fillOval(165, 100, 50, 50);
    }
    if (!go.getState()) {
        g.setColor(Color.WHITE);
        g.fillOval(165, 160, 50, 50);
    }
}
public static void main(String[] args) {
    new Traffic();
}

}