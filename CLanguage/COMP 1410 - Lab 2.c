#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void printArray(int array[], int arraySize) {
    for (int i = 0; i < arraySize; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

void print2DArray(int array2D[10][5]) {
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 5; j++) {
            printf("%d ", array2D[i][j]);
        }
        printf("\n");
    }
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void ptpSwap(int **a, int **b) {
    int temp = **a;
    **a = **b;
    **b = temp;
}

void swapRows(int array2D[10][5], int row1, int row2) {
    for (int j = 0; j < 5; j++) {
        swap(&array2D[row1][j], &array2D[row2][j]);
    }
}

void BubbleSort(int *array[], int arraySize) {
    for (int i = 0; i < arraySize - 1; i++) {
        for (int j = 0; j < arraySize - i - 1; j++) {
            if (*array[j] > *array[j + 1]) {
                ptpSwap(&array[j], &array[j + 1]);
            }
        }
    }
}

void arrayBubbleSort(int array[], int arraySize) {
    for (int i = 0; i < arraySize - 1; i++) {
        for (int j = 0; j < arraySize - i - 1; j++) {
            if (array[j] > array[j + 1]) {
                swap(&array[j], &array[j + 1]);
            }
        }
    }
}


//time complexity of quicksort is O(n^2)

void quicksort(int array[], int first, int last) {//array = {2, 3, 9, 5, 8, 7, 4}, first = 0, last = 6
    int stack[last - first + 1];
    int top = -1;

    // Push initial values of first and last to the stack
    stack[++top] = first;
    stack[++top] = last;

    while (top >= 0) { //if the stack empty break the loop
        last = stack[top--];
        first = stack[top--];

        int pivot = array[first]; //set the pivot element to the first element of the array
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
            stack[++top] = first;
            stack[++top] = right;
        }
        if (left < last) {//if the left element is smaller than the last element push the left and last element to the stack
            stack[++top] = left;
            stack[++top] = last;
        }
    }
}

//time complexity of MatrixSort is O(n^2) as we have two nested loops

void MatrixSort(int array2D[10][5]) {
    int *p[10];//array of pointers to the minimum value of each row
    for (int i = 0; i < 10; i++) { //for each row
        int rowMin = array2D[i][0]; //set the minimum value of the row to the first element of the row
        p[i] = &array2D[i][0]; //set the pointer to the first element of the row
        for(int j = 0; j < 5; j++) { //for each column
            if (array2D[i][j] < rowMin){ //update rowMin if the element is smaller than the current minimum value of the row
                rowMin = array2D[i][j];
                p[i] = &array2D[i][j];//set the pointer to the minimum value of the row
            }
        }
    }
    BubbleSort(p, 10);//sort the array of pointers
    for (int i = 0; i < 10 - 1; i++) { //for each row
        for (int k = 0; k < 10 -i -1; k++) { //for each row except the last row
            if (*p[k] > *p[k+1]) { // if the minimum value of the row is greater than the minimum value of the next row
                swapRows(array2D, k, k+1); //swap the rows
            }
        }
    }
    printf("\nHelper for Pointer Array of lowest values across rows");
    for (int i = 0; i < 10; i++) {
        printf("%d ", *p[i]);
    }
    printf("\n");
}

//Complexity is O(n^2) because we have two nested loops. The optimal solution is O(nlogn) given that the array is sorted.

int findValuesIn2DArray(int array2D[10][5], int value) {
    int count = 0;
    for (int i = 0; i < 10; i++) {//for each row
        for (int j = 0; j < 5; j++) {//for each column
            if (array2D[i][j] == value) {//check for value
                count++;//increment count if the value is found
            }
        }
    }
    return count;
}

binarySearch(int array[], int arraySize, int value) {
    int low = 0;
    int high = arraySize - 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (array[mid] == value) {
            return mid;
        }
        if (array[mid] < value) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }
    return -1;
}

