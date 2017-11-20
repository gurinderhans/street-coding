#include <iostream>
#include <deque>
#include <vector>
#include <cmath>

using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x, TreeNode *l=NULL, TreeNode *r=NULL) : val(x), left(l), right(r) {}
};

bool mirrored(TreeNode* left, TreeNode *right) {
  if(left==NULL&&right==NULL) return true;
  if(left==NULL||right==NULL) return false;

  return left->val == right->val
    && mirrored(left->right,right->left)
    && mirrored(left->left, right->right);
}

bool isSymmetric(TreeNode* root) {
  if(root==NULL) return true;
  return mirrored(root->left, root->right);
}

int main() {
  TreeNode *r2=new TreeNode{3,
    new TreeNode{4,
      new TreeNode{5,
        new TreeNode{6},
        NULL
      },
      NULL
    },
    new TreeNode{4,
      NULL,
      new TreeNode{5,
        NULL,
        new TreeNode{6}
      }
    }
  };

  bool r=isSymmetric(r2);
  cout << r<<endl;
  return 0;
}
