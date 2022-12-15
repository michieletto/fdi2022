#include <stdio.h>
#include <stdbool.h>

void print_array(int v[], int size) {
    printf("[");
    for (int i = 0; i < size; i++) {
        printf(" %d", v[i]);
    }
    printf(" ]\n");
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bubble_sort(int v[], int size) {
    // gli step di evoluzione vanno dal primo al penultimo elemento
    for (int step = 0; step < size - 1; step++) {
        bool swapped = false;                // tengo traccia degli scambi effettuati
        // scorro current dal primo all'ultimo elemento non ordinato
        for (int current = 0; current < size - step - 1; current++) {
            int next = current + 1;          // calcolo il valore di next
            if (v[current] > v[next]) {      // confronto i due elementi
                swap(&v[current], &v[next]); // se non sono in ordine, li scambio
                swapped = true;              // scambio effettuato
            }
        }
        if (!swapped)                        // se non sono stati effettuati scambi
            return;                          // termino la procedura
    }
}



int main(void) {
    int v[] = {25, 14, 12, 5, 37, 29, 10, 7, 20, 17};
    int size = sizeof(v) / sizeof(v[0]);
    printf("===============================================\n");
    printf("               BUBBLE SORT\n");
    printf("===============================================\n");

    printf("Pre-order: ");
    print_array(v, size);

    bubble_sort(v, size);

    printf("Post-order:");
    print_array(v, size);

    return 0;
}