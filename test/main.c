#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "data_structures.h"

int main()
{
    DynamicArray *my_array = create_DynamicArray();
    append_DynamicArray(my_array, 1);
    append_DynamicArray(my_array, 2);
    append_DynamicArray(my_array, 3);
    append_DynamicArray(my_array, 4);
    append_DynamicArray(my_array, 5);
    append_DynamicArray(my_array, 6);
    append_DynamicArray(my_array, 7);
    append_DynamicArray(my_array, 8);
    append_DynamicArray(my_array, 9);
    for (size_t i = 0; i < my_array->size; i++) {
        printf("%d \n", *(my_array->items + i));
        
    }
    printf("capacity: %d \n", my_array->capacity);
    printf("size: %d \n", my_array->size);
    // List* list_1 = createList();
    // pushToList(&list_1, 9);
    // pushToList(&list_1, 8);
    // pushToList(&list_1, 7);
    // pushToList(&list_1, 6);
    // pushToList(&list_1, 5);
    // pushToList(&list_1, 4);
    // pushToList(&list_1, 3);
    // pushToList(&list_1, 2);
    // pushToList(&list_1, 1);
    // pushToList(&list_1, 0);
    // printList(list_1);
    // printf("\n");
    // deleteFromListByValue2(&list_1, 3);
    // printList(list_1);
    return 0;

}