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
    insert_BinarySearchTree(&tree, 5);
    insert_BinarySearchTree(&tree, 2);
    insert_BinarySearchTree(&tree, 7);
    insert_BinarySearchTree(&tree, 8);
    // print_BinarySearchTree(tree, 0);
    // height_BinarySearchTree(tree);
    printf("%d \n", height_BinarySearchTree(tree));
    // deleteValue_BinarySearchTree(tree, 27);
    // printf("%d \n", minimum_BinarySearchTree(tree)->item);
    // printf("%d \n", maximum_BinarySearchTree(tree)->item);
    // printf("%d \n", search_BinarySearchTree(tree, 5)->item);
    
    return 0;

}