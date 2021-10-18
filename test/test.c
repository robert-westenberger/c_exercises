#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

int* TAB() {
    int temp;
    return(&temp); // return a pointer to the local int
}
int main()
{   
    int* ptr;
    ptr = TAB();
    *ptr = 42; 
    return 0;
}