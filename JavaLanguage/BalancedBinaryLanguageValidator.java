package Labs;
import java.util.Scanner;

public class BalancedBinaryLanguageValidator {

    public static boolean isBalanced(String input) {
        Stack<Character> stack = new Stack<>(input.length());
        
        boolean popped = false;
        for (int i = 0; i < input.length(); i++) {
            char currentChar = input.charAt(i);

            if (!String.valueOf(currentChar).matches("[01]")) {
                throw new IllegalArgumentException("Invalid character(s) in input: " + currentChar); //Case where the character is invalid
            }
            if (String.valueOf(currentChar).matches("[0]") && !popped) { //Only push 0 onto stack in the case where a previous character (1) was not popped
                stack.push(currentChar);
            } else {
                if (stack.isEmpty()) { //Case where the stack is empty and we have an orphaned 1 ie. unbalanced
                    return false;
                }
                if (stack.pop() != '0') { //Case where the popped char is not 0. This case should not be reached as 0 is the only character to be pushed onto the stack
                    return false;
                }
                popped = true;
            }
        }
        return stack.isEmpty();  // Stack should be empty if balanced
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.print("Enter a string to check if the language is valid: ");
        String input = scanner.nextLine();

        boolean result = isBalanced(input);
        if (result) {
            System.out.println("The input is valid in the context free language.");
        } else {
            System.out.println("The input is not valid in the context free language.");
        }

        scanner.close();
    }
}

/*The worst case that the algorithm takes to determine whether the string is correct in terms of 
the binary language is O(n) as the dominant operation is the for loop that needs to go through 
all the characters n in the input string as this for loop only terminates .*/