#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int length;
    printf("Enter the length of the array: ");
    scanf("%d", &length);
    int array[length];
    for (int i = 0; i < length; i++) {
        array[i] = (rand() % 2001) - 1000;// Generate a random number between -1000 and 1000
    }
    printf("Array before sorting: ");
    for (int i = 0; i < length; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
    clock_t start, end;//Create variables of type clock_t
    double timeTaken;//Create a variable to store the time taken

    start = clock();// Set start to the current time (processor time in clock ticks)

    //Employ bubble sort method to sort the array

    // Outer loop to iterate through each element of the array. Since the last element will be sorted after the first iteration, the loop runs length-1 times
    for (int i = 0; i < length-1; i++) {
        // Inner loop to compare adjacent elements and swap them if necessary. First iteration will move the highest element to the end of the array
        for (int j = 0; j < length - i - 1; j++) {
            // Check if the current element is greater than the next element
            if (array[j] > array[j + 1]){
                // Swap the elements using a temporary variable
                int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }

    end = clock();// Set end to the current time (processor time in clock ticks)

// Calculate the time taken in seconds converting from clock ticks w/ constant CLOCK_PER_SEC
// When the precision is such that the time taken is less than or equal to 0.000010, the time taken is converted to milliseconds
    int flag;

    if(((double)(end-start)) / CLOCKS_PER_SEC <= 0.000010){
        timeTaken = ((double)(end - start)) / CLOCKS_PER_SEC*1000;
        flag = 0;// milliseconds are needed to represent value
    }
    else{
    timeTaken = ((double)(end - start)) / CLOCKS_PER_SEC;
        flag = 1;// seconds are adequate to represent value
    }
    printf("Array after sorting: ");
    for (int i = 0; i < length; i++) {
        printf("%d ", array[i]);// print each element of the array
    }
    printf("\n");
    if (flag){
        printf("The array was sorted in %f seconds\n", timeTaken);
    }
    else{
        printf("The array was sorted in %f milliseconds\n", timeTaken);

    }
    return 0;
}