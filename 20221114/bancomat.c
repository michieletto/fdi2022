// bancomat_test.c
#include <stdio.h>

#define NUM_TAGLI 6 

int main() {
    // inizializzare il saldo disponibile del conto corrente a 2000
    int saldo = 2000;
    int prelievo;
    int tagli[NUM_TAGLI] = {5, 10, 20, 50, 100, 500};
    
    // chiedere all’utente quale somma vuole prelevare
    printf("Quanto prelevi?\n");
    // aspettare l’input da parte dell’utente
    scanf("%d", &prelievo);

    // se la somma di prelievo `e minore o uguale al saldo attualmente disponibile
    if(prelievo <= saldo) {
        // restituire la cifra richiesta usando il numero minimo di banconote 
        printf("Banconote restituite:\n");
        // partendo dalla banconota di taglio più grande
        for(int i=NUM_TAGLI-1; i>=0; i--) {
            // verifico se può essere usata per il prelievo
            while(prelievo>=tagli[i]) {
                // visualizzo il valore della banconota
                printf("%d\n", tagli[i]);
                // sottraggo il valore della bancono alla somma da prelevare
                prelievo -= tagli[i];
                // faccio la stessa operazione con il saldo in conto
                saldo -= tagli[i];
            }
        }
    } else {
        // oppure dire all’utente che non è possibile concludere l’operazione
        printf("Saldo troppo basso\n");
    }
    // aggiornare l'utente con il saldo disponibile
    printf("Saldo disponibile: %d\n", saldo);

    // uscire dal programma
    return 0;    
}