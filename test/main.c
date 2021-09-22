#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "data_structures.h"

void printCallback(int item) {
    printf("%d \n", item);
}
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
    prepend_DynamicArray(my_array, 0);
    forEach_DynamicArray(my_array, &printCallback);
    printf("capacity %d \n", my_array->capacity);
    printf("size %d \n", my_array->size);
    return 0;

}