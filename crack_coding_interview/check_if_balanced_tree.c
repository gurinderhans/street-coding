#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "vector/vector.c"

typedef struct node_ {
  struct node_ *left;
  struct node_ *right;

  int data;
} node;

node * new_node(int data)
{
  node *new = malloc(sizeof(node));
  new->data = data;
  new->left = NULL;
  new->right = NULL;
  return new;
}

void get_heights(node *root, vector_int *heights, int lvl)
{
  node *L = root->left,
       *R = root->right;

  if (L == NULL && R == NULL)
  { // reached a leaf node, record height
    vectori_add(heights, lvl);
    return;
  }

  if (L != NULL)
  {
    get_heights(L, heights, lvl+1);
  }
  else
  { // this path doesn't exist, so record limited height
    vectori_add(heights, lvl);
  }

  if (R != NULL)
  {
    get_heights(R, heights, lvl+1);
  }
  else
  { // this path doesn't exist, so record limited height
    vectori_add(heights, lvl);
  }
}

bool is_balanced(node *root)
{
  vector_int heights;
  vectori_init(&heights);
  get_heights(root, &heights, 0);

  int max=-1;
  int min=10000;

  for (int i=0; i<heights.size; ++i)
  {
    int h = vectori_get(&heights, i);
    if (h > max)
      max = h;
    if (h < min)
      min = h;
  }
  return !(max - min > 1);
}

int main ()
{

  node *root = new_node(5);
  
  root->left = new_node(2);
  root->right = new_node(7);
  
  root->left->left = new_node(1);
  root->left->right = new_node(3);
  root->left->right->right = new_node(4);
  root->left->right->left = new_node(9);
  /* root->left->right->right->right = new_node(10); */

  root->right->left = new_node(6);
  root->right->right = new_node(7);

  bool yes = is_balanced(root);
  printf("is balanced = %d\n", yes);

  return 0;
}
