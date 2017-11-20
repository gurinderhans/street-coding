#include <stdio.h>
#include <stdlib.h>

typedef struct node_ {
  struct node_ *left;
  struct node_ *right;
  int data;
} node;

node * new_node(int data) {
  node *new = malloc(sizeof(node));
  new->data = data;
  new->left = NULL;
  new->right = NULL;

  return new;
}

void pprint(int data) {
  printf("data=%d\n", data);
}

node * create_btree(int *arr, int start, int end) {

  if (start > end) {
    return NULL;
  }

  int mid = (start + end) / 2;
  node *new = new_node(arr[mid]);
  new->left = create_btree(arr, start, mid-1);
  new->right = create_btree(arr, mid+1, end);

  return new;
}

int main() {
  int SIZE = 8;

  int *arr = malloc(sizeof(int) * SIZE);
  arr[0]=1;arr[1]=2;arr[2]=3;arr[3]=4;arr[4]=5;arr[5]=6;arr[6]=7;arr[7]=8;
  /* for (int i=0;i<SIZE;++i) printf("%d ",arr[i]); */
  /* printf("\n"); */

  node *tree = create_btree(arr, 0, SIZE-1);
  pprint(tree->data);
  pprint(tree->left->data);
  pprint(tree->right->data);
  pprint(tree->left->left->data);
  pprint(tree->left->right->data);
  pprint(tree->right->left->data);
  pprint(tree->right->right->data);
  pprint(tree->right->right->right->data);

  return 0;
}
