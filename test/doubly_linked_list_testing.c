#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include "doubly_linked_list.h"

void printCallback(int item) {
    printf("%d \n", item);
}
int main()
{
    DoublyLinkedList* list = create_DoublyLinkedList();
    insertAtBeginning_DoublyLinkedList(&list, 2);
    insertBefore_DoublyLinkedList(&list, &(list->head), 1);
    insertAfter_DoublyLinkedList(&list, &(list->tail), 3);
    traverseForward_DoublyLinkedList(&list, printCallback);
    return 0;

}