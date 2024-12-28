package Labs;

public class LinkedListStack<T> implements StackInterface<T> {
    private SLinkedList<T> data;

    public LinkedListStack() {
        data = new SLinkedList<T>();
    }

    @Override
    public boolean isEmpty() {
        return data.isEmpty();
    }

    @Override
    public void push(T newItem) {
        data.addFirst(newItem);
    }

    @Override
    public T pop() {
        if (data.isEmpty()) {
            throw new IllegalStateException("Stack is empty");
        }
        Node<T> firstNode = data.getFirst();
        data.removeFirst();
        return firstNode.getData();
    }

    @Override
    public T top() {
        if (data.isEmpty()) {
            throw new IllegalStateException("Stack is empty");
        }
        return data.getFirst().getData();
    }

    @Override
    public int size() {
        return data.size();
    }
}