#include <stdio.h>
#include <stdlib.h>
#include "queue.h"
#include <time.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void printArray(int array[], int arraySize) {
    for (int i = 0; i < arraySize; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

void quicksort(int array[], int first, int last){
    queue *q = createQueue();
    add(q, first);
    add(q, last);
    while (!is_empty(q)){
            first = front(q);
            rm(q);
            last = front(q);
            rm(q);

            int pivot = array[first];
            int left = first;
            int right = last;

        while (left <= right) { //loop to find the correct position of the pivot element
            while (array[left] < pivot) { //loop to find the first element greater than pivot
                left++;
            }
            while (array[right] > pivot) { //loop to find the first element smaller than pivot
                right--;
            }
            if (left <= right) {//if the left element is smaller than the right element swap them
                swap(&array[left], &array[right]);
                left++;
                right--;
            }
        }

        if (first < right) {//if the first element is smaller than the right element push the first and right element to the stack
            add(q, first);
            add(q, right);
        }
        if (left < last) {//if the left element is smaller than the last element push the left and last element to the stack
            add(q, left);
            add(q, last);        
            }
    }
    destroy(q);
}

int main() {
    
    int array[30];
    srand(time(NULL));

    for(int i = 0; i < 30; i++) {
        array[i] = rand() % 1001;
    }

    printf("Unsorted array: \n");
    printArray(array, 30);

    quicksort(array, 0, 29);
    printf("Sorted array: \n");
    printArray(array, 30);
    
    return 0;
}
