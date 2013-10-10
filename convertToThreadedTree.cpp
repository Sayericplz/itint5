/*树结点的定义(请不要在代码中定义该结构)
struct TreeNode {
  TreeNode *left, *right;
  bool isLeftThread, isRightThread;
}*/
#include <stack>
void convertToThreadedTree(TreeNode *root) {
	stack<TreeNode*> s;
	if(!root) return;
	s.push(root);
	TreeNode *pre = NULL,*p = root->left;
	while(!s.empty())
	{
		if(p)
		{
			s.push(p);
			p = p->left;
		}
		else
		{
			p = s.top();
			s.pop();
			if(!p->left)
			{
				p->left = pre;
				p->isLeftThread = true;
			}
			if(p->right)
			{
				s.push(p->right);
				pre = p;
				p = p->right->left;
			}
			else
			{
				if(!s.empty())
				{
					p->right = s.top();
					pre = p;
				}
				else
				{
					p->right = NULL;
					pre = p;
				}
				p->isRightThread = true;
				p = NULL;
			}
		}
	}
}