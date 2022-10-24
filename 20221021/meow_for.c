#include <stdio.h>
#include <stdbool.h>

int main() {
    int num_meow;
    while (1)
    {
        break;
    }

    for(;;){
        printf("How many \"meow\"? ");
        scanf("%d",&num_meow);
        if(num_meow>0)
            break;
    } 

    for(int i=0;i<num_meow;i++)
        printf("meow\n");

    return 0;
}