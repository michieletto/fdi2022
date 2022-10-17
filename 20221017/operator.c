
#include <stdio.h>
#include <stdbool.h>

int compute_switch(char op, int n1, int n2) {
    int res = 0;
    switch (op)
    {
    case '+':
        res = n1+n2;
        break;
    case '-':
        res = n1-n2;
        break;
    case '*':
        res = n1*n2;
        break;
    case '/':
        res = n1/n2;
        break;
    case '%':
        res = n1%n2;
        break;
    default:
        printf("Not supported operation\n");
        break;
    }
    
    return res;
}

int compute_if(char op, int n1, int n2) {
    if (op == '+') {
        return n1 + n2;
    }
    if (op == '-') {
        return n1 - n2;
    }
    if (op == '*') {
        return n1 * n2;
    }
    if (op == '/') {
        return n1 / n2;
    }
    if (op == '%') {
        return n1 % n2;
    }
    printf("Not supported operation\n");
    return 0;
}

int main(){
    char op;
    printf("What's the operator (+,-,*,/,%%)?\n");
    scanf("%c", &op);

    int a;
    int b;
    printf("What's a?\n");
    scanf("%d", &a);
    printf("What's b?\n");
    scanf("%d", &b);
    
    printf("(if)The result of the operation %d %c %d = %d\n", a, op, b, compute_if(op, a, b));
    printf("(switch)The result of the operation %d %c %d = %d\n", a, op, b, compute_switch(op, a, b));

    return 0;
}
