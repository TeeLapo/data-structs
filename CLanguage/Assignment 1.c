/*
    Name: COMP 1410 Assignment 1
    Author: Taylor Laporte
    Student Number: 102755730
*/

#include <stdio.h>
#include <assert.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

unsigned long long int recursiveFibonacci(int n){
    if(n == 0){
        return 0;//base case
    }
    if(n == 1){
        return 1;//base case
    }
    return recursiveFibonacci(n-1) + recursiveFibonacci(n-2);//recursive case
}

unsigned long long int fibonacci(unsigned long long int n){
    unsigned long long int nminus2 = 0;
    unsigned long long int nminus1 = 1;
    unsigned long long int temp;
    if(n == 0){
        return 0;
    }
    if(n == 1){
        return 1;
    }
    for(unsigned long long int i = 2; i <= n; i++){
        temp = nminus2 + nminus1;
        nminus2 = nminus1;
        nminus1 = temp;
    }   
    return nminus1;
}

bool recursiveIsPalindrome(char str[], int arraySize){
    if(arraySize <= 1){//base case
        return true;
    }
    if (str[0] == str[arraySize - 1]){
        return recursiveIsPalindrome(str + 1, arraySize - 2);//recursive case
    }
    else{
        return false;
    }
}

bool isPalindrome(char str[], int arraySize){
    for(int i = 0; i < arraySize/2; i++){
        if(str[i] == str[arraySize - 1]){
        }
        else{
            return false;
        }
        return true;
    }
}

//Bubble Sort Functions

int swap(int array[], int i, int j){
    int temp;
    temp = array[i];
    array[i] = array[j];
    array[j] = temp;
}

void randomizeArray(int array[], int arraySize){
        srand(time(NULL) * clock());
    for (int i=0; i<arraySize; i++){
        array[i] = rand() % 1001;
    }
}

void recursiveBubbleSort(int array[], int arraySize){
    int j;
    for(j = 0; j < arraySize; j++){//base case is the inner loop
        if(array[j] > array[j+1]){
            swap(array, j, j+1);
        }   
    }
    if(arraySize > 1){
        recursiveBubbleSort(array, arraySize-1);//recursive case to emulate the outer loop
    }
}

void bubbleSort(int array[], int arraySize){
    for(int i = 0; i < arraySize; i++){
        for(int j = 0; j < arraySize; j++){
            if(array[j] > array[j+1]){
                swap(array, j, j+1);
            }
        }
    }
    return;
}

void isSorted(int array[], int arraySize){
    for(int i = 0; i < arraySize; i++){
        if(array[i] > array[i+1]){
            assert(false);
        }
    }
    return;
}

void printArray(int array[], int arraySize){
    for(int i=0; i<arraySize; i++){
        printf("%d, ", array[i]);
    }
    printf("\n");
}

void setter(int ***P, int k){
    ***P = k;
}

void pointerSwap(int ***A2, int ***B2){
    int **temp = *A2;
    *A2 = *B2;
    *B2 = temp;
}

