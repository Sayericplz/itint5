//返回结点node1和node2的最近公共祖先
int height(TreeNode *node)
{
	int h = 0;
	TreeNode *tmp = node;
	while(tmp)
	{
		h++;
		tmp = tmp->parent;
	}
	return h;
}


TreeNode *getLCA(TreeNode *node1, TreeNode *node2) {
	if(!node1 || !node2) return NULL;
	int h1 = height(node1);
	int h2 = height(node2);
	int step = 0;
	if(h1 > h2)
	{
		while(step < h1-h2)
		{
			node1 = node1->parent;
			step++;
		}
	}
	else
	{
		while(step < h2-h1)
		{
			node2 = node2->parent;
			step++;
		}
	}
	while(node1 != node2)
	{
		node1 = node1->parent;
		node2 = node2->parent;
	}
	return node1;
}