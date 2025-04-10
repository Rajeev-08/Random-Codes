import java.io.*;
import java.net.*;
public class Server{
    public static void main(String[]args) throws Exception{
        int a[]={30,40,50,60,70,80,90,100};
        int n=a.length;
        ServerSocket server=new ServerSocket(5555);
        System.out.println("Waiting for connection...");
        Socket client=server.accept();
        DataInputStream dis=new DataInputStream(client.getInputStream());
        DataOutputStream dos=new DataOutputStream(client.getOutputStream());
        System.out.println("No.of packets sent is : "+n);
        dos.write(n);
        dos.flush();
        for(int i=0;i<n;i++){
            dos.write(a[i]);
            dos.flush();
        }
        int k=dis.read();
        dos.write(a[k]);
        dos.flush();

    }
}
