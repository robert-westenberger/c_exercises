#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

/*

Given the root of a binary tree, return the inorder traversal of its nodes' values.

*/


struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

void inOrderTraversalHelper(struct TreeNode* root, int* returnSize, int** result) {
    if (root != NULL) {
        inOrderTraversalHelper(root->left, returnSize, result);
        *(result + *returnSize) = malloc(sizeof(int));
        **(result + *returnSize) = root->val;
        *returnSize = *returnSize + 1;
        inOrderTraversalHelper(root->right, returnSize, result);
    }
    
}




int* inorderTraversal(struct TreeNode* root, int* returnSize){
    int* result = NULL;
    int** ptr = &result;
    returnSize = malloc(sizeof(int));
    *returnSize = 0;
    if (root != NULL) {
        inOrderTraversalHelper(root, returnSize, ptr);
    }
    
    for (int i = 0; i < *returnSize; i++) {
        *(result + i) = **(ptr + i);
    }
   
    return result;
}

int main()
{   
    struct TreeNode* root = malloc(sizeof(struct TreeNode));
    struct TreeNode* node1 = malloc(sizeof(struct TreeNode));
    struct TreeNode* node2 = malloc(sizeof(struct TreeNode));
    root->val = 1;
    node1->val = 2;
    node2->val = 3;
    root->right = node1;
    node1->left = node2;
    int* result = inorderTraversal(root,0);
    int* result2 = inorderTraversal(NULL,0);
    // int** result = inorderTraversal(root,0);
    // *result = 1;
    // *(result+1) = 3;
    // *(result+2) = 2;
    return 0;

}