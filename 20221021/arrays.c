#include <stdio.h>

#define NUM 3

int main() {
    int a[NUM] = {5, 6};

    for(int i=0; i<NUM; i++) {
        printf("Before, value at index %d is %d\n", i, a[i]);
        a[i] = i;
        printf("After, value at index %d is %d\n", i, a[i]);
    }


    return 0;
}