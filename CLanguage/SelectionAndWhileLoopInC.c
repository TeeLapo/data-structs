#include<stdio.h>
int main(void){
    int num1, num2, num3, largestNum, smallestNum;
    printf("input 3 numbers ");
    scanf("%d %d %d",&num1, &num2, &num3);
    if (num1 > num2 && num1 > num3){//check if num1 is largest
        largestNum = num1; //num1 is largest
        if(num2 > num3){//check remaining numbers to determine the smallest
            smallestNum = num3;//num3 is smallest
        }
        else {
            smallestNum = num2;//num2 is smallest
        }
    }
    else if (num2 > num3 && num2 > num1){//check if num2 is largest
        largestNum = num2; //num2 is largest
        if(num1 > num3){//check remaining numbers to determine the smallest
            smallestNum = num3;//num3 is smallest
        }
        else {
            smallestNum = num1;//num2 is smallest
        }
    }
    else{
        largestNum = num3; //num3 is largest
    }
    printf("%s%d%s", "The largest number is ", largestNum, "\n");
    printf("%s%d", "The smallest number is ", smallestNum);
}