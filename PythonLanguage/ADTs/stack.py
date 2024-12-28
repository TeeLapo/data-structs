class Stack:
    def __init__(self): # This is the constructor for the Stack class. It initializes the stack as an empty list. self is a reference to the current instance of the class similar to how this is used in other languages. Two underscores are used to denote that this is a special method.
        self.items = [] # This initializes the items attribute as an empty list.
    def isEmpty(self): # This method checks if the stack is empty by checking if the length of the stack is 0.
        return len(self.items) == 0
    def push(self, item): # This method adds an item to the top of the stack.
        self.items.append(item)
    def pop(self): # This method removes and returns the item at the top of the stack.
        if not self.isEmpty(): # This checks if the stack is not empty.
            return self.items.pop() # This removes and returns the item at the top of the stack.
        else: # If the stack is empty
            raise IndexError("pop from empty stack") # This raises an IndexError with the message "pop from empty stack".
    def peek(self): # This method returns the item at the top of the stack without removing it.
        if not self.isEmpty(): # This checks if the stack is not empty.
            return self.items[-1] # This returns the item at the top of the stack.
        else: # If the stack is empty
            raise IndexError("peek from empty stack") # This raises an IndexError with the message "peek from empty stack".
        
def isMatchingPair(character1, character2): # This function checks if two characters are matching pairs of brackets.
    if character1 == '(' and character2 == ')': # This checks if the two characters are matching pairs of brackets.
        return True # This returns True if the two characters are matching pairs of brackets.
    if character1 == '{' and character2 == '}': # This checks if the two characters are matching pairs of brackets.
        return True # This returns True if the two characters are matching pairs of brackets.
    if character1 == '[' and character2 == ']': # This checks if the two characters are matching pairs of brackets.
        return True # This returns True if the two characters are matching pairs of brackets.
    return False # This returns False if the two characters are not matching pairs of brackets.

def main(): # This is the main function that runs the program.
    import re  # Import the re module for regular expressions
    stack = Stack()  # Create an instance of the Stack class
    s = input("Enter something: ") # input() is a built-in function that gets input from the user
    for i in range(0, len(s)):  # len() is a built-in function that returns the length of a string. This is within a for-loop, which requires parameters for the range of the loop.
        if re.match(r'[\[{\(]', s[i]):  # Use re.match to check for opening brackets
            stack.push(s[i])  # Call push on the stack instance
        elif re.match(r'[\]}\)]', s[i]):  # Use re.match to check for closing brackets
            if stack.isEmpty(): # Check if the stack is empty
                print("Unbalanced") # Print "Unbalanced" if the stack is empty
                return False # Return False if the stack is empty
            if not isMatchingPair(stack.pop(), s[i]): # Check if the stack is not matching pairs
                print("Unbalanced") # Print "Unbalanced" if the stack is not matching pairs
                return False # Return False if the stack is not matching pairs
    if stack.isEmpty(): # Check if the stack is empty
        print("Balanced") # Print "Balanced" if the stack is empty
        return True # Return True if the stack is empty
    else: # If the stack is not empty
        print("Unbalanced") # Print "Unbalanced" if the stack is not empty  
        return False # Return False if the stack is not empty   

if __name__ == "__main__": # This is the main function that runs the program
    main()

