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

/* When pushing to the stack, in the case of the new 
value being smaller than the current minvalue, the value pushed
onto the stack will be (2 * value - minvalue).

(2 * value - minvalue) will always be less than value, because 
val < minvalue .. which means 
val - minvalue < 0

Adding value to both sides gives us
value + value - minvalue < 0 + value
2value - minvalue < value
*/
void minStackPush(MinStack* obj, int val) {
  if (minStackIsFull(obj)) {
    return;
  }
  obj->top = obj->top+1;
  if (minStackIsEmpty(obj)) {
    obj->items[obj->top] = val;
    obj->minvalue = val;
    return;
  }
  if (obj->minvalue > val) {
    obj->items[obj->top] = (2 * val - obj->minvalue);
    obj->minvalue = val;
    return;
  }
  obj->items[obj->top] = val;
}

/* When popping from the stack, if we are popping the smallest element,
update the new min value to be that of 2currentmin - poppedvalue. 

new min = previous min 

new min = 2currentmin - poppedvalue

// popped value was inserted as 2x - previousmin, where previousmin
// was the min before popped value was inserted)
popped value = 2x - previousmin 

// from above equation.  
currentmin=x

new min = 2currentmin - popped value
        = 2x - (2x - previousmin)
        = previous min
*/
void minStackPop(MinStack* obj) {
  if (minStackIsEmpty(obj)) {
    return;
  }
  int poppedvalue = obj->items[obj->top];
  obj->top = obj-> top - 1;
  if (poppedvalue < obj->minvalue) {
    obj->minvalue = (2 * obj->minvalue - poppedvalue);
  } 
}

int minStackTop(MinStack* obj) {
  if (obj->items[obj->top] < obj->minvalue) {
    return obj->minvalue;
  }
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
    minStackPush(minStack, 8);
    // printf("8  Top:%d Min:%d \n", minStackTop(minStack), minStackGetMin(minStack));
    // minStackPush(minStack, 10);
    // printf("10 Top:%d Min:%d \n", minStackTop(minStack), minStackGetMin(minStack));
    // minStackPush(minStack, 6);
    // printf("6  Top:%d Min:%d \n", minStackTop(minStack), minStackGetMin(minStack));
    // minStackPush(minStack, 3);
    // printf("3  Top:%d Min:%d \n", minStackTop(minStack), minStackGetMin(minStack));
    // minStackPush(minStack, 7);
    // printf("7  Top:%d Min:%d \n", minStackTop(minStack), minStackGetMin(minStack));
    // minStackPop(minStack);
    // printf("3  Top:%d Min:%d \n", minStackTop(minStack), minStackGetMin(minStack));
    // minStackPop(minStack);
    // printf("6  Top:%d Min:%d \n", minStackTop(minStack), minStackGetMin(minStack));
   
   // printf("%d \n", minStackGetMin(minStack)); // -3
    // minStackPop(minStack);
    // printf("%d \n", minStackTop(minStack)); // 0
    // printf("%d \n", minStackGetMin(minStack)); // -2
    return 0;

}