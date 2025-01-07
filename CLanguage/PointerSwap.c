#include <stdio.h>
#include <stdlib.h>

void setter(int ***P, int k){
    ***P = k;
}

void pointerSwap(int ***A2, int ***B2){
    int **temp = *A2;
    *A2 = *B2;
    *B2 = temp;
}

int main() {
    int i, j;
    int *A = &i;
    int *B = &j;
    int **A2 = &A;
    int **B2 = &B;
    int ***P = &A2; 
    
    setter(P, 2);
    printf("%d", ***P);//print dereferenced value of P = 2

    pointerSwap(&A2, &B2);

    setter(P, 8);

    printf("%d \n", ***P);
    printf("%d \n", **P);
    printf("%d \n", **B2);
    printf("%d \n", j);
    printf("%d \n", *B);
    printf("%d \n", *A2);
    printf("%d \n", *P); 

    return 0;
}