#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include <stdlib.h>

/* TODO: Worst fit heuristic */
/*
[5] In the bin-packing problem, we are given n metal objects, each weighing 
between zero and one kilogram. Our goal is to find the smallest number of bins 
that will hold the n objects, with each bin holding one kilogram at most.
• The best-fit heuristic for bin packing is as follows. Consider the objects in 
the order in which they are given. For each object, place it into the 
partially filled bin with the smallest amount of extra room after the object 
is inserted.. If no such bin exists, start a new bin. Design an algorithm 
that implements the best-fit heuristic (taking as input the n weights 
w1, w2, ...,wn and outputting the number of bins used) in O(n log n) time.
• Repeat the above using the worst-fit heuristic, where we put the next object in
the partially filled bin with the largest amount of extra room after the object
is inserted.
*/
#define ARR_LENGTH 6

double randFrom(double min, double max)
{
  double range = (max - min);
  double div = RAND_MAX / range;
  return min + (rand() / div);
}
double* generateArrayOfRandomDoubles(int n) {
  double *arr = malloc(n * sizeof(double));
  for (int i = 0; i<n; i++) {
    *(arr + i) = randFrom(0.1, 1);
  }
  return arr;
}

typedef struct Node
{
  double capacity;
  struct Node *left;
  struct Node *right;
} Node;

bool insert_BinarySearchTree(Node **tree, double value)
{
  Node *treePtr = *tree;
  Node *newNode = malloc(sizeof(Node));
  Node *newNodeParent = NULL;

  newNode->capacity = value;
  newNode->left = NULL;
  newNode->right = NULL;

  while (treePtr != NULL)
  {
    newNodeParent = treePtr;
    if ((treePtr)->capacity > value)
    {
      treePtr = (treePtr)->left;
    }
    else
    {
      treePtr = (treePtr)->right;
    }
  }

  if (newNodeParent == NULL)
  {
    *tree = newNode;
  }
  else
  {
    if (newNodeParent->capacity > value)
    {
      newNodeParent->left = newNode;
    }
    else
    {
      newNodeParent->right = newNode;
    }
  }

  return true;
}

Node *search_BinarySearchTree(Node *tree, double value)
{
  if (tree == NULL)
  {
    return NULL;
  }
  if (tree->capacity == value)
  {
    return tree;
  }
  if (value < tree->capacity)
  {
    return search_BinarySearchTree(tree->left, value);
  }
  return search_BinarySearchTree(tree->right, value);
}
Node *minimum_BinarySearchTree(Node *tree)
{
  Node *minimum;
  if (tree == NULL)
  {
    return NULL;
  }
  minimum = tree;
  while (minimum->left != NULL)
  {
    minimum = minimum->left;
  }
  return minimum;
}
Node *maximum_BinarySearchTree(Node *tree)
{
  Node *maximum;
  if (tree == NULL)
  {
    return NULL;
  }
  maximum = tree;
  while (maximum->right != NULL)
  {
    maximum = maximum->right;
  }
  return maximum;
}

Node *deleteNode_BinarySearchTree(Node *tree, Node *node) {
  if (tree == NULL) {
    return tree;
  }

  if (node->capacity < tree->capacity) {
    tree->left = deleteNode_BinarySearchTree(tree->left, node);
  }
  else if (node->capacity > tree->capacity) {
    tree->right = deleteNode_BinarySearchTree(tree->right, node);
  }
  else {
    if (tree->left == NULL) {
      Node *temp = tree->left;
      free(tree);
      return temp;
    }
    else if (tree->right == NULL)
    {
      Node *temp = tree->right;
      free(tree);
      return temp;
    }
    Node *temp = minimum_BinarySearchTree(tree->right);
    tree->capacity = temp->capacity;
    tree->right = deleteNode_BinarySearchTree(tree->right, temp);
  }
  return tree;
}

void print_BinarySearchTree(Node *tree, int row)
{
  if (tree == NULL)
  {
    return;
  }

  print_BinarySearchTree(tree->right, row + 2);

  printf("\n ");
  for (int i = 0; i < row; i++)
  {
    printf(" ");
  }
  printf("%f", tree->capacity);
  print_BinarySearchTree(tree->left, row + 2);
}

Node *findBestFitBin(Node **tree, double value, double maxBinCapacity)
{
  Node* treePtr = *tree;
  double newCapacity = 0;
  double bestFitCapacity = 0;
  Node* bestFitBin = NULL;
  while (treePtr != NULL) {
    newCapacity = treePtr->capacity + value;
    if (newCapacity > maxBinCapacity) {
      // can't add to this bin, try a smaller bin
      treePtr = treePtr->left;
    } else {
      bestFitBin = treePtr;
      bestFitCapacity = newCapacity;
      treePtr = treePtr->right;
    }
  }
  return bestFitBin;
}
void placeIntoBin(Node **tree, double value, double maxBinCapacity) {
  Node *treePtr = *tree;
  Node *newNodeParent = NULL;
  Node *newBin = NULL;
  if (treePtr == NULL) {
    insert_BinarySearchTree(tree, value);
  } else {
    newBin = findBestFitBin(tree, value, maxBinCapacity);
    if (newBin == NULL) {
      insert_BinarySearchTree(tree, value);
    } else {
      *tree = deleteNode_BinarySearchTree(*tree, newBin);
      insert_BinarySearchTree(tree, newBin->capacity + value);
    }
    
    
  }
  __asm("nop");
}

int countNodes(Node* tree) {
  if (tree == NULL) {
    return 0;
  }

  return 1 + countNodes(tree->left) + countNodes(tree->right);
}
int bestFit(double* weights, double maxBinCapacity) {
  Node *tree = NULL;

  for (int i = 0; i < ARR_LENGTH; i++) {
    placeIntoBin(&tree, *(weights + i), maxBinCapacity);
    printf("%f \n", *(weights + i));
  }
  return countNodes(tree);
}
int main() {
  // srand(time(NULL));
  double *weights = generateArrayOfRandomDoubles(ARR_LENGTH);
  // double *weights = malloc(ARR_LENGTH * sizeof(double));
  // *weights = 4;
  // *(weights + 1) = 8;
  // *(weights + 2) = 1;
  // *(weights + 3) = 4;
  // *(weights + 4) = 2;
  // *(weights + 5) = 1;
  int n = bestFit(weights, 10);
  return 0;
}