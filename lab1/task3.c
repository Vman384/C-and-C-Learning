#include <stdio.h>
#include <math.h>

int main(){
    int height;
    int radius;
    float pi = 3.1415926553f ;
    printf("Enter height: \n");
    scanf("%d", &height);
    printf("Enter radius: \n");
    scanf("%d", &radius);
    float surfaceArea = pow(radius, 2)*pi*2+2*pi*height*radius;
    float volume = pi*pow(radius, 2)*height;
    printf("The surface area is: %.2f \n", surfaceArea);
    printf("The volume is: %.2f \n", volume);
    return 0;
}