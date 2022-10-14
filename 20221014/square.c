#include <stdio.h>

// Compute the square of a number
int square(int n) {
    return n*n;
}

// Get the input from the user
int main() {
    int n;
    scanf("%d", &n);
    printf("The square of %d, is %d\n", n , square(n));
}
