#ifndef LINKEDLIST_H
#define LINKEDLIST_H

struct Node {
    int data;
    struct Node *next;
    struct Node *prev;
};

struct LinkedList {
    struct Node *head;
    struct Node *tail;
    int length;
};

// Function prototypes
struct Node* create_node(int data);
void linked_list_prepend(struct LinkedList *list, int data);
void linked_list_append(struct LinkedList *list, int data);
int linked_list_remove(struct LinkedList *list, int dataToRemove);
int linked_list_get(struct LinkedList *list, int idx);
struct Node *linked_list_get_node(struct LinkedList *list, int idx);
void linked_list_insert_at(struct LinkedList *list, int data, int idx);
int linked_list_remove_at(struct LinkedList *list, int idx);
struct LinkedList *create_randomised_list(int length);
void print_all_nodes(struct LinkedList *list);
int linear_search(struct LinkedList *list, int needle);

#endif
