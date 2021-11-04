#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <limits.h>
#include "avl_tree.h"

void preOrder(AVLTree* tree, AVLNode *node)
{
  if (node != NULL)
  {
    tree->data_ops.print(node->data);
    preOrder(tree, node->left);
    preOrder(tree, node->right);
  }
}

int main()
{

  // AVLTree* string_tree = create_AVLTree(data_ops_string);
  // string_tree->head = insert_AVLTree(string_tree, string_tree->head, "Test");
  // string_tree->head = insert_AVLTree(string_tree, string_tree->head, "Bar");
  // preOrder(string_tree, string_tree->head);
  AVLTree *int_tree = create_AVLTree(data_ops_int);
  int ten = 10;
  int twenty = 20;
  int thirty = 30;
  int fourty = 40;
  int fifty = 50;
  int twentyfive = 25;
  int_tree->head = insert_AVLTree(int_tree, int_tree->head, &ten);
  int_tree->head = insert_AVLTree(int_tree, int_tree->head, &twenty);
  int_tree->head = insert_AVLTree(int_tree, int_tree->head, &thirty);
  int_tree->head = insert_AVLTree(int_tree, int_tree->head, &fourty);
  int_tree->head = insert_AVLTree(int_tree, int_tree->head, &fifty);
  int_tree->head = insert_AVLTree(int_tree, int_tree->head, &twentyfive);
  preOrder(int_tree, int_tree->head);
  return 0;
}