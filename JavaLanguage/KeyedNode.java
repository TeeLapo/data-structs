package Labs;

public class KeyedNode<T> {
    private T data;
    private int key;
    private boolean isExternal;
    private KeyedNode<T> left;
    private KeyedNode<T> right;

    public KeyedNode(T data, int key){
        this.data = data;
        this.key = key;
        this.right = null;
        this.left = null;
        this.isExternal = true;
    }

    public T getData(){
        return data;
    }

    public int getKey(){
        return key;
    }

    public KeyedNode<T> getRight(){
        return right;
    }

    public KeyedNode<T> getLeft(){
        return left;
    }

    public void setData(T data){
        this.data = data;
    }

    public void setKey(int key){
        this.key = key;
    }

    public void setRight(KeyedNode<T> right){
        this.right = right;
    }

    public void setLeft(KeyedNode<T> left){
        this.left = left;
    }

}

