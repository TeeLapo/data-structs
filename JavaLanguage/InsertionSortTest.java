package Labs;

public class InsertionSortTest {
    public static void main(String[] args) {
        int[] arr = { 12, 11, 13, 5, 6 };
        InsertionSort.insertionSort(arr);
        for (int i = 0; i < arr.length; i++) {
            System.out.print(arr[i] + " ");
        }
    }
}
