package Labs;

public interface SLLQueueInterface<T> {
    public void enqueue(T data);
    public T dequeue();
    public T front();
    public T rear();
    public int size();
    public boolean isEmpty();
    public void fillQueue(T[] arr);
    public void emptyQueue();
}
