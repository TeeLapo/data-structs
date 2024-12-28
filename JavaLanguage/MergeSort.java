package Labs; // Declare the package for this class

public class MergeSort<T> { // Define the MergeSort class with a generic type T

    // Method to perform merge sort on a queue of integers
    public static SLLQueue<Integer> mergeSort(SLLQueue<Integer> queue) {

        // Base case: if the queue is empty or has only one element, it is already sorted
        if (queue.isEmpty() || queue.size() == 1) {
            return queue; // Return the queue as it is
        }

        // Create two new queues to hold the left and right halves of the original queue
        SLLQueue<Integer> left = new SLLQueue<Integer>();
        SLLQueue<Integer> right = new SLLQueue<Integer>();
        
        // Calculate the midpoint of the queue
        int mid = queue.size() / 2;

        // Dequeue elements for the left queue
        for (int i = 0; i < mid; i++) {
            left.enqueue(queue.dequeue()); // Dequeue from the original queue and enqueue to left
        }

        // Dequeue the remaining elements for the right queue
        while (!queue.isEmpty()) {
            right.enqueue(queue.dequeue()); // Dequeue from the original queue and enqueue to right
        }

        // Recursively sort the left and right queues
        left = mergeSort(left); // Sort the left half
        right = mergeSort(right); // Sort the right half

        // Merge the two sorted halves back into the original queue
        SLLQueueMergeSort.mergeSorted(left, right, queue); // Merge left and right into queue

        // Return the sorted queue
        return queue; // The original queue now contains the sorted elements
    }
    
    // Main method to test the mergeSort function
    public static void main(String[] args) {
        // Create a new queue to hold integers
        SLLQueue<Integer> queue = new SLLQueue<Integer>();
        
        // Enqueue unsorted integers into the queue
        queue.enqueue(5);
        queue.enqueue(3);
        queue.enqueue(8);
        queue.enqueue(4);
        queue.enqueue(2);
        queue.enqueue(7);
        queue.enqueue(1);
        queue.enqueue(10);
        queue.enqueue(6);
        queue.enqueue(9);
        
        // Call the mergeSort method to sort the queue
        SLLQueue<Integer> sortedQueue = mergeSort(queue);
        
        // Dequeue and print each element of the sorted queue
        while (!sortedQueue.isEmpty()) {
            System.out.print(sortedQueue.dequeue() + " "); // Print each sorted element
        }
    }
}

// Merge Sort is a divide and conquer algorithm with time complexity of O(n log n) in the worst case, average case, and best case as the problem set is divided in half with each recursive call in all scenarios of the initial array order.