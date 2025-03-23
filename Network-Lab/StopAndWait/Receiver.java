import java.io.*;
import java.net.*;

public class Receiver{
    public static void main(String[]args) throws Exception{
        Receiver r= new Receiver();
        r.run();
    }
    public void run()throws Exception{
        ServerSocket server= new ServerSocket(5555);
        Socket client=server.accept();

        String temp="abc";
        BufferedReader br=new BufferedReader(new InputStreamReader(client.getInputStream()));
        PrintStream p=new PrintStream(client.getOutputStream());

        while(temp.compareTo("exit")!=0){
            Thread.sleep(1000);
            temp=br.readLine();
            if(temp.compareTo("exit")==0){
                break;
            }

            System.out.println("Frame "+temp+" was received");
            Thread.sleep(500);
            p.println("received");
        }
        System.out.println("ALL FRAMES RECEIVED");
    } 
}
