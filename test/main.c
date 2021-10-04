#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include "red_black_tree.h"


int main()
{
    RBTNode* tree = NULL;
    insert_RedBlackTree(&tree, 1);
    insert_RedBlackTree(&tree, 2);
    insert_RedBlackTree(&tree, 3);
    
    insert_RedBlackTree(&tree, 4);
    insert_RedBlackTree(&tree, 5);

    print_RedBlackTree(tree, 0);
    // print_RedBlackTree(tree, 0);
    // printf("\n");
 
    return 0;

}