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

void inOrderTraversalHelper(struct TreeNode* root, int* returnSize, int** result_ref) {
    if (root != NULL) {
        inOrderTraversalHelper(root->left, returnSize, result_ref);        
        if (*returnSize == 0) {
            *result_ref = malloc(sizeof(int));
        } else {
            *result_ref = realloc(*result_ref, 
            (sizeof(int) * (*returnSize + 1)));
        }
        *((*result_ref) + *returnSize) = root->val;
        
        *returnSize = *returnSize + 1;
        inOrderTraversalHelper(root->right, returnSize, result_ref);
    }
}


int* inorderTraversal(struct TreeNode* root, int* returnSize) {
    int* result = NULL;
    int ** result_ref = &result;
    returnSize = malloc(sizeof(int));
    *returnSize = 0;
    if (root != NULL) {
        inOrderTraversalHelper(root, returnSize, result_ref);
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
    // int* result2 = inorderTraversal(NULL,0);
    // int** result = inorderTraversal(root,0);
    // *result = 1;
    // *(result+1) = 3;
    // *(result+2) = 2;
    printf("%d \n", result[0]);
    printf("%d \n", result[1]);
    printf("%d \n", result[2]);
    printf("%d \n", result[4]);
    return 0;
}