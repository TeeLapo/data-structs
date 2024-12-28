package Labs;
import java.util.Scanner;

public class SLLQueueMergeSort {
    
    // Merge two sorted queues into a new queue that is passed as a parameter
    public static void mergeSorted(SLLQueue<Integer> queueA, SLLQueue<Integer> queueB, SLLQueue<Integer> mergedQueue) {
        while (!queueA.isEmpty() && !queueB.isEmpty()) {
            if (queueA.front() < queueB.front()) {
                mergedQueue.enqueue(queueA.dequeue());
            } else {
                mergedQueue.enqueue(queueB.dequeue());
            }
        }
        
        // Only dequeue from queueA if it's not empty
        while (!queueA.isEmpty()) {
            mergedQueue.enqueue(queueA.dequeue());
        }
        
        // Only dequeue from queueB if it's not empty
        while (!queueB.isEmpty()) {
            mergedQueue.enqueue(queueB.dequeue());
        }
    }

    // Merge two sorted queues into a new queue that is created in the method
    public static SLLQueue<Integer> mergeSorted(SLLQueue<Integer> queueA, SLLQueue<Integer> queueB) {
        SLLQueue<Integer> mergedQueue = new SLLQueue<Integer>(); // Create mergedQueue here
        while (!queueA.isEmpty() && !queueB.isEmpty()) {
            if (queueA.front() < queueB.front()) {
                mergedQueue.enqueue(queueA.dequeue());
            } else {
                mergedQueue.enqueue(queueB.dequeue());
            }
        }
        
        // Only dequeue from queueA if it's not empty
        while (!queueA.isEmpty()) {
            mergedQueue.enqueue(queueA.dequeue());
        }
        
        // Only dequeue from queueB if it's not empty
        while (!queueB.isEmpty()) {
            mergedQueue.enqueue(queueB.dequeue());
        }
        return mergedQueue;
    }
    public static void main(String[] args) {
        SLLQueue<Integer> queueA = new SLLQueue<Integer>();
        SLLQueue<Integer> queueB = new SLLQueue<Integer>();
        SLLQueue<Integer> mergedQueue = new SLLQueue<Integer>();
        
        Scanner scanner = new Scanner(System.in);
        String input = "";
        while(!input.equals("x")){
            System.out.println("Submit each number in the first sorted list and enter x when all the numbers have been inputted:");
            input = scanner.nextLine();
            if(!input.equals("x")){
                queueA.enqueue(Integer.parseInt(input));
            }
        }

        do {
            System.out.println("Submit each number in the second sorted list and enter x when all the numbers have been inputted:");
            input = scanner.nextLine();
            if(!input.equals("x")){
                queueB.enqueue(Integer.parseInt(input));
            }
        }
        while(!input.equals("x"));

        scanner.close();

        mergeSorted(queueA, queueB, mergedQueue);

        System.out.println("The first queue is empty: " + queueA.isEmpty());
        System.out.println("The second queue is empty: " + queueB.isEmpty());

        System.out.println("The merged sorted list is:");
        while (!mergedQueue.isEmpty()){
            System.out.println(mergedQueue.dequeue());
        }
    }
}
