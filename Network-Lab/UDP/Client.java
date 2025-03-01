import java.io.*;
import java.net.*;

public class Client extends Thread {
    Thread t1, t2;
    DatagramSocket client;
    DatagramPacket dp;
    BufferedReader br;
    byte[] send = new byte[1024];
    byte[] rec = new byte[1024];
    InetAddress ip;
    String str, a;

    Client() {
        try {
            client = new DatagramSocket();
            ip = InetAddress.getLocalHost();
            br = new BufferedReader(new InputStreamReader(System.in));
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    public void run() {
        try {
            while (true) {
                if (Thread.currentThread()==t1) {
                    dp = new DatagramPacket(rec, rec.length);
                    client.receive(dp);
                    
                    
                    str = new String(rec);
                    System.out.println("From server: " + str);
                } else {
                    a = br.readLine();
                    send = a.getBytes();
                    dp = new DatagramPacket(send, send.length, ip, 5555);
                    client.send(dp);
                }
            }
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    public static void main(String[] args) {
        Client c = new Client();
        c.t1 = new Thread(c, "Receiver");
        c.t2 = new Thread(c, "Sender");
        c.t1.start();
        c.t2.start();
    }
}
