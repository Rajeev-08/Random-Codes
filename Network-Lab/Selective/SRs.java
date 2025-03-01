import java.io.*;
import java.net.*;
public class Server{
    public static void main(String[]args){
        try{
        int a[]={30,40,50,60,70,80,90,100};
        ServerSocket server=new ServerSocket(8011);
        System.out.println("waiting for connection..");
        Socket client=server.accept();
        DataInputStream dis=new DataInputStream(client.getInputStream());
        DataOutputStream dos=new DataOutputStream(client.getOutputStream());
        System.out.println("the number of packet sent is :"+a.length);
        int y=a.length;
        dos.write(y);
        dos.flush();
        for (int i=0;i<y;i++){
            dos.write(a[i]);
            dos.flush();
        }
        int k=dis.read();
        dos.write(a[k]);
        dos.flush();


    }catch(Exception e){}
}
}
