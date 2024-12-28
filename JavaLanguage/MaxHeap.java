package Labs;

public class MaxHeap {
    private int[] heap;
    private int size;
    private int arrayCapacity;

    public MaxHeap(int arrayCapacity){
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
     * Builds a max heap from an unsorted array.
     * @param unsortedArray the unsorted array to build the max heap from
     * @return
     */
    public void buildMaxHeap(int[] unsortedArray){
        setHeap(unsortedArray);
        setSize(unsortedArray.length);
        setArrayCapacity(unsortedArray.length);

        // Start from the last non-leaf node and heapify down moving up the tree to the root
        for(int i = size / 2 - 1; i >= 0; i--){
            heapifyDown(i);
        }
    }

    public void heapSort(int[] unsortedArray){
        buildMaxHeap(unsortedArray);

        // Start from the last element and swap it with the first element then heapify down
        for(int i = size - 1; i >= 0; i--){
            swap(0, i); //
            size--;
            heapifyDown(0);
        }       
        size = unsortedArray.length;
    }

    /**
     * Ensures that the properties of the max heap are maintained after an element is inserted or removed.
     * Base case: If the index is 0, then the element is at the root of the heap and there is nothing to compare it to.
     * Recursive case: If the element is less than its parent, swap the element with its parent and recursively call heapifyUp on the parent.   
     * @param i location of the element to heapify up starting from the root
     */

     public void heapifyUp(int i){
         int parent = (i - 1) / 2;
         if (i == 0){
             return;
         }
         if(heap[i] > heap[parent]){
             swap(i, parent);

             heapifyUp(parent);
         }
     }

     /**
      * Ensures that the properties of the max heap are maintained after an element is inserted or removed.
      *Base case: If the index is greater than or equal to the size of the heap, then the element is a leaf node.
      *Recursive case: If the element is smaller than its children, swap with the largest child and recursively call heapifyDown.
      * @param i location of the element to heapify down starting from the root  
      */
    public void heapifyDown(int i){
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        int largest = i;

        if(left < size && heap[left] > heap[largest]){
            largest = left;
        }

        if(right < size && heap[right] > heap[largest]){
            largest = right;
        }

        if(largest != i){
            swap(i, largest);

            heapifyDown(largest);
        }
    }
   
    /**
     * 
     * Inserts an element into the heap and ensures that the properties of the max heap are maintained.
     * @param value the element to insert into the heap
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
     * Removes the maximum element from the heap and ensures that the properties of the max heap are maintained.
     */
    public void removeMax(){
        if(isEmpty()){
            throw new IndexOutOfBoundsException("Heap is empty");
        }

        heap[0] = heap[size - 1];
        size--;

        heapifyDown(0);
    }

    /**
     * Returns the maximum element in the max heap.
     * @return the maximum element in the max heap
     */
    public int max(){
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
