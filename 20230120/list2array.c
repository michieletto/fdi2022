#include "list2array.h"

/**
 * Copia la lista puntata da head nell'array preallocato output
 * @param [in] head puntatore alla lista che contiene i dati in input
 * @param [out] output array preallocato dove salvare i valori presenti nella lista
 * @return numero di elementi inseriti nell'array
 * La funzione deve essere implementata in maniera ricorsiva
**/
int list2array(struct Node* head, int *output) {
    // 1. Caso base: la lista è vuota
    // l'array non viene modificato e viene
    // ritornato 0 (nessun elemento inserito)
    if (head == NULL)
        return 0;

    // Ricorsione:
    // 2. Inserisco nel primo elemento dell'array
    // il valore dell'elemento in testa alla lista
    output[0] = head->value;
    // 3. Mi sposto al nodo successivo con head
    head = head->next;
    // 4. Mi sposto al prossimo elemento dell'array 
    // con output (vedere aritmetica dei puntatori)
    output++;
    // 5. Richiamo ricorsivamente la funzione in 
    // modo che copi la parte rimanente della lista
    // (che ora parte da un nodo successivo a quello di input)
    // nella parte rimanente dell'array output (che ora punta 
    // all'elemento successivo a quello fornito in input)
    // rispettando così i criteri della ricorsione
    int num_elem = list2array(head, output);

    // Il numero di elementi totale sarà pari al numero di 
    // elementi fornito dalla chiamata ricorsiva più 1, ciè
    // quello elaborato in 2. prima ricorsiva vera e propria
    return 1 + num_elem;
}