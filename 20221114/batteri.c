// batteri_test.c
#include <stdio.h>

int main() {
    // inizializzare le variabili necessarie
    double n_esperiments = 0.0;
    double mean = 0.0;
    double value = 0.0;

    for(;;) 
    {
        for(;;)
        {
            // acquisire il valore di resistenza di un singolo esperimento da tastiera
            printf("Valore di resistenza:\n");
            scanf("%lf", &value);
            // se il valore inserito è valido (compreso tra 0 e 1 compresi)
            if (value<=1.0)
                break;
            // altrimenti inviare un messaggio d'errore e tornare a chiedere nuovamente il valore
            printf("Valore non valido!\n");
        }
        // continuare ad acquisire dati finché non viene inserito un valore negativo
        if (value<0.0)
            break;
        // calcolare la resistenza media del batterio dall'avvio del programma
        mean = (mean * n_esperiments + value) / (n_esperiments + 1.0);
        n_esperiments += 1.0;
        // stampare la media attuale a video    
        printf("Media attuale: %lf\n", mean);
    }
    // se l'intero test è valido (numero di esperimenti >= 10)
    if (n_esperiments>= 10.0) {
        // stampare un riepilogo con il totale di esperimenti e la media del valore di resistenza
        printf("\nRIEPILOGO:\n");
        printf("Numero totale di esperimenti: %d\n", (int)n_esperiments);
        printf("Media valore di resistenza: %lf\n", mean);
    } else {    
        // oppure dire allo scienzato che gli esperimenti non sono sufficienti
        printf("\nNumero di esperimenti non sufficienti\n");
    }
    // uscire dal programma
    return 0;
}