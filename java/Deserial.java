
import java.io.*;


public class Deserial {
    public static void main(String[] args) {
        
        User u;
        try{
        FileInputStream f=new FileInputStream("C:\\Users\\rajiv\\Downloads\\code\\java\\f1.txt");
        ObjectInputStream o=new ObjectInputStream(f);
     u=(User)o.readObject();       
            f.close();
            o.close();
            System.out.println("...deserialized successfully...");
            System.out.println("->...info...<-");
            System.out.println("user : " +u.name+"\npass : "+u.pass);
    }catch(Exception e){
        System.out.println(e.getMessage());
    }
}
    
}
