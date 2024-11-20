#include <stdio.h>

int main(){
    char firstName[20];
    char lastName[20];
    printf("Enter your first name: \n");
    scanf("%s", firstName);
    printf("Enter your last name: \n");
    scanf("%s", lastName);
    printf("%c%c\n",firstName[0],lastName[0]);
    return 0;
}