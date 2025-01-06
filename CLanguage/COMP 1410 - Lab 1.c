#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

int recursiveFactorial(int n){
    if(n < 2){//base case
        return 1;
    }
    return n * recursiveFactorial(n - 1);//recursive case decrement n by 1
}

float recursivePower(float base, float exponent){ 
    if(exponent == 0){
        return 1;//base case when any exponent is raise to zero it is equal to 1
    }
    if(exponent == 1){
        return base;//base case when any exponent is raised to 1 it is equal to the base
    }
    return base * recursivePower(base, exponent-1);//recursive case decrement exponent by 1
}

//Perform matrix multiplication of two 2D arrays of size NxN and store the result in a third 2D array
void matrixMultiplication(int matrixSize, int a[matrixSize][matrixSize], int b[matrixSize][matrixSize], int c[matrixSize][matrixSize]){
    for (int i = 0; i < matrixSize; i++){//Iterate through the rows
        for (int j = 0; j < matrixSize; j++){//Iterate through the columns
            c[i][j] = 0; // Initialize the element of c to 0 before calculating the sum
            for (int k = 0; k < matrixSize; k++) {//Iterate through the columns of the first matrix and rows of the second matrix
                c[i][j] += a[i][k] * b[k][j];//Add the product of the elements of the two matrices to the 0 initialized element of c
            }
        }
    }
return;
}

void swapMatricesValue(int matrixSize, int a[matrixSize][matrixSize], int b[matrixSize][matrixSize]){
    for (int i = 0; i < matrixSize; i++){//Iterate through the rows
        for (int j = 0; j < matrixSize; j++){//Iterate through the columns
            int temp = a[i][j];//Store the value of a in a temporary variable
            a[i][j] = b[i][j];
            b[i][j] = temp;
        }
    }
    return;
}

void copyMatrices(int matrixSize, int original[matrixSize][matrixSize], int copy[matrixSize][matrixSize]){
    for (int i = 0; i < matrixSize; i++){//Iterate through the rows
        for (int j = 0; j < matrixSize; j++){//Iterate through the columns
            copy[i][j] = original[i][j];//Copy the elements of the original matrix to the copy matrix
        }
    }
    return;
}

void swapMatrices(int matrixSize, int a[matrixSize][matrixSize], int b[matrixSize][matrixSize]){
    int temp[matrixSize][matrixSize];
    copyMatrices(matrixSize, a, temp);//Copy the elements of a to a temporary matrix
    copyMatrices(matrixSize, b, a);//Copy the elements of b to a
    copyMatrices(matrixSize, temp, b);//Copy the elements of the temporary matrix to b
    return;
}

void swapPointers(int **PA, int **PB){
    int *temp = *PA;
    *PA = *PB;
    *PB = temp;
    return;
}

int* matrixSearch(int searchValue, int matrixSize, int (*a)[matrixSize]){
    for (int i = 0; i < matrixSize; i++){
        for (int j = 0; j < matrixSize; j++){
            if(a[i][j] == searchValue){
                    return &a[i][j];
            }
        }
    }
    return NULL;
}

int main() {
    printf("Enter a number to calculate its factorial: ");
    int n;
    scanf("%d", &n);
    printf("The factorial of %d, is %d", n, recursiveFactorial(n));

    /*
        recursiveFactorial:
            n = 1
            return address: recursiveFactorial: 17
        recursiveFactorial:
            n = 2
            return address: recursiveFactorial: 17
        recursiveFactorial:
            n = 3
            return address: main:26
        main:
            printf("The factorial of %d, is %d", n, recursiveFactorial(3));
            return address: OS
    */

    float base;
    float exponent;
    printf("Enter a number: ");
    scanf("%f", &base);
    printf("Enter the power you would like to calculate: ");
    scanf("%f", &exponent);
    printf("%.2f raised to the power of %.2f is %.4f", base, exponent, recursivePower(base, exponent));

    /*
        recursivePower:
            base = 0.5
            exponent = 1
            return address: recursivePower: 29
        recursivePower:
            base = 0.5
            exponent = 2
            return address: recursivePower: 29
        recursivePower:
            base = 0.5
            exponent = 3
            return address: recursivePower: 29
        recursivePower:
            base = 0.5
            exponent = 4
            return address: main:49
        main:
            printf("%d raised to the power of %d is %d", base, exponent, recursivePower(base, exponent));
            return address: OS
    */

   int matrixSize;
   printf("Enter the size N to generate two matrices of size NxN: ");
   scanf("%d", &matrixSize);
   
   int a[matrixSize][matrixSize];
   int b[matrixSize][matrixSize];
   srand(time(NULL));

    for(int i = 0; i < matrixSize; i++){
        for(int j = 0; j < matrixSize; j++){
            a[i][j] = rand() % 51;
            b[i][j] = rand() % 51;
        }
    }
    printf("\n");

    //Print the first matrix
    printf("Matrix A\n");

    for (int i = 0; i < matrixSize; i++){
        for (int j = 0; j < matrixSize; j++){
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    
    //Print the second matrix  
    printf("Matrix B\n");

    for (int i = 0; i < matrixSize; i++){
        for (int j = 0; j < matrixSize; j++){
            printf("%d ", b[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    int c[matrixSize][matrixSize];

    matrixMultiplication(matrixSize, a, b, c);
    
    //Print the result of the matrix multiplication
    printf("Matrix AB\n");

    for (int i = 0; i < matrixSize; i++){
        for (int j = 0; j < matrixSize; j++){
            printf("%d ", c[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    
    swapMatrices(matrixSize, a, b);

    //Print the first matrix after swapping
    printf("Swapped Matrix A\n");

    for (int i = 0; i < matrixSize; i++){
        for (int j = 0; j < matrixSize; j++){
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    //Print the second matrix after swapping
    printf("Swapped Matrix B\n");

    for (int i = 0; i < matrixSize; i++){
        for (int j = 0; j < matrixSize; j++){
            printf("%d ", b[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    int (*PA)[matrixSize] = a;//Declare a pointer to a 2D array
    int (*PB)[matrixSize] = b;//Declare a pointer to a 2D array

    swapPointers(PA, PB);//Swap the pointers passing the address of the pointers

    //Test if there's a single digit output in the randomized matrix output and provide the address of that element
    for (int i = 1; i <= 9; i++) {
        if (matrixSearch(i, matrixSize, PB)!= NULL) {
            printf("%d was found in the matrix at %p\n", i, matrixSearch(i, matrixSize, PB));
        }
    }
    
    return 0;

}

