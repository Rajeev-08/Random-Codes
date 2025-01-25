//q12
public class Dummy {

    private int[] numbers;

    public Dummy(int[] numbers) {
        this.numbers = numbers;
    }

    public int findSecondLargest() {

        int largest = Integer.MIN_VALUE;
        int secondLargest = Integer.MIN_VALUE;

        for (int number : numbers) {
            if (number > largest) {
                secondLargest = largest;
                largest = number;
            } else if (number > secondLargest && number != largest) {
                secondLargest = number;
            }
        }

        return secondLargest;
    }

    public int findSecondSmallest() {

        int smallest = Integer.MAX_VALUE;
        int secondSmallest = Integer.MAX_VALUE;

        for (int number : numbers) {
            if (number < smallest) {
                secondSmallest = smallest;
                smallest = number;
            } else if (number < secondSmallest && number != smallest) {
                secondSmallest = number;
            }
        }

        return secondSmallest;
    }

    public static void main(String[] args) {
        int[] numberArray = {5, 2, 8, 1, 7, 3, 6, 4};

        Dummy dummyObject = new Dummy(numberArray);

        int secondLargest = dummyObject.findSecondLargest();
        int secondSmallest = dummyObject.findSecondSmallest();

        System.out.println("Original Array: " + java.util.Arrays.toString(numberArray));
        System.out.println("Second Largest Number: " + secondLargest);
        System.out.println("Second Smallest Number: " + secondSmallest);
    }
}
