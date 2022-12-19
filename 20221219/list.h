#ifndef __LIST_H__
#define __LIST_H__

#include <stdlib.h>
#include <stdio.h>

typedef struct Node
{
    int value;		    // dato
    struct Node *next;	// link
} Node;

void print_list(struct Node *head);

struct Node* new_node(int value);

void delete_list(struct Node* head);

struct Node* insert_head(struct Node* head, int value);

void insert_after(struct Node* prev, int value);

struct Node* insert_tail(struct Node * head, int value);

struct Node* insert_sorted(struct Node *head, int value);

struct Node* find_prev(struct Node *head, int value);

#endif // __LIST_H__