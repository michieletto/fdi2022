#include <stdio.h>
// This is a comment

/* 
Another comment, this comment is working 
for multiple lines
 */

int main() 
{
    int a = 1;
    int b = 2;
    int c;
    /*
    Other available types:
    unsigned int u;
    float f;
    double d; 
    */
    
    printf("What's \"a\"?\n");
    scanf("%d", &a);

    printf("What's \"b\"?\n");
    scanf("%d", &b);

    c = a + b;
    printf("c = %d\n", c);

    return 0;
}