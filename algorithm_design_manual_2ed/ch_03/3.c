#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "data_structures.h"


/* 
Stacks, Queues, and Lists
3.3 We have seen how dynamic arrays enable arrays to grow while still achieving
constant-time amortized performance. This problem concerns extending dynamic
arrays to let them both grow and shrink on demand.
(a) Consider an underflow strategy that cuts the array size in half whenever the
array falls below half full. Give an example sequence of insertions and deletions
where this strategy gives a bad amortized cost.
(b) Then, give a better underflow strategy than that suggested above, one that
achieves constant amortized cost per deletion.
*/

int main()
{
    DynamicArray *my_array = create_DynamicArray();
    append_DynamicArray(my_array, 5);
    append_DynamicArray(my_array, 6);
    return 0;

}