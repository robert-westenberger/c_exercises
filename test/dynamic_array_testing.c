#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "data_structures.h"

void printCallback(int item) {
    printf("%d \n", item);
}

void test(DynamicArray *my_array, char message[]) {
    printf("START \n");
    printf("%s \n", message);
    printf("capacity %d \n", my_array->capacity);
    printf("size %d \n", my_array->size);
    printf("END \n");
    printf("\n");
}
int main()
{
    DynamicArray *my_array = create_DynamicArray();
    // test(my_array, "Just created array");
    // append_DynamicArray(my_array, 1);
    // test(my_array, "Just appended 1 to array");
    // append_DynamicArray(my_array, 2);
    // test(my_array, "Just appended 2 to array");
    // append_DynamicArray(my_array, 3);
    // test(my_array, "Just appended 3 to array");
    // append_DynamicArray(my_array, 4);
    // test(my_array, "Just appended 4 to array");
    // removeAtIndex_DynamicArray(my_array, 3);
    // test(my_array, "Just removed 4 from array");
    // removeAtIndex_DynamicArray(my_array, 2);
    // test(my_array, "Just removed 3 from array");
    // removeAtIndex2_DynamicArray(my_array, 1);
    // test(my_array, "Just removed 2 from array");
    // append_DynamicArray(my_array, 2);
    // test(my_array, "Just appended 2 to array");
    // append_DynamicArray(my_array, 2);
    // test(my_array, "Just appended 2 to array");
    // // append_DynamicArray(my_array, 5);
    // // append_DynamicArray(my_array, 6);
    // // append_DynamicArray(my_array, 7);
    // // append_DynamicArray(my_array, 8);
    // // append_DynamicArray(my_array, 9);
    // // prepend_DynamicArray(my_array, 0);
    // // removeAtIndex2_DynamicArray(my_array, 5);
    // // forEach_DynamicArray(my_array, &printCallback);
    // // printf("capacity %d \n", my_array->capacity);
    // // printf("size %d \n", my_array->size);
    return 0;

}