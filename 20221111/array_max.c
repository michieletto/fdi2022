#include <stdio.h>

#define NUM_ELEMS 9

int* get_max(int numbers[], int size) {  
    int *max_ptr = &numbers[0];
    printf("max_ptr-1: %p\n", max_ptr);
    printf("*max_ptr-1: %d\n", *max_ptr);
    for (int i = 0; i < size; i++)
    {
        if (numbers[i] >= (*max_ptr)) {
            max_ptr = &numbers[i];
            printf("max_ptr%d: %p\n", i, max_ptr);
            printf("*max_ptr%d: %d\n", i, *max_ptr);
        }
    }
    printf("max_ptr%d: %p\n", NUM_ELEMS, max_ptr);
    printf("*max_ptr%d: %d\n", NUM_ELEMS, *max_ptr);
    return max_ptr;
}

int main() {
    int numbers[NUM_ELEMS] = {0, 25, 6, 13, 9, 72, 44, 16, 33};

    int max = 42;
    int *number_max_ptr = NULL;

    if (number_max_ptr != NULL)  {
        printf("number_max_ptr(pre): %p\n", number_max_ptr);
        printf("*number_max_ptr(pre): %d\n", *number_max_ptr);
    } else {
        printf("number_max_ptr is still NULL!\n");
    }
    number_max_ptr = get_max(numbers, NUM_ELEMS);
    if (number_max_ptr != NULL)  {
        printf("number_max_ptr(post): %p\n", number_max_ptr);
        printf("*number_max_ptr(post): %d\n", *number_max_ptr);
    } else {
        printf("number_max_ptr is still NULL!\n");
    }
    
    printf("Max is %d\n", *number_max_ptr);

    return 0;
}