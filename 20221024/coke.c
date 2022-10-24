#include <stdio.h>
#include <stdbool.h>

int main() {
    int to_pay = 50;
    int coin = 0;

    while (to_pay > 0)
    {
        printf("Importo dovuto: %d\n", to_pay);

        while(true) {
            printf("Inserisci una moneta: ");
            scanf("%d", &coin);
            if (coin == 25 || coin == 10 || coin == 5) {
                break;
            }
        }
        to_pay -= coin;
    }

    printf("Resto dovuto: %d\n", -to_pay);

    return 0;
}