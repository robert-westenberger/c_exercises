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

typedef struct ListNode {
  int val;
  struct ListNode *next;
} ListNode;

struct ListNode *addTwoNumbers(struct ListNode *l1, struct ListNode *l2) {
  struct ListNode* returnValue = NULL;
  struct ListNode** returnValuePtr = &returnValue;
  int sum;
  int count = 0;
  int carryover = 0;
  while(l1 != NULL || l2 != NULL) {
  
    // if (count > 0) {
    //   (*returnValuePtr)->next = malloc(sizeof(ListNode));
    //   returnValuePtr = &(*returnValuePtr)->next;
    // } else {
    //   (*returnValuePtr) = malloc(sizeof(ListNode));
    // }
    
    // if (l1 != NULL && l2 != NULL) {
    //   sum = l1->val + l2->val;
    // } else if (l1 != NULL) {
    //   sum = l1->val;
    // } else {
    //   sum = l2->val;
    // }
    // if (sum <= 9) {
    //   (*returnValuePtr)->val = sum;
    // } else {
    //   carryover = sum - 9;
    //   (*returnValuePtr)->val = 0;
    //   if (l1->next != NULL && l2->next != NULL) {
    //     if (l1->next->val >= l2->next->val) {
    //       l2->next->val = l2->next->val + carryover;
    //     }
    //     else {
    //       l1->next->val = l1->next->val + carryover;
    //     }
    //   } else if (l1->next != NULL) {
    //     l1->next->val = l1->next->val + carryover;
    //   } else if (l2->next != NULL) {
    //     l2->next->val = l2->next->val + carryover;
    //   } else {
    //     l1->next = malloc(sizeof(ListNode));
    //     l1->next->val = carryover;
    //   }
    // }
    if (l1 != NULL) {
      l1 = l1->next;
    }
    if (l2 != NULL) {
      l2 = l2->next;
    }
    
    count++;
  }
  
  return returnValue;
}

int main() {
  ListNode *node_1 = (struct ListNode *)malloc(sizeof(struct ListNode));
  ListNode *node_2 = (struct ListNode *)malloc(sizeof(struct ListNode));
  ListNode *node_3 = (struct ListNode *)malloc(sizeof(struct ListNode));
  ListNode *node_4 = (struct ListNode *)malloc(sizeof(struct ListNode));
  ListNode *node_5 = (struct ListNode *)malloc(sizeof(struct ListNode));
  ListNode *node_6 = (struct ListNode *)malloc(sizeof(struct ListNode));
  node_1->val = 2;
  node_2->val = 4;
  node_3->val = 3;
  node_4->val = 5;
  node_5->val = 9;
  node_6->val = 4;
  node_1->next=node_2;
  node_2->next=node_3;
  node_4->next=node_5;
  node_5->next=node_6;
  ListNode* answer = addTwoNumbers(node_1, node_4);
  return 0;
}