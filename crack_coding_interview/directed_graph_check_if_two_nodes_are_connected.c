#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "vector/vector.c"

typedef struct node_ {
  struct node_ ** children; // could replace with custom built vector :))))
  int child_count;
  int data;
  bool visited;
} node;

node * new_node(int data) {
  node *new = malloc(sizeof(node));
  new->data = data;
  new->children = NULL;
  new->child_count = 0;
  new->visited = false;
  return new;
}

bool check_node_conn(node *from, node *to)
{

  /// Do a DFS through the graph and once we reach
  /// the `to` node, and since we started with `from`
  /// node, we know the two nodes are connected.

  vector *stack;
  vector_new(&stack);
  vector_add(stack, from);

  while (stack->size > 0)
  {
    node *p = vector_get(stack, stack->size-1);
    vector_delete(stack, stack->size-1);

    for (int i=0; i<p->child_count; ++i)
    {
      node *pchild = p->children[i];

      if (pchild->data == to->data) {
        return true;
      }

      if (pchild->visited == false)
      {
        vector_add(stack, pchild);
      }
    }

    p->visited = true;
  }

  return false;
}

int main() {
  node *root = new_node(0);

  // 0 -> (1,5)
  root->children = malloc(sizeof(node *) * 2);
  root->child_count=2;
  root->children[0]=new_node(1);
  root->children[1]=new_node(5);

  // 1 -> (3,2)
  root->children[0]->children = malloc(sizeof(node *) * 2);
  root->children[0]->child_count=2;
  root->children[0]->children[0] = new_node(3);
  root->children[0]->children[1] = new_node(2);

  // 5 -> (3, 4)
  root->children[1]->children=malloc(sizeof(node *) * 2);
  root->children[1]->child_count=2;
  root->children[1]->children[0] = root->children[0]->children[0];
  root->children[1]->children[1] = new_node(4);

  // 3 -> (1, 5, 4)
  node *n3 = root->children[0]->children[0];
  n3->children = malloc(sizeof(node *) * 3);
  n3->child_count=3;
  n3->children[0] = root->children[0];
  n3->children[1] = root->children[1];
  n3->children[2] = root->children[1]->children[1];

  // 4 -> (3,5)
  node *n4 = root->children[1]->children[1];
  n4->children = malloc(sizeof(node *) * 2);
  n4->child_count=2;
  n4->children[0] = root->children[0]->children[0];
  n4->children[1] = root->children[1];

  // 2 -> (1,4)
  node *n5 = root->children[0]->children[1];
  n5->children = malloc(sizeof(node *) * 2);
  n5->child_count=2;
  n5->children[0] = root->children[0];
  n5->children[1] = root->children[1]->children[1];

  bool connected = check_node_conn(root, root->children[0]->children[1]);
  /* bool connected = check_node_conn(root, new_node(9)); */

  printf("is connected = %d\n", connected);

  return 0;
}
