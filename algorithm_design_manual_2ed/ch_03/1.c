#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "data_structures.h"


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


struct parensInfo {
    bool isValid;
    int firstInvalidParensLocation;
};
struct parensInfo set(bool isValid, int firstInvalidParensLocation) {
    struct parensInfo the_struct;
    the_struct.isValid = isValid;
    the_struct.firstInvalidParensLocation = firstInvalidParensLocation;
    return the_struct;
}
struct parensInfo checkParens(char *stringToCheck) {
    Stack* stack = createStack(100);
    int stringLength = strlen(stringToCheck);
    struct parensInfo returnValue;
    for (int i = 0; i < stringLength; i++) {
        char currChar = stringToCheck[i];
        if (currChar == '(') {
            push(stack, i);
        }
        if (currChar == ')') {
            if (isEmptyStack(stack)) {
                returnValue = set(false, i);
                return returnValue;
            }
            else {
                pop(stack);
            }
        }
    }
    if (isEmpty(stack)) {
        returnValue = set(true, 0);
    }
    else {
        returnValue = set(false, pop(stack));
    }
    
    return returnValue;
}
int main()
{
    char test_1[11] = "((())())()";
    char test_2[5] = ")()(";
    char test_3[4] = "())";
    char test_4[5] = "(())";
    char test_5[6] = "(()))";
    printf("%s: %d %d\n", test_1, checkParens(test_1).isValid, checkParens(test_1).firstInvalidParensLocation);
    printf("%s: %d %d\n", test_2, checkParens(test_2).isValid, checkParens(test_2).firstInvalidParensLocation);
    printf("%s: %d %d\n", test_3, checkParens(test_3).isValid, checkParens(test_3).firstInvalidParensLocation);
    printf("%s: %d %d\n", test_4, checkParens(test_4).isValid, checkParens(test_4).firstInvalidParensLocation);
    printf("%s: %d %d\n", test_5, checkParens(test_5).isValid, checkParens(test_5).firstInvalidParensLocation);
    return 0;

}
