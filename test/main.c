#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include "binary_search_tree.h"

void inorderforeach(BSTNode node) {
    printf("Currently on item... %d \n", node.item);
    
    if (node.parent != NULL) {
        printf("parent: %d \n", node.parent ->item);
    }
    if (node.left != NULL && node.right != NULL) {
        printf("%d <- %d -> %d \n", node.left->item, node.item, node.right->item);
        return;
    }
    if (node.left != NULL) {
        printf("%d <- %d \n", node.left->item, node.item);
        return;
    }
    if (node.left != NULL) {
        printf("%d -> %d \n",  node.item, node.right->item);
        return;
    }
    printf("%d \n", node.item);
}
// void preorderprint(BSTNode node) {
//     printf("pre %d \n", node.item);
// }
// void postorderprint(BSTNode node) {
//     printf("post %d \n", node.item);
// }
// void postorderprint(BSTNode node) {
//     printf("post %d \n", node.item);
// }
int main()
{
    BSTNode* tree = NULL;
    insert_BinarySearchTree(&tree, 10);
    insert_BinarySearchTree(&tree, 20);
    insert_BinarySearchTree(&tree, 5);
    insert_BinarySearchTree(&tree, 27);
    insert_BinarySearchTree(&tree, 11);
    inOrderTraversal_BinarySearchTree(tree, inorderforeach);
    // preOrderTraversal_BinarySearchTree(tree, preorderprint);
    // postOrderTraversal_BinarySearchTree(tree, postorderprint);
    
    return 0;

}