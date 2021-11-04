#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <limits.h>
#include "avl_tree.h"

void preOrder(AVLTree* tree, AVLNode *node)
{
  if (node != NULL)
  {
    printf("%s\n", (const char *) node->data);
    preOrder(tree, node->left);
    preOrder(tree, node->right);
  }
}

int main()
{

  AVLTree* string_tree = create_AVLTree(data_ops_string);
  string_tree->head = insert_AVLTree(string_tree, "Test");
  string_tree->head = insert_AVLTree(string_tree, "Bar");
  preOrder(string_tree, string_tree->head);
  return 0;
}