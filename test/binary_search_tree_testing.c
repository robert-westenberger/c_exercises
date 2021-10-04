#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include "binary_search_tree.h"


int main()
{
    BSTNode *tree = NULL;
    insertRecursive_BinarySearchTree(&tree, 6);
    insertRecursive_BinarySearchTree(&tree, 5);
    insertRecursive_BinarySearchTree(&tree, 7);
    insertRecursive_BinarySearchTree(&tree, 2);
    insertRecursive_BinarySearchTree(&tree, 5);
    insertRecursive_BinarySearchTree(&tree, 8);
    print_BinarySearchTree(tree, 0);
    printf("\n");

    
    return 0;

}