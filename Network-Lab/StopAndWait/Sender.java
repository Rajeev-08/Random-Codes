import java.io.*;
import java.net.*;
import java.util.Scanner;
public class Sender{
    public static void main(String[]args)throws Exception{

        Socket client=new Socket("localhost",5555);
        BufferedReader br=new BufferedReader(new InputStreamReader(client.getInputStream()));
        PrintStream p=new PrintStream(client.getOutputStream());
        Scanner sc=new Scanner(System.in);
        System.out.println("Enter the No.of Frames :");
        int n=sc.nextInt();
        sc.close();

        for(int i=0;i<=n;){
            if(i==n){
                p.println("exit");
                break;
            }

            p.println(i);
            System.out.println("Frame "+i+" is sent");
            String ack=br.readLine();
            
            if(ack!=null){
                System.out.println("ACK is recived");
                Thread.sleep(2000);
                i++;
            }else{
                p.println(i);
            }
        }
    }
}
