package Labs;

public class SLLQueue<T> implements SLLQueueInterface<T> {
    private SLinkedList<T> data;
    private Node<T> front;
    private Node<T> rear;
    private int size;

    public SLLQueue() {
        data = new SLinkedList<T>();
        front = null;
        rear = null;
        size = 0;
    }

    @Override
    public boolean isEmpty() {
        return front == null;
    }

    @Override
    public int size() {
        return data.size();
    }

    @Override
    public T front() {
        if (isEmpty()) {
            throw new IllegalStateException("Queue is empty");
        }
        return data.getFirst().getData();
    }

    @Override
    public T rear() {
        if (isEmpty()) {
            throw new IllegalStateException("Queue is empty");
        }
        return rear.getData();
    }

    @Override
    public void enqueue(T newItem) {
        Node<T> newNode = new Node<T>(newItem);
        data.addLast(newNode);
        if (isEmpty()) { // If the queue was empty
            front = newNode; // Set front to the new node
        }
        rear = newNode; // Always update rear to the new node
        size++;
    }
    
    @Override
    public T dequeue() {
        if (isEmpty()) {
            throw new IllegalStateException("Queue is empty");
        }
        T dequeuedData = front.getData();
        data.removeFirst();
        if(!data.isEmpty()){
            front = data.getFirst();
        }
        else{
            front = null;
            rear = null;
        }
        size--;
        return dequeuedData;
    }

    @Override
    public void fillQueue(T[] arr) {
        for (T item : arr) {
            enqueue(item);
        }
    }

    @Override
    public void emptyQueue() {
        while (!isEmpty()) {
            dequeue();
        }
    }
}