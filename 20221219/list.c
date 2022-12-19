#include "list.h"
#include <stdlib.h>
#include <stdio.h>

void print_list(struct Node *head) {
    while (head != NULL) {
        printf("%d -> ", head->value);
        head = head->next;
    }
    printf("NULL\n");
}

struct Node* new_node(int value) {
    struct Node* node = malloc(sizeof(node));
    if (node != NULL) {
        node->value = value;
        node->next = NULL;
    }
    return node;
}

void delete_list(struct Node *head) {
    struct Node *current = NULL;
    while (head != NULL) {
        current = head;
        head = head->next;
        free(current);
    }
}

struct Node* insert_head(struct Node* head, int value) {
    struct Node* temp = new_node(value);
    
    temp->next = head;

    return temp;
}

struct Node* insert_tail(struct Node * head, int value) {
    if (head == NULL)
        return insert_head(head, value);

    struct Node *current  = head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = new_node(value);
    
    return head;
}

void insert_after(struct Node* prev, int value) {
    if (prev == NULL)
        return;

    struct Node* temp = new_node(value);
    temp->next = prev->next;
    prev->next = temp;
}

struct Node* find_prev(struct Node *head, int value) {
    struct Node *prev = head;

    if ((prev == NULL) || (prev->value >= value))
        return NULL;

    while ((prev->next != NULL) && (prev->next->value < value)) {
        prev = prev->next;
    }

    return prev;
}

struct Node* insert_sorted(struct Node *head, int value) {
    struct Node* prev = find_prev(head, value);
    
    if (prev == NULL) {
        head = insert_head(head, value);
    } else {
        insert_after(prev, value);
    }

    return head;
}