int main(){

    //Fibonacci Functions
    
    unsigned long long int n;
    printf("Please enter a number:");
    scanf("%llu", &n);

    printf("%llu\n", recursiveFibonacci(n));
    printf("%llu\n", fibonacci(n));
    printf("Please wait while asserts are being tested...\n\n");

    assert(recursiveFibonacci(0) == 0);
    assert(recursiveFibonacci(1) == 1);
    assert(recursiveFibonacci(2) == 1);
    assert(recursiveFibonacci(3) == 2);
    assert(recursiveFibonacci(5) == 5);
    assert(recursiveFibonacci(10) == 55);
    assert(recursiveFibonacci(30) == 832040);
    assert(recursiveFibonacci(47) == 2971215073);
    assert(fibonacci(0) == 0);
    assert(fibonacci(1) == 1);
    assert(fibonacci(2) == 1);
    assert(fibonacci(3) == 2);
    assert(fibonacci(5) == 5);
    assert(fibonacci(10) == 55);
    assert(fibonacci(30) == 832040);
    assert(fibonacci(47) == 2971215073);

    //Palindrome Functions

    int arraySize;
    printf("Please enter the size of the string: ");
    scanf("%d", &arraySize);
    
    char str[arraySize];//added two to account for the newline character and the null value
    printf("Please enter the string: ");
    getchar(); // Clear the input buffer
    scanf("%[a-zA-Z]", str); // Read the string and ignore all characters that are not a-z or A-Z

    if(strlen(str) < arraySize){//data validation to check if the string is less than the array size defined
        printf("The string provided is less than the specified size. The array size will be updated to %d\n",strlen(str)); 
        arraySize = strlen(str);
    }

    else if (strlen(str) > arraySize){ //data validation to check if the string is greater than the array size defined
        printf("Error the input exceeds the specified string size at %d. Rerun the program with the correct array size corresponding to the string input\n", strlen(str));
        return;
    }
    
    if(recursiveIsPalindrome(str, arraySize)){
        printf("The string %s is a palindrome.\n\n", str);
    }
    else{
        printf("The string %s is not a palindrome.\n\n", str);
    }
    
    if(isPalindrome(str, arraySize)){
        printf("The string %s is a palindrome.\n\n", str);
    }
    else{
        printf("The string %s is not a palindrome.\n\n", str);
    }    

    assert(isPalindrome("racecar", 7) == true);
    assert(isPalindrome("abcba", 5) == true);
    assert(isPalindrome("noon", 4) == true);
 
    int array[30];

    //populate array with randomized values between 0 and 1000
    randomizeArray(array, 30); 
    printf("Randomized Array: \n");
    printArray(array, 30);
    printf("\n");

    //non-recursive bubble sort, print and test
    bubbleSort(array, 30);
    printf("Sorted Array: \n");
    printArray(array, 30);
    isSorted(array, 30);
    printf("\n");

    //randomize array with elements again to test recursive bubble sort
    randomizeArray(array, 30);
    printf("Randomized Array: \n");
    printArray(array, 30);
    printf("\n");

    //recursive bubble sort, print and test
    recursiveBubbleSort(array, 30);
    printf("Sorted Array: \n");
    printArray(array, 30);    
    isSorted(array, 30);
    printf("\n");

//For the following stack frames the frames are popped off from the top of the stack to the bottom of the stack

 /* STACK FRAME: Recursive Fibonacci
        recursiveFibonacci:
            n = 4
            return recursiveFibonacci(3) + recursiveFibonacci(2)
            return address: recursiveFibonacci: 12
        recursiveFibonacci:
            n = 3
            return recursiveFibonacci(2) + recursiveFibonacci(1)
            return address: recursiveFibonacci: 12
        recursiveFibonacci:
            n = 1
            return 1
            return address: main:126
        main:
            printf("%11u", fibonacci(47));
            return address: OS
    */

    /*  STACK FRAME: recursiveIsPalindrome
        recursiveIsPalindrome:
            str = "abcdba"
            arraySize = 6
            return recursiveIsPalindrome("bcdb", 5)
            return address: main: 142
        recursiveIsPalindrome:
            str = "bcdb"
            arraySize = 5
            return false
            return address: main: 142
        main:
            if(recursiveIsPalindrome(str, arraySize)){
                printf("The string is a palindrome.");
            }
            return address: OS
    
    */

    int i = 0, j = 0;
    int *A = &i;
    int *B = &j;
    int **A2 = &A;
    int **B2 = &B;
    int ***P = &A2; 
    
    setter(P, 2);
    printf("i was changed to: %d\n\n", i);//print dereferenced value of P = 2

    pointerSwap(&A2, &B2);

    setter(P, 8);

    printf("i\t :%d \n", i);
    printf("A\t :%d \n", *A);
    printf("B2\t :%d \n\n", **B2);

    printf("j\t :%d \n", j);
    printf("B\t :%d \n", *B);
    printf("A2\t :%d \n", **A2);
    printf("P\t :%d \n", ***P);
        


    return 0;
    }