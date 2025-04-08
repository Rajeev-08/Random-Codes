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
    String a,b;

    Client() {
        try {
            client = new DatagramSocket();
            ip = InetAddress.getLocalHost();
            br = new BufferedReader(new InputStreamReader(System.in));
        } catch (Exception e) {}
    }

    public void run() {
        try {
            while (true) {
                if (Thread.currentThread()==t1) {
                    dp = new DatagramPacket(rec, rec.length);
                    client.receive(dp);
                    a = new String(rec);
                    System.out.println("From server: " +a);
                } else {
                    b = br.readLine();
                    send = b.getBytes();
                    dp = new DatagramPacket(send, send.length, ip, 5555);
                    client.send(dp);
                }
            }
        } catch (Exception e) {}
    }

    public static void main(String[] args) {
        Client c = new Client();
        c.t1 = new Thread(c);
        c.t2 = new Thread(c);
        c.t1.start();
        c.t2.start();
    }
}
