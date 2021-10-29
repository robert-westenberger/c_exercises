#include <stdio.h>
#include <stdlib.h>
#include "helpers.h"

/* WIP */
/*
Let A[1..n] be an array of real numbers. Design an algorithm to perform any
sequence of the following operations:
• Add(i,y) – Add the value y to the ith number.
• Partial-sum(i) – Return the sum of the first i numbers, i.e., for 
  j=1 to i, add A[j]
There are no insertions or deletions; the only change is to the values of the numbers.
Each operation should take O(log n) steps. You may use one additional array of size
n as a work space.
*/

#define ARR_LENGTH 15

typedef struct Node
{
    int min;      // minimum index of A[] contained by a child
    int max;      // maximum index of A[] contained by a child
    double value; // sum of A[min..max]
    struct Node *left;
    struct Node *right;
} Node;

int main()
{
    double *real_numbers = generateArrayOfRandomDoubles_Helpers(ARR_LENGTH, 0, 100);
    Node *tree = NULL;
    for (int i = 0; i < ARR_LENGTH; i++)
    {
        printf("%f \n", *(real_numbers + i));
    }
    return 0;
}