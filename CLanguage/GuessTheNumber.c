/*   
Developer: Taylor Laporte, Student Number 102755730
Date: 6/6
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    srand(time(0));  // Seed the random number generator with the current time

    
    int goal = rand() % 50 + 1;
    int guesses = 10;
    int number;

    for (guesses; guesses >= 1;){//loop to allow for 10 guesses decrementing a guess for each iteration
        printf("Guess a number from 1- 50\n");
        scanf("%d", &number);
        --guesses;//decrementing here to obtain clarity with remaining guesses calculation below (line 38). With this in the for statement the calculation would need to be 11 - guesses.

        //Alternate seed for random number generator based on users first guess. Predictable if you know the value that will be produced with your first guess (ie. first guest of 1 will produce 34)
        //if (seed == 0){
        //    srand(number);
        //    seed = 1;
        //    goal = rand() % 50 + 1;
        //}        

        if (number == goal)//guess is correct, break out of loop
            break;
        else if (number > goal)//guess is too high
            printf("Too high\n");
        else if (number < goal)//guess is too low
            printf("Too low\n");
    }
    if (number == goal){
        guesses = 10 - guesses;//calculates the difference between the number of guesses left and the number of guesses
        if (guesses>1)
            printf("Congratulations! You've guessed the correct number after %d guesses", guesses);//print if the number of guesses left is more then one and guess should be pluralized
        else
            printf("Congratulations! You've guessed the correct number after %d guess", guesses);//print if there's only one guess left and the language should be singular
    }
    else
        printf("Out of guesses! The number was %d", goal);//print if the number was not guessed at this point where there are no guesses remaining
    return 0;
}
