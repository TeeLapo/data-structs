package Labs;

public class QuickSort {

    public static void swap(int arr[], int i, int j) {
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }

    public static int partition(int arr[], int left, int right) { // || Example array: {10, 3, 5, 2, 8}
        int pivot = arr[right]; // Choose the last element as pivot || pivot = 8
        for (int currentElement = left; currentElement < right; currentElement++) { // Iterate through the array || currentElement = 0, 1, 2, 3, 4
            if (arr[currentElement] <= pivot) { // If the current element is smaller than the pivot || 10 <= 8 = F, 3 <= 8 = T, 5 <= 8 = T, 2 <= 8 = T, 8 <= 8 = T
                swap(arr, left, currentElement); // Swap current element with arr[left] || {10, 3, 5, 2, 8}, {3, 10, 5, 2, 8}, {3, 5, 10, 2, 8}, {3, 5, 2, 10, 8}
                left++; // Increment left to point to the next position || left = 1, 2, 3, 4
            }
        }
        swap(arr, left, right); // Swap arr[left] with arr[right] (the pivot) || {3, 5, 2, 8, 10}
        return left; // Return the partition index || 1
    }

    public static void quickSort(int arr[], int left, int right) {

        if (left < right) { // Base case: if left is less than right
            int pivot = partition(arr, left, right);
            assert pivot >= left && pivot <= right; // Resultant pivot should be placed in the correct position with all elements to the left being smaller and all elements to the right being larger
            quickSort(arr, left, pivot - 1); // Recursively sort the left partition
            quickSort(arr, pivot + 1, right); // Recursively sort the right partition
        }
    }

    public static void main(String[] args) {
        int arr[] = {5, 3, 8, 4, 2, 7, 1, 10, 6, 9};
        quickSort(arr, 0, arr.length-1);
        for (int i = 0; i < arr.length; i++) {
            System.out.print(arr[i] + " ");
        }
    }
}

/* The Quicksort algorithm is a divide-and-conquer algorithm, however it does not have a consistent time complexity as it depends on the selected pivot. 
   In both the best and average case the partitions are either perfectly or nearly balanced around the pivot, resulting in a time complexity of O(n log n).
   In the worst case the pivot selected is the smallest or largest element in the array, resulting in a time complexity of O(n^2) as the partitions are not balanced. */