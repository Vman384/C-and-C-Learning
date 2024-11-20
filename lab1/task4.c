#include <stdio.h>
#include <math.h>

double division(int x, int y);

int main(void){
    int x;
    int y;

    printf("Enter 2 numbers: \n");
    printf("Number 1: \n");
    scanf("%d",&x);
    printf("Number 2: \n");
    scanf("%d",&y);
 

    printf("Addition: %d\n",addition(x,y));
    printf("Subtraction: %d\n",subtraction(x,y));
    printf("Multiplication: %d\n",multiplication(x,y));
    printf("Division: %f\n", division(x, y));



    
    return 0;
}

int addition(int x, int y){
    int result = x+y;
    return result;
}


int subtraction(int x, int y){
    return x-y;
}


int multiplication(int x, int y){
    int result = x*y;
    return result;
}


double division(int x, int y){
    return (double) x/y;
}