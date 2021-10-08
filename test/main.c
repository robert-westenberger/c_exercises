#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

/* 2ed 3.11 Suppose that we are given a sequence of n values x1, x2, ..., xn and seek to
quickly answer repeated queries of the form: given i and j, find the smallest value
in xi, . . . , xj .
(a) Design a data structure that uses O(n2) space and answers queries in O(1)
time.
(b) Design a data structure that uses O(n) space and answers queries in O(log n)
time. For partial credit, your data structure can use O(n log n) space and have
O(log n) query time. */

#define RAND_RANGE_MIN 0
#define RAND_RANGE_MAX 100
#define SEQUENCE_LENGTH 10

int randInRange(int min, int max) {
    return min + rand() % (max+1 - min);
}

/* creates range of random ints */
int* createRange(int n) {
    int *newArray = malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++) {
        newArray[i] = randInRange(RAND_RANGE_MIN, RAND_RANGE_MAX);
    }

    return newArray;
}
int findSmallestValueInRange() {
    
}
int** createLookupTable(int *n, int size) {
    int **lookupTable = (int **)malloc(size * sizeof(int *));
    int row;
    for (row = 0; row < size; row++) {
        lookupTable[row] = (int *)malloc(size * sizeof(int));
    }
    for (int i = 0; i < size; i++) { 
       for (int j = 0; j < size; j++) { 
           lookupTable[i][j] = n[i] + n[j];
        } 
    }
    return lookupTable;
}
int main()
{   
    srand(time(NULL));
    int *unsortedSequenceOfRandomNumbers = createRange(SEQUENCE_LENGTH);
    int **lookupTable = createLookupTable(unsortedSequenceOfRandomNumbers, SEQUENCE_LENGTH);
    for (int i = 0; i < SEQUENCE_LENGTH; i++) {
       printf("\n"); 
       for (int j = 0; j < SEQUENCE_LENGTH; j++) {
            if (lookupTable[i][j] < 10) {
                printf(" %d ", lookupTable[i][j]);
            } else {
                printf("%d ", lookupTable[i][j]);
            }
            
        } 
    }
    printf("\n");
    return 0;

}