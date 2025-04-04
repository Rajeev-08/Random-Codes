import java.io.*;
import java.util.Random;
import java.net.*;
import java.lang.System;
public class Client{
    public static void main(String[]args)throws IOException{
        try{
            int n=0;
            int v[]=new int[10];
            Random rand=new Random();
            int rnum=0;

            InetAddress add=InetAddress.getByName("localhost");
            System.out.println(add);
            Socket connection=new Socket(add,8011);
            DataInputStream in=new DataInputStream(connection.getInputStream());
            DataOutputStream out=new DataOutputStream(connection.getOutputStream());
            int p=in.read();
            System.out.println("number of frame is : "+p);
            for(int i=0;i<p;i++){
                v[i]=in.read();
                System.out.println(v[i]);
            }
            rnum=rand.nextInt(p);

            v[rnum]=-1;
            for (int i=0;i<p;i++){
                System.out.println("Received Frame is : "+v[i]);
            }
            for(int i=0;i<p;i++){
                if (v[i]==-1){
                    System.out.println("Req to retansmit from packet no "+(i+1)+ " again");
                    n=i;
                    out.write(n);
                    out.flush();
                }
            }
            System.out.println();
            v[n]=in.read();
            System.out.println("receiver frame is :"+v[n]);
            System.out.println("quiting..");

        }catch(Exception e){}
    }
}
