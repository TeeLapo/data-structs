package Labs;

public class SLinkedList<T> {
    private Node<T> head;
    private Node<T> tail;
    private int size;

    public SLinkedList() {
        head = null;
        tail = null;
        size = 0;
    }

    public Node<T> getFirst(){
        if (isEmpty()){
            throw new IllegalStateException("There are no nodes in the list");
        }
        return head;
    }

    public Node<T> getLast(){
        if (isEmpty()){
            throw new IllegalStateException("There are no nodes in the list");
        }
        return tail;
    }

    public boolean isEmpty(){
        return head == null;
    }

    public int size(){
        if (isEmpty())
            return 0;
        int count = 1;
        Node<T> currentNode = head;
        while (currentNode.getNext() != null){ 
            count++;
            currentNode = currentNode.getNext();
        }
        return count;
    }

    public void addFirst(T data) {
        Node<T> newNode = new Node<T>(data);
        if (isEmpty()){
            head = newNode;
            tail = newNode;
            size++;
        }
        else{
            newNode.setNext(head);
            head = newNode;
            size++;
        }
    }

    public void removeFirst() {
        if (isEmpty()){
            throw new IllegalStateException("There are no nodes to remove");
        }
        if (head.getNext() != null)
            head = head.getNext();
        else
            head = null;
        size--;
    }

    public void addLast(Node<T> node){
        if (isEmpty()) {
            head = node;
            tail = node;
            size++;
            return;
        }
        Node<T> currentNode = head;
        while (currentNode.getNext() != null){
            currentNode = currentNode.getNext();
        }
        currentNode.setNext(node);
        size++;
    }

    public void removeLast(){
        if (isEmpty()) {
            throw new IllegalStateException("There are no nodes to remove");
        }
        if (head == tail) {
            head = null;
            tail = null;
            return;
        }
        Node<T> currentNode = head;
        Node<T> prevNode = null;
        while (currentNode.getNext() != null){
            prevNode = currentNode;
            currentNode = currentNode.getNext();
        }
        prevNode.setNext(null);
        tail = prevNode;
        size--;
    }
}