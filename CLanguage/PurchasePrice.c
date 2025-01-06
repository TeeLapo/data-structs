#include <stdio.h>

    int main() {
    int purchase;
    int discount;
    int final_price;
    printf("Enter purchase price ");
    scanf("%d", &purchase);
    if (purchase > 100){
        discount = 0.10 * purchase;
        final_price = purchase - discount;
    }
    else{
        final_price = purchase;
    }
    printf("%d",final_price);
    return 0;
}