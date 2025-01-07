#include <stdio.h>

int main(){
    int num1, num2, firstHalf, secondHalf, checkDigit, ISBNProduct, multiplier;
    printf("insert 12 digit ISBN ");
    scanf("%6d%6d", &firstHalf, &secondHalf);
    ISBNProduct = 0;
    multiplier = 1;
    num1 = secondHalf;
    while (num1 > 0)
    {
        num2 = num1 % 10; //get last digit
        num1 = num1 / 10; //remove last digit
        ISBNProduct = ISBNProduct + num2 * multiplier;
        if (multiplier ==1 ){
            multiplier = 3;
        }
        else{
            multiplier = 1;
        }
    }
    num1 = firstHalf;
    while (num1 > 0){
        num2 = num1 % 10; //get last digit
        num1 = num1 / 10; //remove last digit
        ISBNProduct = ISBNProduct + num2 * multiplier;
        if (multiplier ==1 ){
            multiplier = 3;
        }
        else{   
            multiplier = 1;
        }
    }
    checkDigit = 10 - (ISBNProduct % 10);
    printf("%d",checkDigit);
}
