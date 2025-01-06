    #include <stdio.h>
    #include <math.h>
    #include <stdlib.h>
    #include <ctype.h>

//function to validate binary operation. Expected inputs are an array of valid characters and an operator

int isValidOperation(char acceptableOperations[], int arraySize, char operator){
    for(int i = 0; i < arraySize; i++){
        if(acceptableOperations[i] == operator){
            return 1;
        }
    }
    return 0;
}
//            printf("Please enter second number ");
//            scanf("%f", &num2);

//function to calculate binary operation. Expected inputs are two numbers and a binary operation
float binaryOperations(float num1, float num2, char operator){
    float binaryCalculation;
    switch(operator) {
        case '+':
            binaryCalculation = num1 + num2;
            break;
        case '-':
            binaryCalculation = num1 - num2;
            break;
        case '*':
            binaryCalculation = num1 * num2;
            break;
        case '/':
            binaryCalculation = num1 / num2;
            break;
        case '%':
            binaryCalculation = remainderf(num1, num2);
            break;
        case 'P':
        case '^':
            binaryCalculation = pow(num1, num2);
            break;
        case 'X':
            binaryCalculation = fmax(num1, num2);
            break;
        case 'I':
            binaryCalculation = fmin(num1, num2);
            break;
    }
    return binaryCalculation;
}

//function to continue with current operation or select another operation

int continueCurrentOperation(char str[]){
    printf("Please select one of the following options:\n");
    printf("Press Y to perform another %s:\n", str);
    printf("Press any other key to select another operation\n");
    int continueCondition;
    scanf(" %c", &continueCondition);
    if (continueCondition == 'Y' || continueCondition == 'y'){
        return 1;
    } 
    else {
        return 0;
    }
}

//function to process unary operation given the operation and number

float unaryOperations(float num1, char operator){
    float unaryCalculation;
    switch (operator){
        case 'S': //Square root
        case 's': //accept lowercase
            unaryCalculation = sqrt(num1);
            break;
        case 'L': //Logarithm base e
        case 'l': //accept lowercase
            unaryCalculation = log(num1);
            break;
        case 'E': //Exponential
        case 'e': //accept lowercase
            unaryCalculation = exp(num1);
            break;
        case 'C': //Ceiling
        case 'c': //accept lowercase
            unaryCalculation = ceil(num1);
            break;
        case 'F': //Floor
        case 'f': //accept lowercase
            unaryCalculation = floor(num1);
            break;
        default:
            break;
    }
    return unaryCalculation;
}

//function to utilize a variable buffer that will handle cases where the user inputs char values or float values

                    float processVariableBuffer(float a, float b, float c, float d, float e){
                        while(1){
                            char buffer[8];//buffer array to store string input or float value (up to 7 characters + null terminator)
                            scanf("%7s", buffer);//limit input to 7 characters to avoid overflow issues
                            while(getchar() != '\n');  // Clears the input buffer
                            switch (buffer[0]){
                                case 'a':
                                    return a;
                                case 'b':
                                    return b;
                                case 'c':
                                    return c;
                                case 'd':
                                    return d;
                                case 'e':
                                    return e;
                                default:
                                    if(isdigit(buffer[0]) == 0){//check if the input is a number
                                        printf("Invalid input!\n Please enter a valid number or variable (a,b,c,d,e,f)\n");
                                        continue;
                                    }
                                    return atof(buffer);//return converted float value to be processed in the subsequent function. 
                            }
                        }
                    }



