int count(vector<int>& preorder, vector<int>& postorder,int s1,int e1, int s2,int e2)
{
	if(s1 > e1) return 1;
	if(preorder[s1] == postorder[e2]) return 2 * count(preorder,postorder,s1+1,e1,s2,e2-1);
	for(int i = s2;i <= e2;i++)
	{
		if(postorder[i] == preorder[s1])
			return count(preorder,postorder,s1+1,s1+i-s2,s2,i-1)
					*count(preorder,postorder,s1+i-s2+2,e1,i+1,e2-1);
	}
}

int countValidTrees(vector<int>& preorder, vector<int>& postorder) {
	int n = preorder.size();
	if(!n) return 0;
	return count(preorder,postorder,1,n-1,0,n-2);
}

