import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class WriteInt {

    public static void main(String[] args) {
        // Create BufferedReader for user input
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));

        try {
            // Read a line of integers from the user
            System.out.print("Enter a line of integers separated by spaces: ");
            String inputLine = reader.readLine();

            // Tokenize the input line using StringTokenizer
            StringTokenizer tokenizer = new StringTokenizer(inputLine);

            // Create FileWriter and BufferedWriter to write to 'data.txt'
            FileWriter fileWriter = new FileWriter("data.txt");
            BufferedWriter bufferedWriter = new BufferedWriter(fileWriter);

            int sum = 0;

            // Write each integer and calculate the sum
            while (tokenizer.hasMoreTokens()) {
                String token = tokenizer.nextToken();
                int num = Integer.parseInt(token);

                // Write each integer to the file
                bufferedWriter.write("Integer: " + num + "\n");

                // Calculate the sum
                sum += num; 
            }

            // Write the sum to the file
            bufferedWriter.write("Sum: " + sum);

            bufferedWriter.close();

            System.out.println("Data has been written to 'data.txt'.");
        } catch (IOException | NumberFormatException e) {
            e.printStackTrace();
        } finally {
            try {
                reader.close();
            } catch (IOException e) {
                e.printStackTrace();
            }
        }
    }
}
