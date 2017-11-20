#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct ListNode {
  int val;
  struct ListNode *next;
};

struct ListNode *new_node(int val) {
  struct ListNode *ret = malloc(sizeof(struct ListNode));
  ret->val = val;
  ret->next = NULL;

  return ret;
}

struct ListNode * sum (struct ListNode * l1, struct ListNode * l2) {

  struct ListNode *ret = NULL;
  struct ListNode *itr = NULL;

  struct ListNode *ita = l1;
  struct ListNode *itb = l2;

  bool carryOn = false;

  for(;;) {

    if (ita == NULL && itb == NULL && !carryOn) {
      break;
    }

    int sum = 0;
    if (ita != NULL) {
      sum += ita->val;
      ita = ita->next;
    }
    
    if (itb != NULL) {
      sum += itb->val;
      itb = itb->next;
    }

    if (carryOn) {
      sum++;
    }

    carryOn = sum >= 10;

    if (ret == NULL) { // first time
      ret = malloc(sizeof(struct ListNode));
      ret->val = sum % 10;
      ret->next = NULL;
      itr = ret;
    } else {
      itr->next = malloc(sizeof(struct ListNode));
      itr->next->val = sum % 10;
      itr->next->next = NULL;
      itr = itr->next;
    }
  }

  return ret;
}

int main() {

  struct ListNode *l1 = new_node(5);
  /* l1->next = new_node(4); */
  /* l1->next->next = new_node(3); */
  /* l1->next->next->next = new_node(6); */

  struct ListNode *l2 = new_node(5);
  /* l2->next = new_node(6); */
  /* l2->next->next = new_node(4); */

  struct ListNode * res = sum(l1,l2);

  struct ListNode *its = res;
  while (its != NULL) {
    printf("val: %d\n", its->val);
    its = its->next;
  }

  return 0;
}
