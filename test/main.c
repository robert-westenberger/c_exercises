#include <limits.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include "data_structures.h"


/* 
3rd edition
Stacks, Queues, and Lists
3.4 Design a stack S that supports S.push(x), S.pop(), and S.findmin(), which
returns the minimum element of S. All operations should run in constant time.

This is also a problem on leetcode... 
https://leetcode.com/problems/min-stack/
*/

/*-----------------------------------------------------------------------*/

const int STACK_MAX_SIZE = 10000;
typedef struct MinStack {  
    int top;
    int maxsize;
    int minvalue;
    int* items;
} MinStack;

MinStack* minStackCreate() {
    MinStack* stack = (MinStack*)malloc(sizeof(MinStack));
    stack->maxsize = STACK_MAX_SIZE;
    stack->top = -1;
    stack->items = (int*)malloc(stack->maxsize * sizeof(int));
    stack->minvalue= INT_MAX;
    return stack;
}

int minStackIsFull(MinStack* stack)
{
    return stack->top == stack->maxsize - 1;
}

int minStackIsEmpty(MinStack* stack)
{
    return stack->top == -1;
}

void minStackPush(MinStack* obj, int val) {
  if (minStackIsFull(obj)) {
    return;
  }
  if (obj->minvalue > val) {
    obj->minvalue = val;
  }
  obj->top = obj->top+1; 
  obj->items[obj->top] = val;
}

void minStackPop(MinStack* obj) {
  if (minStackIsEmpty(obj)) {
    return;
  }    
  obj->top = obj-> top - 1;
}

int minStackTop(MinStack* obj) {
  return obj->items[obj->top];
}

int minStackGetMin(MinStack* obj) {
  return obj->minvalue;
}

void minStackFree(MinStack* obj) {
    free(obj);
}

int main()
{
    MinStack *minStack = minStackCreate();
    minStackPush(minStack, -2);
    minStackPush(minStack, 0);
    minStackPush(minStack, -3);
    minStackGetMin(minStack);
    printf("%d \n", minStackGetMin(minStack)); // -3
    __asm("nop");
    minStackPop(minStack);
    printf("%d \n", minStackTop(minStack)); // 0
    printf("%d \n", minStackGetMin(minStack)); // -2
    return 0;

}