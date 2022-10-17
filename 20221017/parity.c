
#include <stdio.h>
#include <stdbool.h>

bool is_even(int number);

int main(){
    int n;
    printf("What's n?\n");
    scanf("%d", &n);

    if (is_even(n)) {
        printf("%d is even\n", n);
    } else {
        printf("%d is odd\n", n);
    }
}

bool is_even(int number) {
    if(number%2 == 0) {
        return true;
    } else {
        return false;
    }
}