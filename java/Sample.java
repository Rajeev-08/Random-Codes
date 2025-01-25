//Q11
public class Sample {

    // Method to find the frequency of each vowel in a string
    public static void findVowelFrequency(String input) {
        input = input.toLowerCase(); // Convert the input to lowercase for case-insensitive comparison
        int[] frequency = new int[5]; // Array to store the frequency of each vowel (a, e, i, o, u)

        for (int i = 0; i < input.length(); i++) {
            char ch = input.charAt(i);
            if (ch == 'a') {
                frequency[0]++;
            } else if (ch == 'e') {
                frequency[1]++;
            } else if (ch == 'i') {
                frequency[2]++;
            } else if (ch == 'o') {
                frequency[3]++;
            } else if (ch == 'u') {
                frequency[4]++;
            }
        }

        // Display the frequency of each vowel
        System.out.println("Frequency of vowels in the string:");
        System.out.println("a: " + frequency[0]);
        System.out.println("e: " + frequency[1]);
        System.out.println("i: " + frequency[2]);
        System.out.println("o: " + frequency[3]);
        System.out.println("u: " + frequency[4]);
    }

    // Method to display the string without vowels
    public static void removeVowels(String input) {
        String result = input.replaceAll("[aeiouAEIOU]", ""); // Remove vowels using regular expression

        // Display the string without vowels
        System.out.println("String without vowels: " + result);
    }

    public static void main(String[] args) {
        String inputString = "Hello World! This is a Sample String.";

        // Task a: Find the frequency of each vowel in the string
        findVowelFrequency(inputString);

        // Task b: Display the string without vowels
        removeVowels(inputString);
    }
}

