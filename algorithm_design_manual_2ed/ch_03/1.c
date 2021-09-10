#include <stdio.h>
#include <stdbool.h>
#include "data_structures.h"
#include "example.h"


/* 
Stacks, Queues, and Lists
3.1 A common problem for compilers and text editors is determining whether the
parentheses in a string are balanced and properly nested. For example, the string
((())())() contains properly nested pairs of parentheses, which the strings )()( and
()) do not. Give an algorithm that returns true if a string contains properly nested
and balanced parentheses, and false if otherwise. For full credit, identify the position
of the first offending parenthesis if the string is not properly nested and balanced.
*/

/* ------------------------------------------------ */

/* Algorithm will use a stack data structure. As the string containing parens is scanned, there
will be three cases:
1) Open parens - Push to the stack
2) Close parens - Pop from the stack
3) Other character - Do nothing (out of scope for this exercise..?)

The string will contain unbalanced parens if the stack is not empty.
*/

bool checkParens(char *stringToCheck) {
    printf("%s\n", stringToCheck);
    return true;
}
int main()
{
    // char test_1[11] = "((())())()";
    // char test_2[5] = ")()(";
    // char test_3[4] = "())";
    Stack* stack = createStack(100);
    push(stack, 10);
    push(stack, 20);
    printf("%d popped from stack\n", pop(stack));
    // int myfoo = foo(4);
    // printf("%d", myfoo);
    return 0;
    // checkParens(test_1);
	

	return 0;
}
