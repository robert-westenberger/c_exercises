#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "helpers.h"

/*
Leetcode 100 Same Tree
Given the roots of two binary trees p and q, write a function to 
check if they are the same or not.

Two binary trees are considered the same if they are structurally 
identical, and the nodes have the same value.
*/

struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

bool isSameTree(struct TreeNode *p, struct TreeNode *q)
{
    if (p == NULL && q == NULL)
    {
        return true;
    }
    if (p == NULL || q == NULL)
    {
        return false;
    }
    return (p->val == q->val) && isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
}
int main()
{
    struct TreeNode *node_1 = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    struct TreeNode *node_2 = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    struct TreeNode *node_3 = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    struct TreeNode *node_4 = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    struct TreeNode *node_5 = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    struct TreeNode *node_6 = (struct TreeNode *)malloc(sizeof(struct TreeNode));

    node_1->val = 1;
    node_2->val = 2;
    node_3->val = 3;
    node_4->val = 1;
    node_5->val = 2;
    node_6->val = 3;
    node_1->left = node_2;
    node_1->right = node_3;
    node_4->left = node_5;
    node_4->right = node_6;

    node_2->left = NULL;
    node_2->right = NULL;
    node_3->left = NULL;
    node_3->right = NULL;
    node_5->left = NULL;
    node_5->right = NULL;
    node_6->left = NULL;
    node_6->right = NULL;
    bool n = isSameTree(node_1, node_4);
    return 0;
}