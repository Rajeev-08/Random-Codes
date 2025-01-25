import java.io.Serializable;
import java.io.*;
class User implements Serializable{
    String name;
    String pass;
    public void say(){
        System.out.println("hello "+name);
    }
}

public class Serial {
    public static void main(String[] args) {
        User u=new User();
        u.name="raju";
        u.pass="12345678";
        
        try{
        FileOutputStream f=new FileOutputStream("f1.txt");
        ObjectOutputStream o=new ObjectOutputStream(f);
        o.writeObject(u);
        f.close();
        o.close();
        System.out.println("serialized");
        }catch(Exception e){
            System.out.println(e);
        }


        }
    }
    

