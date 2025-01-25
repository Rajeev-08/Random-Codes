// Q9
abstract class Dummy {
    protected int[] dataArray;

    public Dummy(int[] dataArray) {
        this.dataArray = dataArray;
    }

    abstract int search(int target);
}

// Subclass LinearSearch implementing linear search
class LinearSearch extends Dummy {

    public LinearSearch(int[] dataArray) {
        super(dataArray);
    }

    @Override
    int search(int target) {
        for (int i = 0; i < dataArray.length; i++) {
            if (dataArray[i] == target) {
                return i; // Return the index if the target is found
            }
        }
        return -1; // Return -1 if the target is not found
    }
}

// Subclass BinarySearch implementing binary search
class BinarySearch extends Dummy {

    public BinarySearch(int[] dataArray) {
        super(dataArray);
    }

    @Override
    int search(int target) {
        int low = 0;
        int high = dataArray.length - 1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (dataArray[mid] == target) {
                return mid; // Return the index if the target is found
            } else if (dataArray[mid] < target) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return -1; // Return -1 if the target is not found
    }
}

public class Search{
    public static void main(String[] args) {
        int[] dataArray = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

        // Using LinearSearch
        Dummy linearSearchObject = new LinearSearch(dataArray);
        int linearSearchResult = linearSearchObject.search(6);
        System.out.println("Linear Search Result: " + linearSearchResult);

        // Using BinarySearch
        Dummy binarySearchObject = new BinarySearch(dataArray);
        int binarySearchResult = binarySearchObject.search(6);
        System.out.println("Binary Search Result: " + binarySearchResult);
    }
}