int main(){
    printf("Welcome to my Command-Line Calculator (CLC)\n");
    printf("Developer: Taylor Laporte, Student Number 102755730\n");
    printf("Version: 1\n");
    printf("Date: 6/13\n\n");

    int validOperation;
    float num1, num2, calculation;
    char operationType, operator;
    char acceptableBinaryOperations[] = {'+', '-', '*', '/', '%', 'P', '^', 'X', 'I'};
    char acceptableUnaryOperations[] = {'S', 's', 'L', 'l', 'E', 'e', 'C', 'c', 'F', 'f'};
    int arraySize;
    float a = 0.00, b = 0.00, c = 0.00, d = 0.00, e = 0.00;

    
    //Select from Menu Options for Operation Types

    operationType = '0';
    while (operationType != 'E'){//loop to present options for different operations
        printf("Please select one of the following items\n");
        printf("B) - Binary Mathematical Operations, such as addition and subtraction\n");
        printf("U) - Unary Mathematical Operations, such as square root, and log\n");
        printf("A) - Advanced Mathematical Operations, using variables, arrays\n");
        printf("V) - Define variables and assign them values\n");
        printf("E) - Exit\n");
        scanf(" %c", &operationType); // Added space before %c to skip whitespace

        //Process Binary Operations

        while (operationType == 'B' || operationType == 'b'){//loop to continue with binary operations
            validOperation = '0';//initialize/reset validOperations
            operator = '0';//initialize/reset operator
            arraySize = sizeof(acceptableBinaryOperations)/sizeof(acceptableBinaryOperations[0]);
            printf("Please enter first number ");
            while (scanf("%f",&num1) != 1) {
                printf("Invalid input! Please enter a valid number.\n");
                while(getchar() != '\n');  // Clears the input buffer
            }
            do{
                printf("Please enter the binary operation (+, -, *, /, %, P, X, I): ");
                scanf(" %c", &operator);
                validOperation = isValidOperation(acceptableBinaryOperations, arraySize, operator);
            } while(validOperation == 0);
                // operator will be a valid operation beyond here
            printf("Please enter second number ");
            while (scanf("%f",&num2) != 1) {
                printf("Invalid input! Please enter a valid number.\n");
                while(getchar() != '\n');  // Clears the input buffer
            }
            calculation = binaryOperations(num1, num2, operator);
            printf("%.2f\n\n", calculation);
            if (continueCurrentOperation("Binary Operation")){
            //Do nothing. Will continue with binary operations
            } 
            else {
                operationType = '0'; //reset operationType to break loop
            } 
        }   

        //Process Unary Operations

        while(operationType == 'U' || operationType == 'u'){//loop to continue with unary operations
            validOperation = '0';//initialize/reset validOperations
            operator = '0';//initialize/reset operator
            arraySize = sizeof(acceptableUnaryOperations)/sizeof(acceptableUnaryOperations[0]);
            do{
            printf("Please enter the unary operation you would like to perform ('S', 'L', 'E', 'C' 'F')\n");
            printf("S) - Square Root\n");
            printf("L) - Logarithm basee e\n");
            printf("E) - Exponentiation\n");
            printf("C) - Ceiling\n");
            printf("F) - Floor\n");
            scanf(" %c",&operator);
            validOperation = isValidOperation(acceptableUnaryOperations, arraySize, operator);
            } while(validOperation == 0);
            //operator will be a valid operation beyond here
            printf("Please enter the number to perform the operation on\n");
            while (scanf("%f",&num1) != 1) {
            printf("Invalid input! Please enter a valid number.\n");
            while(getchar() != '\n');  // Clears the input buffer
            }
            calculation = unaryOperations(num1, operator);
            printf("%.2f\n\n", calculation);
            if (continueCurrentOperation("Unary Operation")){
            } 
            else {
            operationType = '0'; //reset operationType to break loop
            } 
        }

        //Process Advanced Operations

        while (operationType == 'A'|| operationType == 'a'){
        //            printf("Sorry, at this time I don't have enough knowledge to serve you in this category\n\n");
        //    operationType = '0'; //reset operationType to jump back to menu
        //continue; // REMOVE ONCE FUNCTIONS BELOW ARE COMPLETE
            validOperation = '0';//initialize/reset validOperations
            operator = '0';//initialize/reset operator
            int advancedOperationSubType;
            printf("Please select one of the following items to use with variables\n");
            printf("B) - Binary Mathematical Operations, such as addition and subtraction\n");
            printf("U) - Unary Mathematical Operations, such as square root, and log\n");
            printf("E) - Exit\n");
            scanf(" %c",&advancedOperationSubType);
            switch (advancedOperationSubType)
            {
            case 'B':
            case 'b':
                while(advancedOperationSubType == 'B' || advancedOperationSubType == 'b'){//loop to continue with advanced binary operations
                    arraySize = sizeof(acceptableBinaryOperations)/sizeof(acceptableBinaryOperations[0]);
                    printf("Please enter first number or variable: ");
                    num1 = processVariableBuffer(a, b, c, d, e);
                    do{
                        printf("Please enter the binary operation (+, -, *, /, %, P, X, I): ");
                        scanf(" %c", &operator);
                        validOperation = isValidOperation(acceptableBinaryOperations, arraySize, operator);
                    } while(validOperation == 0);
                    // operator will be a valid operation beyond here
                    printf("Please enter second number or variable: ");
                    num2 = processVariableBuffer(a, b, c, d, e);
                    calculation = binaryOperations(num1, num2, operator);
                    printf("%.2f\n\n", calculation);
                    if (continueCurrentOperation("Advanced Binary Operation")){
                    } 
                    else {
                        advancedOperationSubType = '0'; //reset operationType to break loop
                    }
                }
                break;        
            case 'U':
            case 'u':
                while(advancedOperationSubType == 'U' || advancedOperationSubType == 'u'){//loop to continue with advanced unary operations
                    arraySize = sizeof(acceptableUnaryOperations)/sizeof(acceptableUnaryOperations[0]);
                    do{
                        printf("Please enter the unary operation you would like to perform ('S', 'L', 'E', 'C' 'F')\n");
                        printf("S) - Square Root\n");
                        printf("L) - Logarithm basee e\n");
                        printf("E) - Exponentiation\n");
                        printf("C) - Ceiling\n");
                        printf("F) - Floor\n");
                        scanf(" %c", &operator);
                        validOperation = isValidOperation(acceptableUnaryOperations, arraySize, operator);
                    } while(validOperation == 0);
                    // operator will be a valid operation beyond here
                    printf("Please enter the number or variable to perform the operation on\n");
                    num1 = processVariableBuffer(a, b, c, d, e);
                    calculation = unaryOperations(num1, operator);
                    printf("%.2f\n\n", calculation);
                    if (continueCurrentOperation("Advanced Unary Operation")){
                    } 
                    else {
                        advancedOperationSubType = '0'; //reset operationType to break loop
                    }
                }
                break;
            case 'E':
            case 'e':
                operationType = '0';
                break;
            default:
                break;
            }
            if (continueCurrentOperation("Advanced Operation")){
            } 
            else {
                operationType = '0'; //reset operationType to break loop
            }                 
        }

        //Process Variable Assignment

        while (operationType == 'V' || operationType == 'v'){
            printf("Please enter the variable name you would like to assign a value to (a, b, c, d, e)\n");
            scanf(" %c",&operator);
            switch (operator){
                case 'a':
                case 'A':
                    printf("Please enter the value you would like to assign to a\n");
                    scanf("%f", &a);
                    break;
                case 'b':
                case 'B':
                    printf("Please enter the value you would like to assign to b\n");
                    scanf("%f", &b);
                    break;
                case 'c':
                case 'C':
                    printf("Please enter the value you would like to assign to c\n");
                    scanf("%f", &c);
                    break;
                case 'd':
                case 'D':
                    printf("Please enter the value you would like to assign to d\n");
                    scanf("%f", &d);
                    break;
                case 'e':
                case 'E':
                    printf("Please enter the value you would like to assign to e\n");
                    scanf("%f", &e);
                    break;
                default:
                    printf("Invalid variable name!\n");
                    continue;
            }
            if(continueCurrentOperation("Variable Assignment")){
                continue;
            }
            else {
                break;
            }
        if (operationType == 'E' || operationType == 'e'){
            printf("Thanks for using my Simple Calculator. Hope to see you again, Goodbye!");
            return 0;
            }
        }
    }
}