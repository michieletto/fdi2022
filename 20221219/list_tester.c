#include "list.h"

void test_base() {
    struct Node *n1 = new_node(10);
    struct Node *n2 = new_node(17);
    struct Node *n3 = new_node(25);

    if ((n1 != NULL) && (n2 != NULL) && (n3 != NULL)) {

        n1->next = n2;
        n2->next = n3;
        n3->next = NULL;

        print_list(n1);

        delete_list(n1);
        n1 = NULL;
    }
}

void test_insert() {
    struct Node *head = NULL;
    head = insert_head(head, 25);
    head = insert_head(head, 17);
    head = insert_head(head, 10);

    print_list(head);

    delete_list(head);
}

void test_sort() {
    struct Node *head = NULL;

    head = insert_head(head, 37);

    head = insert_sorted(head, 10);
    head = insert_sorted(head, 172);
    head = insert_sorted(head, 2);
    head = insert_sorted(head, 18);
    head = insert_sorted(head, 55);

    head = insert_tail(head, 329);

    print_list(head);
}

int main() {
    test_base();

    test_insert();
   
    test_sort();

    return 0;
}