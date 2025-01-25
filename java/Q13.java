public class Q13 {

    private int[] numbers;

    public Q13(int[] numbers) {
        this.numbers = numbers;
    }

    public void sortArray() {
        int n = numbers.length;

        for (int i = 0; i < n - 1; i++) {
            for (int j = 0; j < n - i - 1; j++) {
                if (numbers[j] > numbers[j + 1]) {
                    int temp = numbers[j];
                    numbers[j] = numbers[j + 1];
                    numbers[j + 1] = temp;
                }
            }
        }
    }

    public int searchSortedArray(int target) {
        sortArray();

        int low = 0;
        int high = numbers.length - 1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (numbers[mid] == target) {
                return mid; 
            } else if (numbers[mid] < target) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return -1; 
    }

    public static void main(String[] args) {
        int[] numberArray = {5, 2, 8, 1, 7, 3, 6, 4};
        int target = 6;

        Q13 sampleObject = new Q13(numberArray);

        sampleObject.sortArray();
        System.out.println("Sorted Array: " + java.util.Arrays.toString(numberArray));

        int searchResult = sampleObject.searchSortedArray(target);

        if (searchResult >= 0) {
            System.out.println("Element " + target + " found at index " + searchResult);
        } else {
            System.out.println("Element " + target + " not found in the array.");
        }
    }
}
