import java.io.IOException;
import java.net.DatagramPacket;
import java.net.DatagramSocket;
import java.net.InetAddress;
import java.util.Scanner;

public class Client {
    public static void main(String[] args) throws IOException {
        DatagramSocket ds = new DatagramSocket(1235); // Different port from the server
        InetAddress ip = InetAddress.getLocalHost();

        System.out.println("Client is running...");

        // Thread to handle sending messages to the server
        Thread sendThread = new Thread(() -> {
            try {
                Scanner sc = new Scanner(System.in);
                while (true) {
                    String msg = sc.nextLine();
                    byte[] buf = msg.getBytes();
                    DatagramPacket DpSend = new DatagramPacket(buf, buf.length, ip, 1234);
                    ds.send(DpSend);

                    if (msg.equals("bye")) {
                        ds.close();
                        sc.close();
                        break;
                    }
                }
            } catch (IOException e) {
                System.out.println("Error in sending: " + e.getMessage());
            }
        });

        // Thread to handle receiving messages from the server
        Thread receiveThread = new Thread(() -> {
            try {
                while (true) {
                    byte[] receive = new byte[65535];
                    DatagramPacket DpReceive = new DatagramPacket(receive, receive.length);
                    ds.receive(DpReceive);
                    String serverMsg = new String(DpReceive.getData(), 0, DpReceive.getLength());

                    System.out.println("Server: " + serverMsg);

                    if (serverMsg.equals("bye")) {
                        ds.close();
                        break;
                    }
                }
            } catch (IOException e) {
                System.out.println("Error in receiving: " + e.getMessage());
            }
        });

        sendThread.start();
        receiveThread.start();
    }
}
