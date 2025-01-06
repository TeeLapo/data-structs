#include <stdio.h>
#include <stdlib.h>

int main() {
    int number, frequency=0;
    int array[30];
    for (int i = 0; i < 30; i++) {
        array[i] = (rand() % 21);// Generate a random number between 0 and 20
        printf("%d ", array[i]);
    }
    printf("\n");
    printf("Enter a number to check the frequency in the array\n");
    scanf("%d", &number);
    for (int i = 0; i < 30; i++) {
        // if the array and each index are equal, increment the frequency counter
        if (array[i] == number) {
            frequency++;
        }
    }
    printf("The number %d appears %d times in the array", number, frequency);
    return 0;
}