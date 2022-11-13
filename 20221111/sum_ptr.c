#include <stdio.h>

int sum(int* a, int b) {
    printf("a2: %d\n", *a);
    *a +=  b;
    printf("a3: %d\n", *a);
    return *a;
}

int main() {
    int a = 5;
    int b = 37;

    printf("a1: %d\n", a);
    int c = sum(&a, b);
    printf("a4: %d\n", a);
    printf("c: %d\n", c);

    return 0;
}