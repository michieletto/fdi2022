#include "count_even.h"

/**
 * Conta il numero di elementi pari all'interno di una matrice quadrata di interi
 * @param [in] matrix matrice quadrata da esaminare
 * @param [in] size dimensione del lato della matrice
 * @return numero di elementi pari presenti nella matrice
**/
int count_even(int *matrix, int size) {
    // Imposto il contatore a zero
    int even = 0;
    // Per ogni riga e per ogni colonna
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            // Controllo se l'elemento è pari
            if (matrix[i*size+j] % 2 == 0)
                // e nel caso aumento il contatore
                even++;
        }
    }
    // Ritorno il conteggio finale
    return even;
}