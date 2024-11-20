#include <stdio.h>
#include <stdlib.h>

struct Tuple {
    int a;
    int *b;
};

struct Tuple find_closest_to_average(int the_array[], int num_elements) {
    int sum = 0;
    int average;
    int min_diff = 2147483647;  // maximum value for an int
    int *closest_element = NULL;

    for(int i = 0; i < num_elements; ++i) {
        sum += the_array[i];
    }
    
    average = sum / num_elements;
    
    for(int i = 0; i < num_elements; ++i) {
        int diff = abs(average - the_array[i]);
        if(diff < min_diff) {
            min_diff = diff;
            closest_element = &the_array[i];
        }
    }
    
    struct Tuple result = {average, closest_element};
    return result;
}

int main(void) {
    int the_array[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    struct Tuple result = find_closest_to_average(the_array, 9);
    printf("The average is: %d and the closest value is: %d with a pointer: %p\n", result.a, *result.b, result.b);
    return 0;
}
