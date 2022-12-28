#ifndef __LIST_H__
#define __LIST_H__

#include <stdlib.h>
#include <stdio.h>

typedef struct Node
{
    int value;		    // dato
    struct Node *next;	// link
} Node;

// Visita di ogni nodo all'interno della lista
// per stampare il contenuto a schermo
void print_list(struct Node *head);

// Alloca un nuovo nodo da inserire nella lista usando la memoria dinamica
struct Node* new_node(int value);

// Cancella i nodi appartenenti alla lista
void delete_list(struct Node* head);

// Aggiunge un nodo in testa alla lista
struct Node* insert_head(struct Node* head, int value);

// Aggiunge un nodo dopo il nodo in input 
void insert_after(struct Node* prev, int value);

// Aggiunge un nodo in coda alla lista
struct Node* insert_tail(struct Node * head, int value);

// Inserisce un nodo mantenendo la lista ordinata
struct Node* insert_sorted(struct Node *head, int value);

// Cerca nella lista ordinata il nodo precedente al valore in input 
struct Node* find_prev(struct Node *head, int value);

#endif // __LIST_H__