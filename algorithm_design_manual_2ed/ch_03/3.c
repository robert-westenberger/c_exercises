#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "data_structures.h"


/* 
Stacks, Queues, and Lists
3.3 Give an algorithm to reverse the direction of a given singly linked list. In
other words, after the reversal all pointers should now point backwards. Your
algorithm should take linear time.
*/
/* Iterative version. */
/* 
1. Initialize three pointers. prev and next are both NULL, while
current is the pointer to the first item in the list (the head). 
2. Iterate through the list. For every iteration do:
    a. Store next node 
    b. Change the next node to be instead the previous node
    c. Set previous as current for the next iteration.
    d. Set current to next for the next iteration.
3. Set the new head of the list to be the element that was formerly last 
in the list.
*/
void reverseSinglyLinkedList(List** list) {

    Node *previous = NULL, *next = NULL, *current = (*list)->head;
 
    while (current != NULL) {
        next = current->next;
        current->next = previous;
        previous = current;
        current = next;
    }
    (*list)->head = previous;
}

/* Recursive Version */
/* 
1. Divide list into two parts, first node and rest of list 
2. Call reverse for the rest of the linked list.
3. Link rest of the list to the first of the list
4. Fix head pointer
*/
Node *reverseSinglyLinkedListRecursive(Node** node) {
    Node *next = (*node)->next;
    if (next == NULL) {
        return *node;
    }
    Node *rest = reverseSinglyLinkedListRecursive(&next);
    (*node)->next->next = *node;
    (*node)->next = NULL;
    return rest;
}
void reverseSinglyLinkedListRecursiveEntry(List** list) {
    Node *head = (*list)->head;
    if (head != NULL) {
        (*list)->head = reverseSinglyLinkedListRecursive(&head);
    }
}
int main()
{
    List* list_1 = createList();
    pushToList(&list_1, 9);
    pushToList(&list_1, 8);
    pushToList(&list_1, 7);
    pushToList(&list_1, 6);
    pushToList(&list_1, 5);
    pushToList(&list_1, 4);
    pushToList(&list_1, 3);
    pushToList(&list_1, 2);
    pushToList(&list_1, 1);
    pushToList(&list_1, 0);
    printList(list_1);
    reverseSinglyLinkedListRecursiveEntry(&list_1);
    printf("\n");
    printList(list_1);
    return 0;

}