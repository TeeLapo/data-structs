package Labs;
import java.util.Scanner;

public class BracketValidator {

    public static boolean isBalanced(String input) {
        Stack<Character> stack = new Stack<>(input.length());

        for (int i = 0; i < input.length(); i++) {
            char currentChar = input.charAt(i);

            if (String.valueOf(currentChar).matches("[\\{\\[\\(]")) {
                stack.push(currentChar);
            } else if (String.valueOf(currentChar).matches("[\\}\\]\\)]")) {
                if (stack.isEmpty()) { //Case where the stack is empty and we have an orphaned closing bracket ie. unbalanced
                    return false;
                }
                char lastOpenBracket = stack.pop();
                if ((lastOpenBracket == '{' && currentChar != '}') || (lastOpenBracket == '[' && currentChar != ']') || 
                (lastOpenBracket == '(' && currentChar != ')')) { //Case where the closing bracket does not match the opening bracket
                    return false;
                }
            } else if (String.valueOf(currentChar).matches("[0-9/*\\-+]")) { //Continues if the character is valid
                continue;
            } else {
                throw new IllegalArgumentException("Invalid character(s) in input starting at: " + currentChar); //Case where the character is invalid
            }
        }

        return stack.isEmpty();  // Stack should be empty if balanced
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.print("Enter a string to check for balanced brackets: ");
        String input = scanner.nextLine();

        long startTime = System.nanoTime();

        boolean result = isBalanced(input);
        if (result) {
            System.out.println("The string has balanced brackets.");
        } else {
            System.out.println("The string does not have balanced brackets.");
        }

        scanner.close();

        long endTime = System.nanoTime();
        long duration = (endTime - startTime);
        System.out.println("Time taken: " + duration + " nanoseconds");
    }    
}

//Resolves 2: i. T, ii. F, iii. F, iv. T

/*The worst case that the algorithm takes to determine whether the string is correct (balanced)
is O(n) as the dominant operation is the for loop that needs to go through all the characters n 
in the input string as this for loop only terminates .*/