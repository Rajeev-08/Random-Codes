import java.io.*;
import java.net.*;

public class TCPClient extends Thread{
    Thread t1,t2;
    String a,b;
    BufferedReader br1,br2;
    PrintWriter p;
    Socket client;


    TCPClient(){
        try{
         client=new Socket("127.0.0.1",5555);
        br1=new BufferedReader(new InputStreamReader(System.in));
         br2=new BufferedReader(new InputStreamReader(client.getInputStream()));
         p=new PrintWriter(client.getOutputStream(),true);
    }catch(Exception e){}
}

    public void run(){
        try{
            while(true){
                if(Thread.currentThread()==t1){
                    a=br1.readLine();
                    p.println(a);


                }else{
                    b=br2.readLine();
                    System.out.println("server says "+b);

                }
            }
        }catch(Exception e){}
    }

    public static void main(String[]args){
        TCPClient c=new TCPClient();
        c.t1=new Thread(c);
        c.t2=new Thread(c);
        c.t1.start();
        c.t2.start();
    }
}
