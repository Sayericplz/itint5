//使用getLeftChildNode(TreeNode)获得左儿子结点
//使用getRightChildNode(TreeNode)获得右儿子结点
//使用isNullNode(TreeNode)判断结点是否为空
int height(TreeNode node)
{
	int h = 0;
	while(!isNullNode(node))
	{
		h++;
		node = getLeftChildNode(node);
	}
	return h;
}

int count_complete_binary_tree_nodes(TreeNode root) {
	if(isNullNode(root)) return 0;
	int hleft = height(getLeftChildNode(root));
	int hright = height(getRightChildNode(root));
	return hleft==hright?(1<<hleft)+count_complete_binary_tree_nodes(getRightChildNode(root)):(1<<hright)+count_complete_binary_tree_nodes(getLeftChildNode(root));
}