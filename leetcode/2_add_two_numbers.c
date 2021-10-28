#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "uthash.h"

/*
You are given two non-empty linked lists representing two non-negative integers. 
The digits are stored in reverse order, and each of their nodes contains a 
single digit. Add the two numbers and return the sum as a linked list.

You may assume the two numbers do not contain any leading zero, except 
the number 0 itself.

(The linked lists can be of different lengths)
*/

struct ListNode
{
    int val;
    struct ListNode *next;
};

struct ListNode *addTwoNumbers(struct ListNode *l1, struct ListNode *l2)
{
    struct ListNode *returnValue = NULL;
    struct ListNode **returnValuePtr = malloc(sizeof(struct ListNode));
    int sum = 0;
    int count = 0;
    int carry = 0;
    while (l1 != NULL || l2 != NULL)
    {
        if (count > 0)
        {
            returnValue->next = malloc(sizeof(struct ListNode));
            returnValue = returnValue->next;
            returnValue->next = NULL;
        }
        else
        {
            returnValue = malloc(sizeof(struct ListNode));
            *returnValuePtr = returnValue;
            returnValue->next = NULL;
        }
        if (l1 != NULL && l2 != NULL)
        {
            sum = l1->val + l2->val + carry;
        }
        else if (l1 != NULL)
        {
            sum = l1->val + carry;
        }
        else
        {
            sum = l2->val + carry;
        }
        if (sum <= 9)
        {
            returnValue->val = sum;
        }
        else
        {
            carry = (sum / 10) % 10;
            sum = sum % 10;

            returnValue->val = sum;
        }
        if (l1 != NULL)
        {
            l1 = l1->next;
        }
        if (l2 != NULL)
        {
            l2 = l2->next;
        }
        count++;
    }

    return *returnValuePtr;
}

int main()
{
    struct ListNode *node_1 = (struct ListNode *)malloc(sizeof(struct ListNode));
    struct ListNode *node_2 = (struct ListNode *)malloc(sizeof(struct ListNode));
    struct ListNode *node_3 = (struct ListNode *)malloc(sizeof(struct ListNode));
    struct ListNode *node_4 = (struct ListNode *)malloc(sizeof(struct ListNode));
    struct ListNode *node_5 = (struct ListNode *)malloc(sizeof(struct ListNode));
    struct ListNode *node_6 = (struct ListNode *)malloc(sizeof(struct ListNode));
    node_1->val = 2;
    node_2->val = 4;
    node_3->val = 3;
    node_4->val = 5;
    node_5->val = 9;
    node_6->val = 4;
    node_1->next = node_2;
    node_2->next = node_3;
    node_4->next = node_5;
    node_5->next = node_6;
    struct ListNode *answer = addTwoNumbers(node_1, node_4);
    return 0;
}