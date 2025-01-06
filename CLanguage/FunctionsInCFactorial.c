#include <stdio.h>
#include <stdint.h>

//define function prototype
long long int processFactorial(int number);

int main(){
//Step 1: Get user input
int number;
long long int factorial;
printf("Enter a number to calculate its factorial: ");
scanf("%d", &number);

//Step 2: Call function and pass input, receive answer from function
factorial = processFactorial(number);

//Step 3: Print answer returned from area function
printf("The factorial of %d is %lld\n", number, processFactorial(number));

return 0;
}

//define function (function should return a value, no printing)
long long int processFactorial(int number){
    long long int factorial = number;//initialize factorial to number
    for (int i = 2; i < number; i++){//loop for each factor from 2 to number-1 ex. for 5, loop 2,3,4 as 1 is redundant and 5 is given
        factorial *= i;
    }
    return factorial;
}

//This program can handle factorials that output up to 2^63-1 before the long long int data type overflows. This results in the factorial overflowing after 20!
