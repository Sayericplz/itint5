/*
树结点的定义(请不要在代码中定义该结构)
struct TreeNode {
  TreeNode *left;
  TreeNode *right;
}*/
bool check(TreeNode *node,int &len)
{
	if(!node) 
	{
		len = 0;
		return true;
	}
	int llen,rlen;
	bool lb = check(node->left,llen);
	bool rb = check(node->right,rlen);
	len = max(llen,rlen)+1;
	return lb&&rb&&abs(llen-rlen)<=1;
}

bool isBalancedTree(TreeNode *root) {
	if(!root) return true;
	int len;
	return check(root,len);
}
