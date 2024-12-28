def main():
    purchase_input = input("Enter the purchase price: ")
    purchase = int(purchase_input)
    if purchase > 100:
        discount = 0.10 * purchase
        final_price = purchase - discount
    else:
        final_price = purchase
    print("The final price is " + str(final_price))

if __name__ == "__main__":
    main()