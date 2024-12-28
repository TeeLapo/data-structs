import random

def main():
    random.seed() #seed the random number generator with the current time
    goal = random.randint(1, 50) #generate a random number between 1 and 50
    total_guesses = 10  # Renamed for clarity
    guesses_left = total_guesses  # Track remaining guesses

    for _ in range(total_guesses):  # Use _ since we don't need the loop variable
        number = int(input("Guess a number from 1-50\n"))

        if number == goal:
            guesses_left -= 1
            break  # Correct guess, exit the loop
        elif number > goal:
            print("Too high")
        elif number < goal:
            print("Too low")    
        
        guesses_left -= 1  # Decrement guesses left after each incorrect guess
    
    if number == goal:
        guesses_used = total_guesses - guesses_left  # Calculate guesses used correctly
        if guesses_used > 1:
            print("Congratulations! You've guessed the correct number after %d guesses" % guesses_used)
        else:
            print("Congratulations! You've guessed the correct number after %d guess" % guesses_used)
    else:
        print("Out of guesses! The number was %d" % goal)
        
if __name__ == "__main__":
    main()
