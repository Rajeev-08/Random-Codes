// Custom exception class
class CustomException extends Exception {
    public CustomException(String message) {
        super(message);
    }
}

// Example class using the custom exception
public class UserDefinedExceptionExample {

    // Method that may throw the custom exception
    public static void validateAge(int age) throws CustomException {
        if (age < 18) {
            throw new CustomException("Age must be 18 or above for this operation.");
        } else {
            System.out.println("Valid age: " + age);
        }
    }

    public static void main(String[] args) {
        try {
            // Calling the method that may throw the custom exception
            validateAge(16);
        } catch (CustomException e) {
            // Handling the custom exception
            System.out.println("Custom Exception Caught: " + e.getMessage());
        }
    }
}

