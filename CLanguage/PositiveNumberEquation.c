/*   
Developer: Taylor Laporte, Student Number 102755730
Date: 6/6
*/

#include <stdio.h>


int main(){

    int number, continuationCondition, factorial;
    float calculation;

    while(1){
        printf("Enter a positive integer (between 1 and 7, inclusive)\n");
        scanf("%d", &number);
        if (number > 0 && number < 8){//data validation to ensure number is within the acceptable range
        }
        else{
            printf("Error, invalid number\n");
            continue;
        }
        factorial = 1;//reset the factorial

            for (int j = 2; j <= number+1;j++){//loop to calculate the factorials
                factorial *= j;//calculate factorial instance
                printf("1/%d", factorial);//print current term for broader calculation
                if (j <= number)//print + after term for each term up to number. ie exclude appended + on number+1
                    printf(" + ");
                calculation += 1/(float)factorial;//add the current term to the running total
            }
        printf(" = %.3f\n",calculation);
        printf("Do you want to try again? ");
        scanf("%d", &continuationCondition);
        if (continuationCondition == 0){
            printf("Goodbye!");
            break;
        }
        calculation = 0;
    }
    return 0;
}
