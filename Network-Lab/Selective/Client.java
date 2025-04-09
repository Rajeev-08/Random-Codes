import java.io.*;
import java.net.*;
import java.util.Random;
public class Client{
    public static void main(String[]args)throws Exception{
        Socket client=new Socket("localhost",5555);
        DataInputStream dis=new DataInputStream(client.getInputStream());
        DataOutputStream dos=new DataOutputStream(client.getOutputStream());
        int n=dis.read();
        int v[]=new int[n];

        for(int i=0;i<n;i++){
            v[i]=dis.read();
        }

        Random rand=new Random();
        int r=rand.nextInt(n);
        v[r]=-1;

        for(int i=0;i<n;i++){
            System.out.println("Received Frame is :"+v[i]);
        }

        System.out.println("Requesting to retransmint the frame at index "+r+" Again...");
        dos.write(r);
        dos.flush();
        v[r]=dis.read();

        System.out.println("Frame "+v[r]+ " is received");
        System.out.println("Quiting....");

    }
}
