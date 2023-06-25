#include <stdio.h>

int main(void) {
  
  // num variable
  int num = 10;
  
  // ptr pointer variable
  int *ptr = NULL;

  // assigning the address of num to ptr
  ptr = &num;

  // printing the value of num - Output: 10
  printf("num: %d\n", num);
  printf("num via ptr: %d\n", *ptr);
 
  // updating the value of num via ptr
  printf("Updating value of num via ptr...\n");
  *ptr = 20;

  // printing the new value of num - Output: 20
  printf("num: %d\n", num);
  printf("num via ptr: %d\n", *ptr);

  return 0;
}