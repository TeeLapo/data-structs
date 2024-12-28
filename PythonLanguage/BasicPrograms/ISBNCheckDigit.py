def main():
    isbn_input = input("Insert 12 digit ISBN: ")
    first_half = int(isbn_input[:6]) # Get the first 6 digits
    second_half = int(isbn_input[6:12]) # Get the next 6 digits
    multiplier = 1
    ISBNProduct = 0 # Initialize ISBNProduct outside the loop

    num1 = second_half
    while num1 > 0:
        num2 = num1 % 10
        num1 = num1 // 10 # Use integer division
        ISBNProduct += num2 * multiplier # Accumulate the product
        if multiplier == 1:
            multiplier = 3 # Corrected assignment
        else:
            multiplier = 1

    num1 = first_half
    while num1 > 0:
        num2 = num1 % 10
        num1 = num1 // 10 # Use integer division
        ISBNProduct += num2 * multiplier # Accumulate the product
        if multiplier == 1:
            multiplier = 3 # Corrected assignment
        else:
            multiplier = 1

    checkDigit = int(10 - (ISBNProduct % 10))
    print(checkDigit) # Corrected variable name

if __name__ == "__main__":
    main()