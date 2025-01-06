/*   
Developer: Taylor Laporte, Student Number 102755730
Date: 6/6
*/

#include <stdio.h>

int main(){
    float N, sum, average;
    printf("Input integer between 1 and 1000\n");
    scanf("%f",&N);//obtain user input
    for(int i= 1;i <= N; i++){//loop to add all integers between 1 and the provided number (inclusive of the provided number)
        sum += i;//add current index number to sum
    }
    average = sum / N;//calculate average from sum divided by the number of integers added to the sum
    printf("sum is %.2f: ", sum);//print float valuevof sum with two decimal points of precision
    printf("average is %.2f: ", average);//print float value of average with two decimal points of precision
    return 0;
}
