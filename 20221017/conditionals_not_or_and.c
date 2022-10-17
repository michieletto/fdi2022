#include <stdio.h>

int main() {
    int a = 1;
    int b = 2;

    printf("what's 'a'? ");
    scanf("%d", &a);

    printf("what's 'b'? ");
    scanf("%d", &b);

    // Cascade of conditions
    if (!((a < b) || (a > b))) {
    // Equivalent condition
    // if (!(a < b) && !(a > b)) {
        printf(" a == b\n");
    } else {
        printf(" a != b\n");
    }

    return 0;
}