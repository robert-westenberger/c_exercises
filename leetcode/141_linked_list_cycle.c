#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "uthash.h"

/*
Given head, the head of a linked list, determine if the linked list has a cycle in it.

There is a cycle in a linked list if there is some node in the list that can be 
reached again by continuously following the next pointer. Internally, pos is used to 
denote the index of the node that tail's next pointer is connected to. Note 
that pos is not passed as a parameter.

Return true if there is a cycle in the linked list. Otherwise, return false.
*/

struct ListNode
{
    int val;
    struct ListNode *next;
};
bool hasCycle(struct ListNode *head)
{
    struct ListNode *fast = head;
    struct ListNode *slow = head;
    while (slow && fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
        {
            return true;
        }
    }
    return false;
}

int main()
{
    struct ListNode *node_1 = (struct ListNode *)malloc(sizeof(struct ListNode));
    struct ListNode *node_2 = (struct ListNode *)malloc(sizeof(struct ListNode));
    struct ListNode *node_3 = (struct ListNode *)malloc(sizeof(struct ListNode));
    struct ListNode *node_4 = (struct ListNode *)malloc(sizeof(struct ListNode));

    node_1->val = 3;
    node_2->val = 2;
    node_3->val = 0;
    node_4->val = -4;
    node_1->next = node_2;
    node_2->next = node_3;
    node_3->next = node_4;
    node_4->next = NULL;
    bool answer = hasCycle(node_1);
    return 0;
}