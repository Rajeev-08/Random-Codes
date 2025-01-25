//15

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;

public class AlternateUpperCase {

    public static void main(String[] args) {
        // Specify the input and output file names
        String inputFile = ("C:\\Users\\rajiv\\Downloads\\S3\\JAVA prev\\f5.txt");
        String outputFile = "output.txt";

        try {
            // Read the content from the input file
            String inputContent = readFromFile(inputFile);

            // Transform every alternate character to uppercase
            String modifiedContent = alternateUpperCase(inputContent);

            // Write the modified content to the output file
            writeToFile(outputFile, modifiedContent);

            System.out.println("Content has been modified and written to 'output.txt'.");
        } catch (IOException e) {
            // Handle exceptions
            e.printStackTrace();
        }
    }

    // Method to read content from a file
    private static String readFromFile(String fileName) throws IOException {
        StringBuilder content = new StringBuilder();

        try (BufferedReader reader = new BufferedReader(new FileReader(fileName))) {
            String line;
            while ((line = reader.readLine()) != null) {
                content.append(line).append("\n");
            }
        }

        return content.toString();
    }

    // Method to transform every alternate character to uppercase
    private static String alternateUpperCase(String input) {
        char[] charArray = input.toCharArray();

        for (int i = 0; i < charArray.length; i += 2) {
            charArray[i] = Character.toUpperCase(charArray[i]);
        }

        return new String(charArray);
    }

    // Method to write content to a file
    private static void writeToFile(String fileName, String content) throws IOException {
        try (BufferedWriter writer = new BufferedWriter(new FileWriter(fileName))) {
            writer.write(content);
        }
    }
}
