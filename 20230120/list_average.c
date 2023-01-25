#include "list_average.h"

/**
 * Alloca un nuovo nodo da inserire nella lista usando la memoria dinamica
 * @param [in] value valore da inserire come dato nel nodo
 * @return puntatore al nodo creato
**/
struct Node* new_node(int value) {
    // Allocazione dinamica del nodo
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    // Se l'allocazione è andata a buon fine
    if (node != NULL) {      // Imposto
        node->value = value; // valore
        node->next = NULL;   // e link
    }
    return node;
}

/**
 * Aggiunge un nodo dopo il nodo in input 
 * @param [in] prev puntatore al nodo precedente nella lista
 * @param [in] value valore da inserire come dato nel nodo
 * @return puntatore all'ultimo nodo creato nella lista
 * rispetto al codice visto il 19/12/2022 se il nodo in input è NULL
 * restituisco il puntatore al nuovo nodo dopo averlo creato
**/
struct Node* insert_after(struct Node* prev, int value) {
    // Alloco un nuovo nodo da inserire nella lista
    struct Node* temp = new_node(value);
    // Se il nodo in input non è NULL
    if (prev != NULL) {
        // Collego il nodo che al momento segue prev al nodo 
        // appena creato per accedere al resto della lista 
        temp->next = prev->next;  // opzionale per lo specifico problema
        // Collego il nodo creato in modo che lo segua nella lista
        prev->next = temp;        // obbligatorio per l'algoritmo funzioni
    }
    // restituisco il puntatore al nodo creato
    return temp;
}


/**
 * Calcola la media dei valori contenuti nella lista in input
 * @param [in] head puntatore alla lista che contiene i dati in input
 * @return media dei valori contenuti nella lista in input
 * se la lista è vuota tornare 0.0f
**/
float get_list_average(struct Node* head) {
    // Se la lista è vuota 
    if (head == NULL)
        // Ritorno 0.0f
        return 0.0f;

    // Creo una variabile che contenga la somma dei
    // valori contenuti nei nodi della lista
    float sum = 0.0f;
    // e una seconda variabile per contare il numero di nodi
    int count = 0;

    // Finché il puntatore al nodo è diverso da NULL
    while (head != NULL)
    {
        // Aggiungo alla somma il valore del nodo corrente
        sum += head->value;
        // Incremento il numero di nodi
        count++;
        // Mi sposto al nodo successivo con head
        head = head->next;
    }   

    // Ritorno la media come somma dei valori diviso numero di nodi
    return sum/count;
}

/**
 * Crea una nuova lista composta dai nodi della lista in input 
 * il cui valore supera la media della valori contenuti nella lista 
 * @param [in] head puntatore alla lista che contiene i dati in input
 * @return puntatore alla lista creata dinamicamente composta 
 * dalla copia dei nodi il cui valore supera la media della lista
 * se la lista è vuota ritornare NULL
 * mantenere l'ordine dei nodi della lista originale
**/
struct Node* list_average(struct Node *head) {
    // Calcolo la media dei valori nella lista    
    float average = get_list_average(head);
    // Creo un puntatore ad una nuova lista
    struct Node *new_list = NULL;
    // e uso un secondo puntatore per tenere traccia dell'ultimo nodo 
    // ed inserire i nuovi valori in coda
    struct Node *last = NULL;
    // Uso questo printf per verificare che la media sia corretta
    // commentandolo per il check tramite ./self_evaluation
    // printf("Average = %f\n", average);

    // Finché il puntatore al nodo è diverso da NULL
    while (head != NULL)
    {
        // Se il valore del nodo corrente è maggiore della media
        if (head->value > average){
            // Uso questo printf per verificare che il valore sia quello
            // che mi aspetto e sia effettivamente superiore alla media
            // commentandolo per il check tramite ./self_evaluation
            // printf("%d > %g -> NEW NODE\n", head->value, average);
            // Inserisco dopo l'ultimo elemento e aggiorno last
            last = insert_after(last, head->value);
            // Nel caso in cui non ci sia ancora un riferimento 
            // alla testa della nuova lista, copio in valore di 
            // last che dopo il primo inserimento punta all'unico
            // elemento presente nella lista, che è anche la testa
            if (new_list == NULL)
                new_list = last;
        }
        // Mi sposto al nodo successivo con head
        head = head->next;
    }
    
    // Ritorno il puntatore alla testa della nuova lista
    return new_list;
}