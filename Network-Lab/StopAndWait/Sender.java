import java.io.*;
import java.net.*;
import java.util.Scanner;

class Sender{
    public static void main(String []args) throws Exception{
        Sender s=new Sender();
        s.run();
    }
    public void run() throws Exception{
        Scanner sc=new Scanner(System.in);
        Socket client=new Socket("localhost",5555);
        BufferedReader br =new BufferedReader(new InputStreamReader(client.getInputStream()));
        PrintStream p=new PrintStream(client.getOutputStream());
        System.out.println("enter the no.of frames:");
        int n=sc.nextInt();
        for(int i=0;i<=n;){
            if(i==n){
                p.println("exit");
                break;
            }
            System.out.println("frame "+i+" was sent");
            p.println(i);
            String ack=br.readLine();
            if(ack!=null){
                System.out.println(" ack received");
                Thread.sleep(2000);
                i++;
            }else{
                p.println(i);
            }
        }
    }
}
