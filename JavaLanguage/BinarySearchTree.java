package Labs;

public class BinarySearchTree<T> {

    KeyedNode<T> root;

    public BinarySearchTree(){
        root = null;
    }

    public BinarySearchTree(KeyedNode<T> root){
        this.root = root;
    }

    public void insert(KeyedNode<T> keyedNode){
        if(root == null){
            root = keyedNode;
        } else {
            insert(root, keyedNode);
        }
    }

    public void insert(KeyedNode<T> root, KeyedNode<T> keyedNode){
        if (root == null){
            root = keyedNode;
        } 
        else {
            if(keyedNode.getKey() < root.getKey()){
                if(root.getLeft() == null){
                    root.setLeft(keyedNode);
                } else {
                    insert(root.getLeft(), keyedNode);
                }
            } else {
                if(root.getRight() == null){
                    root.setRight(keyedNode);
                } else {
                    insert(root.getRight(), keyedNode);
                }
            }
        }
    }

    public void insert(T data, int key){
        KeyedNode<T> keyedNode = new KeyedNode<T>(data, key);
        insert(keyedNode);
    }

    public KeyedNode<T> findMin(KeyedNode<T> root){
        if(root == null){
            return null;
        } 
        else {
            if(root.getLeft() == null){
                return root;
            } else {
                return findMin(root.getLeft());
            }
        }
    }

    public KeyedNode<T> remove(KeyedNode<T> root, int key){
        if(root == null){
            return null;
        }
        if(key < root.getKey()){
            root.setLeft(remove(root.getLeft(), key));
        } else if(key > root.getKey()){
            root.setRight(remove(root.getRight(), key));
        } else {
            if(root.getLeft() == null && root.getRight() == null){ // Case where the node to remove is a leaf node
                return null;
            } else if(root.getLeft() == null){ // Case where the node to remove only has a right child
                return root.getRight();
            } else if(root.getRight() == null){ // Case where the node to remove only has a left child
                return root.getLeft();
            } else {
                // Case where the node to remove has two children
                KeyedNode<T> minNode = findMin(root.getRight());
                root.setKey(minNode.getKey());
                root.setData(minNode.getData());
                root.setRight(remove(root.getRight(), minNode.getKey()));
            }
        }
        return root;
    }

    public void remove(int key){
        root = remove(root, key);
    }

    public KeyedNode<T> search(KeyedNode<T> root, int key){
        if(root == null){
            return null;
        } else {
            if(key == root.getKey()){
                return root;
            } else {
                if(key < root.getKey()){
                    return search(root.getLeft(), key);
                } else {
                    return search(root.getRight(), key);
                }
            }
        }
    }

    /**
     * Passes the root of the tree and the key to search for to the recursive search function
     * @param key
     * @return the node with the key or null if the key is not found
     */
    public KeyedNode<T> search(int key){ 
        return search(root, key);
    }

    public void inOrderTraversal(KeyedNode<T> root){
        if(root != null){
            inOrderTraversal(root.getLeft());
            System.out.print(root.getKey() + " "); // System.out.println(root.getData() + " " + root.getKey());
            inOrderTraversal(root.getRight());
        }
    }

    /**
     * 
     * Function to draw the in order traversal of the tree which requires keeping track of the depth of the node to determine the height of the tree
     * @param root the root of the tree and subsequent subtrees
     * @param depth used in the recursive calls to keep track of the depth of the node
     */
    public void drawInOrderTraversal(KeyedNode<T> root, int depth){
        if(root != null){
            drawInOrderTraversal(root.getLeft(), depth + 1);
            for(int i = 0; i < depth; i++){
                System.out.print("    ");
            }
            System.out.println(root.getKey()); // System.out.println(root.getData() + " " + root.getKey());

            drawInOrderTraversal(root.getRight(), depth + 1);
        }        
    }

    public static void main(String[] args) {
        
        BinarySearchTree<String> bst = new BinarySearchTree<>();
        bst.insert("hello", 1);
        bst.insert("", 2);
        bst.insert("", 3);
        bst.insert("", 4);
        bst.insert("bonjour", 5);
        bst.insert("", 6);
        bst.insert("", 7);
        bst.insert("", 8);
        bst.insert("", 9);
        bst.insert("", 10);
        bst.insert("", 11);
        bst.insert("", 12);
        bst.insert("", 13);
        bst.insert("", 14);
        bst.insert("", 15);

        bst.drawInOrderTraversal(bst.root,0);

        long sum = 0;
        long sum0 = 0;
        long sum1 = 0;
        long sum2 = 0;


        for (int i = 0; i < 100000; i++) {
            long startTime = System.nanoTime();
            bst.search(1);
            long endTime = System.nanoTime();
            long duration = (endTime - startTime);
            sum += duration;
            //System.out.print("Search 1: Time taken: " + duration + " nanoseconds\t\t");
            
            startTime = System.nanoTime();
            bst.search(15);
            endTime = System.nanoTime();
            duration = (endTime - startTime);
            sum0 += duration;
            //System.out.println("Search 15: Time taken: " + duration + " nanoseconds");
        }

        bst.remove(5);
        System.out.println("\nAfter removing 5:");
        bst.inOrderTraversal(bst.root);
        bst.remove(15);
        System.out.println("\nAfter removing 15:");
        bst.inOrderTraversal(bst.root);
        bst.remove(1);
        System.out.println("\nAfter removing 1:");
        bst.inOrderTraversal(bst.root);
        bst.insert("", 2);
        System.out.println("\nAfter inserting 2:");
        bst.inOrderTraversal(bst.root);

        BinarySearchTree<String> bst2 = new BinarySearchTree<>();
        bst2.insert("", 8);
        bst2.insert("", 4);
        bst2.insert("", 12);
        bst2.insert("", 2);
        bst2.insert("", 6);
        bst2.insert("", 10);
        bst2.insert("", 14);
        bst2.insert("", 1);
        bst2.insert("", 3);
        bst2.insert("", 5);
        bst2.insert("", 7);
        bst2.insert("", 9);
        bst2.insert("", 11);
        bst2.insert("", 13);
        bst2.insert("", 15);

        bst2.inOrderTraversal(bst2.root);

        for (int i = 0; i < 100000; i++) {
            long startTime = System.nanoTime();
            bst2.search(1);
            long endTime = System.nanoTime();
            long duration = (endTime - startTime);
            sum1 += duration;
            //System.out.print("Search 1: Time taken: " + duration + " nanoseconds\t\t");
            
            startTime = System.nanoTime();
            bst2.search(15);
            endTime = System.nanoTime();
            duration = (endTime - startTime);
            sum2 += duration;
            //System.out.println("Search 15: Time taken: " + duration + " nanoseconds");
        }

        long average = sum / 100000;
        long average0 = sum0 / 100000;
        long average1 = sum1 / 100000;
        long average2 = sum2 / 100000;

        System.out.println("\nAverage time taken to search for 1 in the first tree: " + average + " nanoseconds");
        System.out.println("Average time taken to search for 15 in the first tree: " + average0 + " nanoseconds");
        System.out.println("Average time taken to search for 1 in the second tree: " + average1 + " nanoseconds");
        System.out.println("Average time taken to search for 15 in the second tree: " + average2 + " nanoseconds");

        bst2.remove(8);
        System.out.println("\nAfter removing 8:");
        bst2.inOrderTraversal(bst2.root);
    }
}
