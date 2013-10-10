/*
树结点的定义(请不要在代码中定义该类型)
struct TreeNode {
    int val;
    vector<TreeNode*> children;  //该结点的儿子结点
 };
*/

int generate(TreeNode *node,int &len)
{
	int n = node->children.size();
	int maxlen;
	if(n == 0)
	{
		len = max(node->val,0);
		maxlen = len;
		return maxlen;
	}
	else if(n == 1)
	{
		int onelen;
		int submax = generate(node->children[0],onelen); 
		len = max(max(node->val,node->val + onelen),0);
		maxlen = max(submax,len);
		return maxlen;
	}
	int *clen = new int[n];
	int submax = 0;
	for(int i = 0;i < n;i++)
	{
		int tmp = generate(node->children[i],clen[i]);
		if(tmp > submax) submax = tmp;
	}
	sort(clen,clen+n);
	len = max(max(node->val,node->val+clen[n-1]),0);
	maxlen = max(max(submax,len),node->val+clen[n-2]+clen[n-1]);
	delete []clen;
	return maxlen;
}

int maxTreePathSum(TreeNode *root) {
	int len;
	if(!root) return 0;
	return generate(root,len);
}

