#include <stdio.h>

int factorial(int n){
    int i = n-1;
    int factorial = 1;
    if (i > 1) {
        return factorial;
    }
    factorial(n);
    factorial *= n;
    i--;
    
}

int main() {
//calculate factorials
int n;

printf("Enter a number: ");
scanf("%d", &n);

factorial(n);

printf("Factorial of %d = %d\n", n, factorial(n));

    return 0;
}