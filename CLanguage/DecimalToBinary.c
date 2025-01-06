#include <stdio.h>
#include <math.h>

//define function prototype
long long int decimalToBinary(long long int decimalNumber);

long long int main(){
    //Step 1: Get user input
    int decimalNumber;
    long long int binaryNumber;
    printf("Enter the decimal integer : ");
    scanf("%d", &decimalNumber);

    //Step 2: Call function and pass input, receive answer from function
    binaryNumber = decimalToBinary(decimalNumber);

    //Step 3: Print answer returned from area function
    printf("The number %d converted to binary is %lld\n", decimalNumber, binaryNumber);
    return 0;
}

//define function (function should return a value, no printing)
long long int decimalToBinary(long long int decimalNumber){//128
    long long int binaryNumber = 0;
    int remainder;
    long long int position = 1;
    while(decimalNumber > 0){//127
        remainder = decimalNumber % 2;//1
        binaryNumber += remainder * position;//1
        decimalNumber /= 2;//move the reference to the next bit
        position *= 10;//move the position
    }

    return binaryNumber;
}