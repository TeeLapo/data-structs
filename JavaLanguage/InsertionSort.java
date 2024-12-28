package Labs;

public class InsertionSort {
    public static void insertionSort(int[] arr) {
        for (int i = 1; i < arr.length; i++) { // Start from the second element
            int key = arr[i]; // Set key to the current element. The key is akin to picking up a card from the unsorted deck to hold in your hand. Alternative would be to use a swap method to move the element to the correct position, but the disadvantage is that it requires more memory and time.
            int j = i - 1; // Set j to the previous element
            while (j >= 0 && arr[j] > key) { // While j is greater than or equal to 0 and the previous element is greater than the current element
                arr[j + 1] = arr[j]; // Move the previous element to the current element
                j = j - 1; // Decrement j
            }
            arr[j + 1] = key; // Set the current element to the key
        }
    }
}

/*  The best case of insertion sort is O(n) when the array is already sorted as only one comparison is made for each element. ie. the for loop is executed n times and the while loop is executed 0 times.
    The average case of insertion sort is when the array is partially sorted, resulting in a time complexity of O(n^2) as the number of comparisons and shifts increase with the number of inversions.
    The worst case of insertion sort is when the array is sorted in reverse order, resulting in a time complexity of O(n^2) as the maximum number of comparisons and shifts are made for each element. */