#include <stdio.h>

int sum(int* a, int b) {
    printf("a2: %d\n", *a);
    *a +=  b;
    printf("a3: %d\n", *a);
    return *a;
}

int main() {
    int *a_ptr = NULL;
    int a = 5;
    int b = 37;

    a_ptr = &a;

    printf("a1: %d\n", a);
    printf("&a1: %p\n", &a);
    printf("a_ptr1: %p\n", a_ptr);
    printf("*a_ptr1: %d\n", *a_ptr);
    printf("&*a_ptr1: %p\n", &(*a_ptr));
    int c = sum(a_ptr, b);
    printf("a4: %d\n", a);
    printf("&a2: %p\n", &a);
    printf("a_ptr2: %p\n", a_ptr);
    printf("*a_ptr2: %d\n", *a_ptr);
    printf("&*a_ptr2: %p\n", &(*a_ptr));
    printf("c: %d\n", c);

    return 0;
}