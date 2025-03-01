import java.io.*;
import java.net.*;
public class Server extends Thread{
    Thread t1,t2;
    BufferedReader br;
    byte[] rec=new byte[1024];
    byte []send=new byte[1024];
    DatagramSocket server;
    DatagramPacket dp;
    public static InetAddress ip;
    public static int port;
    String str,a;

    Server(){
        try{
        server =new DatagramSocket(5555);
        br=new BufferedReader(new InputStreamReader(System.in));
    }catch(Exception e){

    }
}

public void run(){
    try{
        while(true){
            if (Thread.currentThread()==t1){
                dp=new DatagramPacket(rec,rec.length);
                server.receive(dp);
                ip=dp.getAddress();
                port=dp.getPort();
                str=new String(rec);
                System.out.println("form client :"+str);
            }else{
                a=br.readLine();
                send=a.getBytes();
                dp=new DatagramPacket(send,send.length,ip,port);
                server.send(dp);
            }
        }
    }catch(Exception e){}
}
public static void main(String[]args){
    Server s=new Server();
    s.t1=new Thread(s);
    s.t2=new Thread(s);
    s.t1.start();
    s.t2.start();
}
}
