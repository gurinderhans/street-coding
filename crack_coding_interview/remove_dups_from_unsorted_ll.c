#include <stdio.h>
#include <stdlib.h>

struct node {
  struct node *next;
  int data;
};

// Assumption: each node value is less than 32, for bigger values use a hashmap, etc
void removeDups(struct node *root) {

  int dupcheckMask=0;

  struct node* prev = root;
  struct node* curr = root->next;

  while (curr != NULL) {
    int currData = curr->data;
    if ((dupcheckMask & (1<<currData)) > 0) {//duuppppp
      prev->next = curr->next;
    } else {
      dupcheckMask |= (1<<currData);
      prev = curr;
    }

    curr = curr->next;
  }
}

struct node create_node(int data) {
  struct node *new = malloc(sizeof(struct node));
  new->data = data;
  return *new;
}

int main() {

  struct node a = create_node(9);
  struct node b = create_node(2);
  struct node c = create_node(4);
  struct node d = create_node(6);
  struct node e = create_node(1);
  struct node ba = create_node(2);
  struct node f = create_node(7);

  a.next=&b;
  b.next=&c;
  c.next=&d;
  d.next=&e;
  e.next=&ba;
  ba.next=&f;
  f.next=NULL;

  removeDups(&a);

  struct node *curr = &a;
  while(curr!=NULL) {
    printf("data=%d\n", curr->data);
    curr = curr->next;
  }

  return 0;
}
