#include <iostream>
#include <string>

using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x, TreeNode *l=NULL, TreeNode *r=NULL) : val(x), left(l), right(r) {}
};

string tree2str(TreeNode* t) {
  if(t==NULL) return "";
  string l=tree2str(t->left);
  string r=tree2str(t->right);
  if (l=="" && r=="")
    return to_string(t->val);

  string rt=to_string(t->val)+"("+l+")";
  if(r!="")
    rt+="("+r+")";
  return rt;
}

int main() {
  TreeNode *r2=new TreeNode(1);
  // ,
  //     new TreeNode(2,new TreeNode(4)),
  //     new TreeNode(3));

  string r=tree2str(r2);
  cout << r<<endl;
  return 0;
}
