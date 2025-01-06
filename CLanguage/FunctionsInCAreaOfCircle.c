#include <stdio.h>
#include <math.h>

//define function prototype
float areaOfCircle(float radius);

int main(){
//Step 1: Get user input
float radius;
float area;
printf("Enter the radius of the circle: ");
scanf("%f", &radius);

//Step 2: Call function and pass input, receive answer from function
area = areaOfCircle(radius);

//Step 3: Print answer returned from area function
printf("The area of the circle is: %.2f\n", areaOfCircle(radius));

return 0;
}

//define function (function should return a value, no printing)
float areaOfCircle(float radius){
    float area = M_PI * pow(radius, 2);
    return area;
}
