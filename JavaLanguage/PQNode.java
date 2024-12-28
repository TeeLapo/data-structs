package Labs;

public class PQNode extends Node {
    private int priority;

    public PQNode(int data, int priority) {
        super(data);
        this.priority = priority;
    }

    public int getPriority() {
        return priority;
    }

    public void setPriority(int priority) {
        this.priority = priority;
    }

}
