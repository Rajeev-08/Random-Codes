import java.awt.FlowLayout;
import java.awt.event.*;
import javax.swing.*;
class T extends JFrame implements ActionListener {
JButton b1;
JButton b2;
JButton b3;
JButton b4;
JButton b5;
JButton b6;
JButton b7;
JButton b8;
JButton b9;
JButton b10;JButton add;JButton sub;JButton mul;JButton div;JButton eq;JButton C;JTextField t;


static int a=0,b=0,result=0;
static int operator=0;
public T(){
t=new JTextField(20);
b1=new JButton("1");
b2=new JButton("2");
b3=new JButton("3");
add=new JButton("+");

b4=new JButton("4");
b5=new JButton("5");
b6=new JButton("6");
sub=new JButton("-");

b7=new JButton("7");
b8=new JButton("8");
b9=new JButton("9");
mul=new JButton("*");

b10=new JButton("0");
div=new JButton("/");
eq=new JButton("=");
C=new JButton("C");


add(t);
add(b1);
add(b2);
add(b3);
add(add);

add(b4);
add(b5);
add(b6);
add(sub);

add(b7);
add(b8);
add(b9);
add(mul);

add(b10);
add(div);
add(eq);
add(C);

b1.addActionListener(this);b2.addActionListener(this);
b3.addActionListener(this);b4.addActionListener(this);
b5.addActionListener(this);b6.addActionListener(this);
b7.addActionListener(this);b8.addActionListener(this);
b9.addActionListener(this);b10.addActionListener(this);
mul.addActionListener(this);add.addActionListener(this);
sub.addActionListener(this);div.addActionListener(this);
eq.addActionListener(this);C.addActionListener(this);





    setLayout(new FlowLayout());
    setResizable(false);
    setSize(200,200);
    setDefaultCloseOperation(EXIT_ON_CLOSE);
    setVisible(true);
}
public void actionPerformed(ActionEvent e){
    if(e.getSource()==b1){
        t.setText(t.getText().concat("1"));
    }
    if(e.getSource()==b2){
        t.setText(t.getText()+"2");
    }
    if(e.getSource()==b3){
        t.setText(t.getText()+"3");
    }
    if(e.getSource()==b4){
        t.setText(t.getText()+"4");
    }
    if(e.getSource()==b5){
        t.setText(t.getText()+"5");
    }
    if(e.getSource()==b6){
        t.setText(t.getText()+"6");
    }
    if(e.getSource()==b7){
        t.setText(t.getText()+"7");
    }
    if(e.getSource()==b8){
        t.setText(t.getText()+"8");
    }
    if(e.getSource()==b9){
        t.setText(t.getText()+"9");
    }
    if(e.getSource()==b10){
        t.setText(t.getText()+"0");
    }
    if(e.getSource()==add){
        a=Integer.parseInt(t.getText());
        operator=1;
        t.setText("");     
    }
    if(e.getSource()==sub){
        a=Integer.parseInt(t.getText());
        operator=2;
        t.setText("");     
    }
    if(e.getSource()==mul){
        a=Integer.parseInt(t.getText());
        operator=3;
        t.setText("");     
    }
    if(e.getSource()==div){
        a=Integer.parseInt(t.getText());
        operator=4;
        t.setText("");     
    }
    if(e.getSource()==eq){
        b=Integer.parseInt(t.getText());
        switch(operator){
            case 1:result=a+b;
                    break;
            case 2: result=a-b;
                    break;
            case 3 :result=a*b;
                    break;
            case 4:result=a/b;
                    break;
            default: result=0;
        }
        t.setText(""+result);
    }
if(e.getSource()==C){
    t.setText("");  
}

}

public static void main(String[] args) {
    new T();
}

}