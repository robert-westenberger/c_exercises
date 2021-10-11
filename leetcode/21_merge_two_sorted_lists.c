#include <limits.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

/*

Merge two sorted linked lists and return it as a sorted list.
 The list should be made by splicing together the nodes of the 
 first two lists.

*/

typedef struct ListNode { 
    int val;
    struct ListNode *next;
} ListNode;

struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2){
    
    if (l1 == NULL) {
        return l2;
    }
    if (l2 == NULL) {
        return l1;
    }
    if (l1->val <= l2->val) {
        l1->next = mergeTwoLists(l1->next, l2);
        return l1;
    }
    l2->next = mergeTwoLists(l1, l2->next);
    return l2;
}

int main()
{   
    ListNode* node_1 = (struct ListNode*)malloc(sizeof(struct ListNode));
    ListNode* node_2 = (struct ListNode*)malloc(sizeof(struct ListNode));
    ListNode* node_3 = (struct ListNode*)malloc(sizeof(struct ListNode));
    ListNode* node_4 = (struct ListNode*)malloc(sizeof(struct ListNode));
    ListNode* node_5 = (struct ListNode*)malloc(sizeof(struct ListNode));
    ListNode* node_6 = (struct ListNode*)malloc(sizeof(struct ListNode));
    // node_1->val = 1;
    // node_2->val = 2;
    // node_3->val = 4;
    // node_1->next = node_2; 
    // node_2->next = node_3;
    // node_4->val = 1;
    // node_5->val = 3;
    // node_6->val = 4;
    // node_4->next = node_5;
    // node_5->next = node_6;
    mergeTwoLists(node_1, node_4);
    return 0;

}