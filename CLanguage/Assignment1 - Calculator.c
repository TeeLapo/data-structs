    #include <stdio.h>

    int main(){
        printf("Welcome to my Command-Line Calculator (CLC)\n");
        printf("Developer: Taylor Laporte, Student Number 102755730\n");
        printf("Version: 1\n");
        printf("Date: 6/3\n\n");

        int validOperation;
        float num1, num2, calculation;
        char operationType, binaryOperation, continueCondition;

        operationType = '0';

        while (operationType != 'E'){//loop to present options for different operations
            printf("Please select one of the following items\n");
            printf("B) - Binary Mathematical Operations, such as addition and subtraction\n");
            printf("U) - Unary Mathematical Operations, such as square root, and log\n");
            printf("A) - Advanced Mathematical Operations, using variables, arrays\n");
            printf("V) - Define variables and assign them values\n");
            printf("E) - Exit\n");
            scanf(" %c", &operationType); // Added space before %c to skip whitespace
            while (operationType == 'B'){//loop to continue with binary operations
                binaryOperation = '0';//initialize/reset binaryOperation
                printf("Please enter first number ");
                scanf("%f",&num1);
                do{
                    printf("Please enter the operation (+, -, *, /): ");
                    scanf(" %c", &binaryOperation);
                        if(binaryOperation == '+')
                            validOperation = 1;
                        else if(binaryOperation == '-')
                            validOperation = 1;
                        else if(binaryOperation == '*')
                            validOperation = 1;
                        else if(binaryOperation == '/')
                            validOperation = 1;
                        else{
                            validOperation = 0;
                            printf("invalid operation!");
                        }
                }
                while(validOperation == 0);
                 // binaryOperation will be a valid operation beyond here
                printf("Please enter second number ");
                scanf("%f", &num2);
                if (binaryOperation == '+'){
                    calculation = num1 + num2;
                }
                else if (binaryOperation == '-'){
                    calculation = num1 - num2;
                }
                else if (binaryOperation == '*'){
                    calculation = num1 * num2;
                }
                else if (binaryOperation == '/'){
                    calculation = num1 / num2;
                }
                printf("%.2f\n", calculation);
                printf("Please select one of the following options:\n");
                printf("Press Y to perform another Binary Operation:\n");
                printf("Press any other key to select another operation\n");
                scanf(" %c", &continueCondition);
                if (continueCondition == 'Y'){
                } 
                else {
                    operationType = '0'; //reset operationType to break loop
                }
            }    
            while (operationType == 'U'){
                        printf("Sorry, at this time I don't have enough knowledge to serve you in this category\n\n");
                operationType = '0'; //reset operationType to jump back to menu
            }
            while (operationType == 'A'){
                        printf("Sorry, at this time I don't have enough knowledge to serve you in this category\n\n");
                operationType = '0'; //reset operationType to jump back to menu
            }
            while (operationType == 'V'){
                        printf("Sorry, at this time I don't have enough knowledge to serve you in this category\n\n");
                operationType = '0'; //reset operationType to jump back to menu
            }
            if (operationType == 'E'){
                printf("Thanks for using my Simple Calculator. Hope to see you again, Goodbye!");
                return 0;
            }
        }
    }