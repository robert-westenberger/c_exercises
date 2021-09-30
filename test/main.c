#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include "binary_search_tree.h"

void printCallback(int item) {
    printf("%d \n", item);
}
int main()
{
    BSTNode* tree = NULL;
    insert_BinarySearchTree(&tree, 10);
    insert_BinarySearchTree(&tree, 50);
    insert_BinarySearchTree(&tree, 30);
    insert_BinarySearchTree(&tree, 5);
    return 0;

}