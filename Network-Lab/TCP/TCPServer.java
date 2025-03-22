import java.io.*;
import java.net.*;

public class TCPServer extends Thread{
    Thread t1,t2;
    String a,b;
    BufferedReader br1,br2;
    ServerSocket server;
    Socket client;
    PrintWriter p;
    
    TCPServer(){

        try{
            server=new ServerSocket(5555);
            client=server.accept();
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
                    System.out.println("from client :"+b);
                }
            }
        }catch(Exception e){}
        }

        public static void main(String[]args){
            TCPServer s=new TCPServer();
            s.t1= new Thread(s);
            s.t2=new Thread(s);
            s.t1.start();
            s.t2.start();

        }
    }

