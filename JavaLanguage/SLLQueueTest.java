package Labs;

public class SLLQueueTest {
    public static void main(String[] args) {
        SLLQueue<Integer> queue = new SLLQueue<Integer>();
        System.out.println("Is the queue empty? " + queue.isEmpty());
        System.out.println("Current size of the queue: " + queue.size());
        queue.enqueue(1);
        System.out.println("Is the queue empty after adding an element? " + queue.isEmpty());
        System.out.println("Current size of the queue after adding an element: " + queue.size());
        System.out.println("Front element of the queue: " + queue.front());
        System.out.println("Rear element of the queue: " + queue.rear());
        queue.enqueue(2);
        System.out.println("Front element after adding 2: " + queue.front());
        System.out.println("Rear element after adding 2: " + queue.rear());
        queue.enqueue(3);
        System.out.println("Front element after adding 3: " + queue.front());
        System.out.println("Rear element after adding 3: " + queue.rear());
        queue.enqueue(4);
        queue.enqueue(5);
        System.out.println("Front element after adding 4 and 5: " + queue.front());
        System.out.println("Rear element after adding 4 and 5: " + queue.rear());

        System.out.println("\nEmpty the queue and printing all values in their order added:");
        while (!queue.isEmpty()) {
            System.out.println(queue.dequeue());
        }
    }
}
