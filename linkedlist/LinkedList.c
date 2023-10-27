#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "LinkedList.h"

struct Node* create_node(int data)
{
    struct Node *node = malloc(sizeof(struct Node));
    node->data = data;

    return node;
}

/**
 * Prepends a node with the given data to the linked list.
 *
 * This function adds a new node with the specified data to the beginning of the linked list.
 * If the list is empty, it creates the node and makes it both the head and the tail.
 *
 * @param list - A pointer to the linked list structure.
 * @param data - The data to be added to the new node.
 */
void linked_list_prepend(struct LinkedList *list, int data)
{
    struct Node *node = create_node(data);
    list->length ++;

    if (list->head == NULL) {
        list->head = list->tail = node;
        return;
    }

    node->next = list->head;
    list->head->prev = node;
    list->head = node;
}

/**
 * Appends a node with the given data to the linked list.
 *
 * This function adds a new node with the specified data to the end of the linked list.
 * If the list is empty, it creates the node and makes it both the head and the tail.
 *
 * @param list - A pointer to the linked list structure.
 * @param data - The data to be added to the new node.
 */
void linked_list_append(struct LinkedList *list, int data)
{
    struct Node *node = create_node(data);
    list->length ++;

    if (list->head == NULL)
    {
        list->head = list->tail = node;
        return;
    }

    node->prev = list->tail;
    list->tail->next = node;
    list->tail = node;
}

/**
 * Removes a node with the specified data from the linked list.
 *
 * This function removes the first occurrence of a node with the specified data from the list.
 * It updates the list structure and returns the removed data.
 *
 * @param list - A pointer to the linked list structure.
 * @param dataToRemove - The data to be removed from the list.
 * @return The data of the removed node or -1 if not found.
 */
int linked_list_remove(struct LinkedList *list, int dataToRemove)
{
    struct Node *currentNode = list->head;

    for (size_t i = 0; currentNode != NULL && i <= list->length; ++i)
    {
        if (currentNode->data == dataToRemove)
        {
            break;
        }
        currentNode = currentNode->next;
    }
    if (currentNode == NULL)
    {
        return -1;
    }

    list->length --;

    if (list->length == 0)
    {
        int removedData = list->head->data;
        free(list);
        return removedData;
    }

    if (currentNode->prev != NULL)
    {
        currentNode->prev->next = currentNode->next;
    }
    if (currentNode->next)
    {
        currentNode->next->prev = currentNode->prev;
    }

    if (currentNode == list->head)
    {
        list->head = currentNode->next;
    }
    if (currentNode == list->tail)
    {
        list->tail = currentNode->prev;
    }

    int removedData = currentNode->data;
    free(currentNode);

    return removedData;
}

/**
 * Retrieves data at the specified index in the linked list.
 *
 * This function returns the data at the specified index in the linked list.
 *
 * @param list - A pointer to the linked list structure.
 * @param idx - The index of the data to retrieve (0-based).
 * @return The data at the specified index or -1 if out of bounds.
 */
int linked_list_get(struct LinkedList *list, int idx)
{
    if (idx >= list->length)
    {
        return -1;
    }

    struct Node *currentElement = list->head;
    for (size_t i = 0; i < idx; i++)
    {
        currentElement = currentElement->next;
    }

    return currentElement->data;    
}

/**
 * Retrieves a pointer to the node at the specified index in the linked list.
 *
 * This function returns a pointer to the node at the specified index in the linked list.
 *
 * @param list - A pointer to the linked list structure.
 * @param idx - The index of the node to retrieve (0-based).
 * @return A pointer to the specified node or NULL if out of bounds.
 */
struct Node *linked_list_get_node(struct LinkedList *list, int idx)
{
    if (idx > list->length)
    {
        return NULL;
    } else if (idx == list->length) {
        return list->head;
    } else if (idx == list->length) {
        return list->tail;
    }

    struct Node *currentNode = list->head;
    for (size_t i = 0; i < idx; ++i)
    {
        currentNode = currentNode->next;
    }
    return currentNode;
}

/**
 * Inserts a new node with the given data at the specified index in the linked list.
 *
 * This function inserts a new node with the specified data at the specified index in the linked list.
 * If the index is out of bounds, it does nothing.
 *
 * @param list - A pointer to the linked list structure.
 * @param data - The data to be added to the new node.
 * @param idx - The index at which to insert the new node (0-based).
 */
void linked_list_insert_at(struct LinkedList *list, int data, int idx)
{
    if (idx > list->length)
    {
        return;
    } else if (idx == list->length) {
        linked_list_append(list, data);
        return;
    } else if (idx == 0) {
        linked_list_prepend(list, data);
        return;
    }
    struct Node *currentElement = linked_list_get_node(list, idx);
    struct Node *node = create_node(data);
    list->length ++;
    
    node->prev = currentElement->prev;
    node->next = currentElement;
    currentElement->prev->next = node;
    currentElement->prev = node;
}

/**
 * Removes a node at the specified index from the linked list.
 *
 * This function allows you to remove a node at a specific index in the linked list.
 * If the index is out of bounds or the list is empty, it returns -1 as an error code.
 *
 * @param list - A pointer to the linked list structure.
 * @param idx - The index of the node to remove.
 *
 * @return The data of the removed node on success, or -1 on error.
 */
int linked_list_remove_at(struct LinkedList *list, int idx)
{
    if (list->head == NULL || idx < 0 || idx >= list->length) {
        return -1;
    }
    if (idx == 0 && list->length == 1) {
        int removedData = list->head->data;
        free(list);
        return removedData;
    } else if (idx == 0) {
        struct Node *oldHead = list->head;
        list->head = list->head->next;
        int removedData = oldHead->data;

        list->length--;
        free(oldHead);
        return removedData;
    } else if (idx == (list->length - 1)) {
        struct Node *oldTail = list->tail;
        list->tail = list->tail->prev;
        int removedData = oldTail->data;

        list->length--;
        free(oldTail);
        return removedData;
    }

    struct Node *nodeToRemove = linked_list_get_node(list, idx);
    int removedData = nodeToRemove->data;
    nodeToRemove->next->prev = nodeToRemove->prev;
    nodeToRemove->prev->next = nodeToRemove->next;
    free(nodeToRemove);

    return removedData;
}

void print_all_nodes(struct LinkedList *list) {
    struct Node *currentElement = list->head;
    printf("Printing full list. Length is %d \n", list->length);
    for (size_t i = 0; i < list->length; ++i) {
        printf("Index: %zu - ", i);
        printf("Data: %d \n", currentElement->data);
        currentElement = currentElement->next;
    }
}

int linear_search(struct LinkedList *list, int needle) {
    struct Node *currentNode = list->head;

    for (size_t i = 0; i < list->length; ++i) {
        if (currentNode->data == needle) {
            return 1;
        }
        currentNode = currentNode->next;
    }
    return 0;
}

struct LinkedList *create_randomised_list(int length) {
    srand(time(NULL));

    struct LinkedList *list = malloc(sizeof(struct LinkedList));

    for (size_t i = 0; i < length; ++i) {
        int r = rand() % 100;
        linked_list_append(list, r);
    }
    
    return list;
}