#include <iostream>
#include <vector>
#include <deque>

using namespace std;

struct Node {
  int data;
  Node *left;
  Node *right;

  Node(int val) {
    data = val;
    left = nullptr;
    right = nullptr;
  }
};

void level_order_traversal(Node *root) {
  if (root == nullptr)
    return;

  deque<Node*> dq;
  dq.push_back(root);
  while(dq.size() > 0)
  {
    Node *n = dq.front();
    dq.pop_front();

    cout << n->data << endl;

    if (n->left)
      dq.push_back(n->left);
    if (n->right)
      dq.push_back(n->right);
  }
}

int main() {

  /*
       3
      / \
     4   5
    / \ / \
   6  7 8  9
  */

  Node *root = new Node(3);
  root->left = new Node(4);
  root->right = new Node(5);
  root->left->left = new Node(6);
  root->left->right = new Node(7);
  root->right->left = new Node(8);
  root->right->right = new Node(9);

  level_order_traversal(root);

  return 0;
}
