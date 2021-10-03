#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include "binary_search_tree.h"


int main()
{
    BSTNode* tree = NULL;
    insert_BinarySearchTree(&tree, 6);
    insert_BinarySearchTree(&tree, 5);
    insert_BinarySearchTree(&tree, 2);
    insert_BinarySearchTree(&tree, 5);
    insert_BinarySearchTree(&tree, 7);
    insert_BinarySearchTree(&tree, 8);
    print_BinarySearchTree(tree, 0);
    printf("\n");

    
    return 0;

}