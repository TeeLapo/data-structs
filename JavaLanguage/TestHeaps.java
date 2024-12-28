package Labs;

public class TestHeaps {
    public static void main(String[] args) {
        System.out.println("Array Size\tMinHeap Time (ns)\tMaxHeap Time (ns)");
        System.out.println("-------------------------------------------------");
        
        // Test array sizes from 2^3 to 2^20
        for (int power = 3; power <= 20; power++) {
            int size = (int) Math.pow(2, power);
            
            // Generate random arrays
            int[] unsortedArray1 = new int[size];
            int[] unsortedArray2 = new int[size];
            for (int i = 0; i < size; i++) {
                int randomNum = (int) (Math.random());
                unsortedArray1[i] = randomNum;
                unsortedArray2[i] = randomNum;
            }
            
            // Test MinHeap
            MinHeap minHeap = new MinHeap(size);
            long startTime = System.nanoTime();
            minHeap.heapSort(unsortedArray1);
            long minHeapTime = System.nanoTime() - startTime;
            
            // Test MaxHeap
            MaxHeap maxHeap = new MaxHeap(size);
            startTime = System.nanoTime();
            maxHeap.heapSort(unsortedArray2);
            long maxHeapTime = System.nanoTime() - startTime;
            
            // Print results
            System.out.printf("2^%-9d\t%-15d\t%-15d%n", power, minHeapTime, maxHeapTime);
        }
    }
}
