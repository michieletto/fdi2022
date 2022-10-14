#include <stdio.h>

void hello(char to[], char greetings[]){
    printf("%s, %s!\n", greetings, to);
}

int main() {
    char name[30];
    printf("What's your name? ");
    scanf("%s", name);
    hello(name, "Hello");

    return 0;
}

