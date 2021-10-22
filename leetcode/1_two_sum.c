#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "uthash.h"

/*
Given an array of integers nums and an integer target, return indices of the two numbers 
such that they add up to target.

You may assume that each input would have exactly one solution, and you may not use the 
same element twice.

You can return the answer in any order.

A naive soln would be a nested for loop
*/

struct hash_struct
{
    int id;
    int index;
    UT_hash_handle hh;
};
void addToMap(struct hash_struct **map, int key, int value)
{
    struct hash_struct *item = malloc(sizeof(struct hash_struct));
    item->id = key;
    item->index = value;
    HASH_ADD_INT(*map, id, item);
}
bool mapContains(struct hash_struct **map, int key)
{
    struct hash_struct *found_item;
    HASH_FIND_INT(*map, &key, found_item);
    return !(found_item == NULL);
}
int mapGet(struct hash_struct **map, int key)
{
    struct hash_struct *found_item;
    HASH_FIND_INT(*map, &key, found_item);
    return found_item->index;
}
/*
Optimal solution 1
Use hash map to store array elements, using the element as 
a key and its index as the value. Then, for each element in the array, subtract it from the 
target value and check if it exists in the hash map. If it does, return the current index
and the index stored in the hashmap.
*/
int *twoSumHash(int *nums, int numsSize, int target, int *returnSize)
{
    struct hash_struct *array_items = NULL;
    int *returnValue = malloc(sizeof(int) * 2);
    *returnSize = 2;
    int ans = 0;
    for (int i = 0; i < numsSize; i++)
    {
        int num = *(nums + i);
        int difference = target - num;

        if (mapContains(&array_items, difference))
        {
            *returnValue = mapGet(&array_items, difference);
            *(returnValue + 1) = i;
        }
        else
        {
            addToMap(&array_items, num, i);
        }
    }
    return returnValue;
}
void sort(int n, int *ptr)
{
    int i, j, t;

    // Sort the numbers using pointers
    for (i = 0; i < n; i++)
    {

        for (j = i + 1; j < n; j++)
        {

            if (*(ptr + j) < *(ptr + i))
            {

                t = *(ptr + i);
                *(ptr + i) = *(ptr + j);
                *(ptr + j) = t;
            }
        }
    }
}
/*
Optimal Solution 2 
*/
int *twoSumDoublePointer(int *nums, int numsSize, int target, int *returnSize)
{
    int leftIndex = 0;
    int rightIndex = numsSize - 1;
    int *returnValue = malloc(sizeof(int) * 2);
    *returnSize = 2;
    sort(numsSize, nums);
    while (leftIndex < rightIndex)
    {
        if (*(nums + leftIndex) + *(nums + rightIndex) == target)
        {
            *returnValue = *(nums + leftIndex);
            *(returnValue + 1) = *(nums + rightIndex);
            return returnValue;
        }
        else if (*(nums + leftIndex) + *(nums + rightIndex) < target)
        {
            leftIndex = leftIndex + 1;
        }
        else
        {
            rightIndex = rightIndex - 1;
        }
    }

    return returnValue;
}
int *twoSum(int *nums, int numsSize, int target, int *returnSize)
{
    return twoSumDoublePointer(nums, numsSize, target, returnSize);
}

int main()
{

    int *ints = malloc(sizeof(int) * 4);
    *ints = 3;
    *(ints + 1) = 2;
    *(ints + 2) = 4;

    int returnSize = 0;
    int *answer = twoSum(ints, 3, 6, &returnSize);

    return 0;
}