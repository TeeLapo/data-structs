package Labs;

public class MinHeap {
    private int[] heap;
    private int size;
    private int arrayCapacity;

    public MinHeap(int arrayCapacity){
        this.arrayCapacity = arrayCapacity;
        heap = new int[arrayCapacity];
        size = 0;
    }

    public boolean isEmpty(){
        return size == 0;
    }

    public boolean isFull(){
        return size == arrayCapacity;
    }

    public void setHeap(int[] heap){
        this.heap = heap;
    }

    public void setSize(int size){
        this.size = size;
    }

    public void setArrayCapacity(int arrayCapacity){
        this.arrayCapacity = arrayCapacity;
    }

    public void swap(int index1, int index2){
        int temp = heap[index1];
        heap[index1] = heap[index2];
        heap[index2] = temp;
    }

    /**
     * Builds a min heap from an unsorted array.
     * @param unsortedArray the unsorted array to build the min heap from
     * @return
     * Complexity: O(n) where n is the number of elements in the unsorted array
     */
    public void buildMinHeap(int[] unsortedArray){
        setHeap(unsortedArray);
        setSize(unsortedArray.length);
        setArrayCapacity(unsortedArray.length);

        // Start from the last non-leaf node and heapify down moving up the tree to the root
        for(int i = size / 2 - 1; i >= 0; i--){
            heapifyDown(i);
        }
    }

    /**
     * Sorts an unsorted array in ascending order using the heap sort algorithm.
     * @param unsortedArray the unsorted array to sort
     * @return
     * Complexity: O(nlogn) where n is the number of elements in the unsorted array
     */
    public void heapSort(int[] unsortedArray) {
        buildMinHeap(unsortedArray); // Build the min heap from the unsorted array

        // Start from the first element and swap it with the last element then heapify down
        for (int i = 0; i < unsortedArray.length; i++) {
            swap(0, size - 1); // Move current root (minimum) to the end
            size--; // Reduce the size of the heap
            heapifyDown(0); // Restore the min-heap property
        }
        
        // Reset size to the original length
        size = unsortedArray.length;
    }

    /**
     * Ensures that the properties of the min heap are maintained after an element is inserted or removed.
     * Base case: If the index is 0, then the element is at the root of the heap and there is nothing to compare it to.
     * Recursive case: If the element is greater than its parent, swap the element with its parent and recursively call heapifyUp on the parent.   
     * @param i location of the element to heapify up starting from the root
     * Complexity: O(logn) where n is the number of elements in the heap
     */

     public void heapifyUp(int i){
         int parent = (i - 1) / 2;
         if (i == 0){
             return;
         }
         if(heap[i] < heap[parent]){
             swap(i, parent);

             heapifyUp(parent);
         }
     }

     /**
      * Ensures that the properties of the min heap are maintained after an element is inserted or removed.
      * Base case: If the index is greater than or equal to the size of the heap, then the element is a leaf node and there is nothing to compare it to.
      * Recursive case: If the element is smaller than its children, swap the element with the smallest child and recursively call heapifyDown on the child.
      * @param i location of the element to heapify down starting from the root  
      * Complexity: O(logn) where n is the number of elements in the heap
      */
    public void heapifyDown(int i){
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        int smallest = i;

        if(left < size && heap[left] < heap[smallest]){
            smallest = left;
        }

        if(right < size && heap[right] < heap[smallest]){
            smallest = right;
        }

        if(smallest != i){
            swap(i, smallest);

            heapifyDown(smallest);
        }
    }
   
    /**
     * Inserts an element into the heap and ensures that the properties of the min heap are maintained.
     * @param value the element to insert into the heap
     * Complexity: O(logn) where n is the number of elements in the heap
     */
    public void insert(int value){
        if(isFull()){
            throw new IndexOutOfBoundsException("Heap is full");
        }

        heap[size] = value;

        heapifyUp(size);
        size++;
    }

    /**
     * Removes the minimum element from the heap and ensures that the properties of the min heap are maintained.
     * Complexity: O(logn) where n is the number of elements in the heap
     */
    public void removeMin(){
        if(isEmpty()){
            throw new IndexOutOfBoundsException("Heap is empty");
        }

        heap[0] = heap[size - 1];
        size--;

        heapifyDown(0);
    }

    /**
     * Returns the minimum element in the min heap.
     * @return the minimum element in the min heap
     */
    public int min(){
        if(isEmpty()){
            throw new IndexOutOfBoundsException("Heap is empty");
        }

        return heap[0];
    }

    public int getSize(){
        return size;
    }

    public void printHeap(){
        for(int i = 0; i < size; i++){
            System.out.print(heap[i] + " ");
        }
        System.out.println();
    }
}
