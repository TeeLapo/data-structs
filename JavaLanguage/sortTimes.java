package Labs;
import java.util.Arrays;

public class sortTimes {

    public static void SortTimeComparison(int[] arr, int runTimes) {

        long MergeSortTime = 0;
        long QuickSortTime = 0;
        long InsertionSortTime = 0;
        
        int[] arrCopy = Arrays.copyOf(arr, arr.length); //used to ensure all sorting algorithms are sorting the same array
        
        // Convert int[] to Integer[]
        Integer[] integerArray = Arrays.stream(arr).boxed().toArray(Integer[]::new);
        SLLQueue<Integer> queueFromArray = new SLLQueue<Integer>();
        
        for (int i = 1; i <= runTimes; i++) {
            queueFromArray.fillQueue(integerArray);
            long startTime = System.nanoTime();
            // This sorting algorithm is via the SLLQueue class so the array is not modified
            MergeSort.mergeSort(queueFromArray);
            long endTime = System.nanoTime();
            long duration = (endTime - startTime);
            MergeSortTime = duration;
            queueFromArray.emptyQueue();

            startTime = System.nanoTime();
            QuickSort.quickSort(arr, 0, arr.length - 1);
            endTime = System.nanoTime();
            duration = (endTime - startTime);
            QuickSortTime = duration;

            // arr is modified by the insertion sort algorithm so we use the copy
            startTime = System.nanoTime();
            InsertionSort.insertionSort(arrCopy);
            endTime = System.nanoTime();
            duration = (endTime - startTime);
            InsertionSortTime = duration;

            
            System.out.print("Mergesort " + i + ": " + MergeSortTime + " nanoseconds, ");
            System.out.print("Quicksort " + i + ": " + QuickSortTime + " nanoseconds, ");
            System.out.println("Insertion sort " + i + ": " + InsertionSortTime + " nanoseconds ");
        }
    
    }
    
    public static int[] createRandomArray(int n) {
        int[] arr = new int[n];
        for (int i = 0; i < n; i++) {
            arr[i] = (int) (Math.random());
        }
        return arr;
    }
    public static void main(String[] args) {

    
        int[] arr = createRandomArray(64);
        SortTimeComparison(arr, 5);
    }

}
