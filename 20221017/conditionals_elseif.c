#include <stdio.h>

int main() {
    int a = 1;
    int b = 2;

    printf("what's 'a'? ");
    scanf("%d", &a);

    printf("what's 'b'? ");
    scanf("%d", &b);

    // Introducing else-if
    if (a < b) {
        printf(" a < b\n");
    } else if (a > b) {
        printf(" a > b\n");
    } else if (a == b) {
        printf(" a == b\n");
    }

    return 0;
}