//Complexity is O(nlogn) as we have a loop of n and a binary search of logn.

int findValuesInSorted2DArray(int array2D[10][5], int value) {
    int count = 0;
    for (int i = 0; i < 10; i++) { // for each row
        if (binarySearch(array2D[i], 5, value) != -1) {
            count++;
        }
    }
    return count;
}

int main() {

    int array[30];
    srand(time(NULL));

    for(int i = 0; i < 30; i++) {
        array[i] = rand() % 1001;
    }

    quicksort(array, 0, 29);
    printf("Sorted array: \n");
    printArray(array, 30);

    int array2D[10][5]; 
    
    for(int i=0; i<10; i++){
        for(int j=0; j<5; j++){
            array2D[i][j] = rand() % 101;
        }
    }

    printf("\nUnsorted 2D array: \n");
    print2DArray(array2D);
    MatrixSort(array2D);
    printf("\nSorted 2D array: \n");
    print2DArray(array2D);

    for (int i = 0; i < 10; i++){
        arrayBubbleSort(array2D[i], 5);
    }

    printf("\n2D Sorted Columns and Sorted Rows\n");
    print2DArray(array2D);

    printf("\nFound value in %d rows\n", findValuesInSorted2DArray(array2D, 4));

    return 0;

/*
Part C

(a) O(1) //= O(12)*O(12)*O(1)
    for(int j = 0; j < 12; j++)                                         //time complexity is O(12) = O(1)
        for(int k = 0; k < 12; k++)                                     //time complexity is O(12) = O(1)
            print(“*”);                                                 //time complexity is O(1)

(b) O(N) //= O(1000)*O(N)*O(1)
    for(int j = 0; j < 1000; j++)                                       //time complexity is O(1000) = O(N)
        for(int k = 0; k < N; k++)                                      //time complexity is O(N)
            print(“*”);                                                 //time complexity is O(1)

(c)O(N^3) //= O(N^2)*O(N)*O(1)
    for(int j = 0; j < N; j++)                                          //time complexity is O(N)
        for(int k = 0; k < N*N; k++)                                    //time complexity is O(N^2)
            print(“*”);                                                 //time complexity is O(1)

(d) O(log^2 n) //= O(log n)*O(log n)*O(1)
    for(int j = 0; j < N; j /= 2){                                      //time complexity is O(log n)
        print(“*”);                                                     //time complexity is O(1)
        for(int k = 0; k < N; k /= 2)                                   //time complexity is O(log n)
            print(“*”);                                                 //time complexity is O(1)
    }

(e) O(N) //=
    for(int j = 0; j < N; j++)                                          //time complexity is O(N)
        for(int k = j; k < j+7; k++)                                    //time complexity is O(7) = O(1)
            print(“*”);                                                 //time complexity is O(1)

(f) //For F/G/H, determine recursive form and use table to convert it
    void print_star(int k){ //requires k>=0
        if(k == 0) return;                                              //time complexity is O(1)
            print(“*”);                                                 //time complexity is O(1)
        print_star(k-1);                                                //time complexity is O(k)
return;
}

//time complexity of the recursive function is O(k)

(g)
void print_star(int k, int N){ //requires k<=N
if(k == N) return;                                                      //time complexity is O(1)
for(int j = 0; j < N; j++)                                              //time complexity is O(N)
print(“*”);                                                             //time complexity is O(1)
print_star(k+1);                                                        //time complexity is O(k)
return;
}

//time complexity of the recursive function is O(nlogn)

(h)
void print_star(int k, int N){ //requires k<=N
if(k >= N) return;                                                      //time complexity is O(1)
for(int j = 0; j < N*2; j++)                                            //time complexity is O(N)
print(“*”);                                                             //time complexity is O(1)
print_star(k*2);                                                        //time complexity is O(k)
return;
}

//time complexity of the recursive function is O(nlogn)

*/

}

