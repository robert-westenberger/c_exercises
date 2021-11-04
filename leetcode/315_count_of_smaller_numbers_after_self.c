#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <limits.h>
#include "sorting.h"

/* WIP */
/*
315. Count of Smaller Numbers After Self
https://leetcode.com/problems/count-of-smaller-numbers-after-self/
You are given an integer array nums and you have to return a new counts array. 
The counts array has the property where counts[i] is the number of smaller elements to the 
right of nums[i].
*/

// struct node
// {
//   int key;
//   struct node *left;
//   struct node *right;
//   int height;
//   int size; // size of the tree rooted with this node
// };

int *countSmaller(int *nums, int numsSize, int *returnSize)
{
    return nums;
}

int main()
{

    // int *myInts = generateArrayOfRandomInts_Helpers(10, 0, 100);
    int *myInts = malloc(sizeof(int) * 6);
    *myInts = 12;
    *(myInts + 1) = 11;
    *(myInts + 2) = 13;
    *(myInts + 3) = 5;
    *(myInts + 4) = 6;
    *(myInts + 5) = 7;
    mergeSort(myInts, 0, 6);
    // int *myInts2 = generateArrayOfRandomInts_Helpers(10, INT_MIN, INT_MAX);

    // int* returnSize = malloc(sizeof(int));
    // *returnSize = 10;
    // int* answer = countSmaller(myInts, 10, returnSize);
    // for (int i = 0; i < 10; i++)
    // {
    //   printf("ints: %d counts: %d \n", *(myInts + i) , *(answer + i));
    // }

    return 0;
}