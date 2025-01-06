/*   
Developer: Taylor Laporte, Student Number 102755730
Date: 6/6
*/

#include <stdio.h>

int main(){

//define variables
int numberOfLines;
int count = 0;

//obtain input
printf("Insert number of lines to print\n"); 
scanf("%d", &numberOfLines);

while(numberOfLines>count){//loop for new line and to increment count                        
    for(int i=0;i<=count;i++){// loop to print *s for current line up until count, which increments after line is printed in outer loop               
        printf("* ");                                                  
    }                                          
    count++;//increment count
    printf("\n");//go to next line
}
    return 0;
}
