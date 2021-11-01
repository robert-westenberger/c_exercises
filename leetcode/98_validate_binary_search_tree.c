#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <limits.h>
#include "uthash.h"

/*
Given the root of a binary tree, determine if it is a valid binary search tree (BST).

A valid BST is defined as follows:

The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees must also be binary search trees.
*/

struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};
bool isValidBSTHelper(struct TreeNode *root, long min, long max)
{
    if (!root)
    {
        return true;
    }

    if (root->val <= min || root->val >= max)
    {
        return false;
    }
    return isValidBSTHelper(root->left, min, root->val) && isValidBSTHelper(root->right, root->val, max);
}
bool isValidBST(struct TreeNode *root)
{
    return isValidBSTHelper(root, LONG_MIN, LONG_MAX);
}

int main()
{
    struct TreeNode *node_1 = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    struct TreeNode *node_2 = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    struct TreeNode *node_3 = (struct TreeNode *)malloc(sizeof(struct TreeNode));

    struct TreeNode *node_4 = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    struct TreeNode *node_5 = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    struct TreeNode *node_6 = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    struct TreeNode *node_7 = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    struct TreeNode *node_8 = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    node_1->val = 2;
    node_2->val = 2;
    node_3->val = 2;

    node_4->val = 5;
    node_5->val = 1;
    node_6->val = 4;
    node_7->val = 3;
    node_8->val = 6;
    node_1->left = node_2;
    node_1->right = node_3;
    node_2->left = NULL;
    node_2->right = NULL;
    node_3->left = NULL;
    node_3->right = NULL;
    node_4->left = node_5;
    node_4->right = node_6;
    node_5->left = NULL;
    node_5->right = NULL;
    node_6->left = node_7;
    node_6->right = node_8;
    node_7->left = NULL;
    node_7->right = NULL;
    node_8->left = NULL;
    node_8->right = NULL;
    // bool answer1 = isValidBST(node_1);
    bool answer2 = isValidBST(node_1);
    return 0;
}