import java.io.IOException;
import java.net.DatagramPacket;
import java.net.DatagramSocket;
import java.net.InetAddress;

public class Server {
    public static void main(String[] args) throws IOException {
        DatagramSocket ds = new DatagramSocket(1234);
        byte[] receive = new byte[65535];

        System.out.println("Server is running...");

        // Thread to handle receiving messages from the client
        Thread receiveThread = new Thread(() -> {
            try {
                while (true) {
                    DatagramPacket DpReceive = new DatagramPacket(receive, receive.length);
                    ds.receive(DpReceive);
                    String clientMsg = new String(DpReceive.getData(), 0, DpReceive.getLength());

                    System.out.println("Client: " + clientMsg);

                    if (clientMsg.equals("bye")) {
                        System.out.println("Client sent bye... EXITING");
                        ds.close();
                        break;
                    }
                }
            } catch (IOException e) {
                System.out.println("Error in receiving: " + e.getMessage());
            }
        });

        // Thread to handle sending messages to the client
        Thread sendThread = new Thread(() -> {
            try {
                InetAddress clientIP = InetAddress.getLocalHost();
                while (true) {
                    byte[] sendData = new byte[65535];
                    String serverMsg = System.console().readLine(); // Read input from server console

                    sendData = serverMsg.getBytes();
                    DatagramPacket DpSend = new DatagramPacket(sendData, sendData.length, clientIP, 1235);
                    ds.send(DpSend);

                    if (serverMsg.equals("bye")) {
                        ds.close();
                        break;
                    }
                }
            } catch (IOException e) {
                System.out.println("Error in sending: " + e.getMessage());
            }
        });

        receiveThread.start();
        sendThread.start();
    }
}
