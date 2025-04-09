import java.io.*;
import java.net.*;

public class R{
    public static void main(String[]args)throws Exception{

        ServerSocket server=new ServerSocket(5555);
        System.out.println("Waiting For connection...");
        Socket client=server.accept();
        BufferedReader br=new BufferedReader(new InputStreamReader(client.getInputStream()));
        PrintStream p=new PrintStream(client.getOutputStream());
        String temp="";

        while(temp.compareTo("exit")!=0){
            Thread.sleep(1000);
            temp=br.readLine();

            if(temp.compareTo("exit")==0)
                break;

            System.out.println("Frame "+temp+" is received");
            Thread.sleep(500);
            p.println("Ack");

        }
        
        System.out.println("ALL FRAMES RECEIVED SUCCESSFULLY");
    }
}
