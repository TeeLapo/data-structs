package Labs;
public class Stack<T> implements StackInterface<T> {
    private T[] data;
    private int top;

    @SuppressWarnings("unchecked")
    public Stack(int capacity) {
        data = (T[]) new Object[capacity]; //Creating a generic array
        top = -1;
    }

    public boolean isEmpty() {
        return top == -1;
    }

    @Override
    public void push(T newItem) {
        if (top == data.length - 1) {
            throw new IllegalStateException("Stack is full");
        }
        data[++top] = newItem;
    }

    @Override
    public T pop() {
        if (isEmpty()) {
            throw new IllegalStateException("Stack is empty");
        }
        return data[top--];
    }

    @Override
    public T top() {
        if (isEmpty()) {
            throw new IllegalStateException("Stack is empty");
        }
        return data[top];
    }

    public int size() {
        return top + 1;
    }
}