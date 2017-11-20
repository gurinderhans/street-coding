#include <stdio.h>
#include <stdlib.h>


struct ListNode {
  int val;
  struct ListNode *next;
};


struct ListNode* swapPairs(struct ListNode* head) {

  if (head == NULL || head->next == NULL)
    return head;

  struct ListNode *a = head;
  struct ListNode *b = a->next;

  struct ListNode *ret = b;

  struct ListNode *nxt = b->next;

  for (;;) {

    b->next = a;

    if (nxt == NULL)
    {
      a->next = NULL;
      break;
    }
    else if (nxt->next == NULL)
    {
      a->next = nxt;
      break;
    }
    else
    {
      a->next = nxt->next;
    }

    a = nxt;
    b = a->next;
    nxt = b->next;
  }


  return ret;
}

struct ListNode * new_node(int val) {
  struct ListNode * new = malloc(sizeof(struct ListNode));
  new->next = NULL;
  new->val = val;
  return new;
}

int main () {
  struct ListNode * a = new_node(1);
  a->next = new_node(2);
  a->next->next = new_node(3);
  a->next->next->next = new_node(4);
  /* a->next->next->next = new_struct ListNode *(4); */

  struct ListNode * ret = swapPairs(a);

  struct ListNode * it = ret;
  while (1) {
    if (ret == NULL)
      break;
    printf("val=%d\n", ret->val);
    ret = ret->next;
  }


  return 0;
}
