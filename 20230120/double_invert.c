#include "double_invert.h"

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
 * Aggiunge un nodo in testa alla lista
 * @param [in] head puntatore alla testa della lista
 * @param [in] value valore da inserire come dato nel nodo
 * @return puntatore alla nuova testa della lista
**/
struct Node* insert_head(struct Node* head, int value) {
    // Alloco un nuovo nodo da inserire nella lista
    struct Node* temp = new_node(value);
    // Collego il nodo attualmente in testa al nodo appena creato
    temp->next = head;
    // Restituisco l'indirizzo del nodo che ora è in testa alla lista
    return temp;
}

/**
 * Data una lista concatenata, aggiungere in coda una lista di
 * nuovi nodi in modo da raddoppiarne la lunghezza originale.
 * I nuovi nodi dovranno contenere gli stessi valori dei 
 * nodi originali, ma in ordine inverso. 
 * @param [inout] head puntatore alla testa della lista concatenata
 * La funzione dovrà gestire il caso di lista vuota.
**/
void double_invert(struct Node *head) {
    // Se la lista è vuota
    if (head == NULL)
        // Termino la funzione
        return;
    
    // Creo due puntatori di appoggio
    // Il primo alla nuova lista che creo
    struct Node *mirror_list = NULL;
    // Il secondo per tenere traccia dell'ultimo elemento della lista
    struct Node *last = NULL;

    // Finché il puntatore al nodo è diverso da NULL
    while (head != NULL)
    {
        // Inserisco un nuovo nodo all'inizio della nuova lista
        // che contiene il valore contenuto nel nodo corrente 
        // della lista in input
        mirror_list = insert_head(mirror_list, head->value);
        // Aggiorno last al nodo corrente
        last = head;
        // Mi sposto al nodo successivo con head
        head = head->next;
        // così quando head == NULL
        // last punta all'ultimo nodo della lista
    }

    // Aggancio la nuova lista in coda a quella in input
    last->next = mirror_list;
}