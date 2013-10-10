/*
树结点的定义(请不要在代码中定义该结构)
struct TreeNode {
  int val;
  TreeNode *left, *right;
}*/
#include <limits.h>
bool check(TreeNode *node,int minV,int maxV)
{
	if(!node) return true;
	int val = node->val;
	if(val <= minV || val > maxV) return false;
	return check(node->left,minV,val)&&check(node->right,val,maxV);
}

bool isBST(TreeNode *root) {
	int minV = INT_MIN,maxV = INT_MAX;
	return check(root,minV,maxV);
}