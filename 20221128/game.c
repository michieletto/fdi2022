#include <stdio.h>
#include <stdlib.h>

#define SEED 42
#define MIN_N 1
#define MAX_N 100

/* Genera un numero tra 0 e n */
int get_random(int n) {
    // Inizializzare il seed pseudo-random per mantenere la ripetibilità
    srand(SEED);
    // Generare un numero tra 0 e n
    return (rand() % (n+1));
}

int main() {
    int level = 0;
    // Chiedere all'utente il livello di gioco (tra MIN_N e MAX_N)
    for(;;) {
        printf("Level: \n");
        scanf("%d", &level);
        if ((level >= MIN_N) && (level <= MAX_N))
            break;
    }

    // Generare un numero tra 0 e n
    int r = get_random(level);
    int guess = 0;

    // Chiedere all'utente l'ipotesi di numero
    for(;;) {
        printf("Guess: \n");
        scanf("%d", &guess);
    
        // se l'ipotesi è corretta
        if (guess == r) {
            printf("Just right!\n");
            break;
        } else if (guess > r) {
            // invece se l'ipotesi è maggiore del numero generato
            printf("Too large!\n");
        } else {
            // oppure se l'ipotesi è minore del numero generato
            printf("Too small!\n");
        }
    }

    return 0;
}   