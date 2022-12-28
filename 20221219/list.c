#include "list.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * Visita di ogni nodo all'interno della lista
 * per stampare il contenuto a schermo
 * @param [in] head puntatore alla testa della lista
*/
void print_list(struct Node *head) {
    // Finché il puntatore al nodo è diverso da NULL
    while (head != NULL) {
        // Stampo a schermo il contenuto del nodo
        printf("%d -> ", head->value);
        // e mi sposto al nodo successivo
        head = head->next;
    }
    // Stampo a schermo che sono arrivato alla fine della lista
    printf("NULL\n");
}

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
 * Cancella i nodi appartenenti alla lista 
 * per liberare la memoria allocata
 * @param [in] head puntatore alla testa della lista
**/
void delete_list(struct Node *head) {
    // Puntatore per tenere traccia del nodo da cancellare
    struct Node *current = NULL;
    // Finché il puntatore al nodo è diverso da NULL
    while (head != NULL) {
        // Copio l'indirizzo del nodo da cancellare
        current = head;
        // Avanzo al nodo successivo
        head = head->next;
        // Cancello il nodo
        free(current);
    }
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
 * Aggiunge un nodo dopo il nodo in input 
 * @param [in] prev puntatore al nodo precedente nella lista
 * @param [in] value valore da inserire come dato nel nodo
 * se il nodo in input è NULL, esce senza fare operazioni
**/
void insert_after(struct Node* prev, int value) {
    // Se il nodo in input è NULL, esco senza fare operazioni
    if (prev == NULL)
        return;
    // Alloco un nuovo nodo da inserire nella lista
    struct Node* temp = new_node(value);
    // Collego il nodo che al momento segue prev al nodo 
    // appena creato per accedere al resto della lista 
    temp->next = prev->next;
    // Collego il nodo creato in modo che lo segua nella lista
    prev->next = temp;
}

/**
 * Aggiunge un nodo in coda alla lista
 * @param [in] head puntatore alla testa della lista
 * @param [in] value valore da inserire come dato nel nodo
 * @return puntatore alla nuova testa della lista
**/
struct Node* insert_tail(struct Node * head, int value) {
    // Se la lista è vuota, equivale ad un inserimento in testa
    if (head == NULL)
        return insert_head(head, value);

    // Altrimenti cerco l'ultimo nodo
    struct Node *last  = head;
    // cioè il nodo il cui next è NULL
    while (last->next != NULL) {
        // visitando la lista fino a trovarlo
        last = last->next;
    }
    // inserisco dopo last
    insert_after(last, value);
    // Restituisco il puntatore al primo elemento della lista
    return head;
}

/**
 * Cerca nella lista ordinata il nodo precedente al valore in input 
 * @param [in] head puntatore alla testa della lista ordinata 
 * @param [in] value valore da inserire nella lista ordinata
 * @return puntatore al nodo precedente al valore cercato
 * se non c'è un nodo precedente al valore in input restituisce NULL
**/
struct Node* find_prev(struct Node *head, int value) {
    struct Node *prev = head;
    // Se la lista è vuota o il valore cercato è minore 
    // del valore contenuto nel nodo di testa, ritorno NULL
    if ((prev == NULL) || (prev->value >= value))
        return NULL;
    // Altrimenti visito la lista fino all'ultimo nodo o al 
    // nodo che contiene un valore maggiore di quello in input
    while ((prev->next != NULL) && (prev->next->value < value)) {
        prev = prev->next;
    }
    // Restituisco il puntatore al nodo trovato (o a NULL)
    return prev;
}

/**
 * Inserisce un nodo mantenendo la lista ordinata
 * @param [in] head puntatore alla testa della lista ordinata 
 * @param [in] value valore da inserire nella lista ordinata
 * @return puntatore alla nuova testa della lista ordinata
**/
struct Node* insert_sorted(struct Node *head, int value) {
    // Cerco il nodo che precede il valore da inserire
    struct Node* prev = find_prev(head, value);
    // Come prima, ci sono 2 casi
    if (prev == NULL) { // inserimento in testa
        head = insert_head(head, value);
    } else {            // inserimento dopo il nodo prev
        insert_after(prev, value);
    }
    // Restituisco il puntatore al primo elemento della lista
    return head;
}