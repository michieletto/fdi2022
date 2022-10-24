#include <stdio.h>

int main() {
    int i = 0;

    while(i < 3) {
        printf("meow\n");
        i = i+1;
        // Equivalente a:
        i += 1;
        i++;
        ++i;
        // Si puà fare la stessa cosa anche con le sottrazioni:
        i -= 1;
        i--;
        --i;
        // ma attenzione le operazione ++i e i++ presentano una differenza 
        // nell'ordine in cui sono eseguite le operazioni, ad esempio:
        int test = 5 + i++; // Prima somma tra 5 e i, poi incremento i
        int test2 = 5 + --i; // Prima incremento i, poi somma tra 5 e i
        // Questo significa che nonostante le operazioni test2 == test
    }

    return 0;
}