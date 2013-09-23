bool next_permutation(vector<int> &arr) {
	int len = arr.size();
	if(len < 2) return false;
	int last = arr[len-1],i;
	for(i = len-2; i >= 0;i--)
	{
		if(arr[i] < last) break;
	}
	if(i == -1) return false;
	last = arr[i];
	arr[i] = arr[len-1];
	arr[len-1] = last;
	for(int j = i+1,k=len-1;j<k;j++,k--)
	{
		last = arr[j];
		arr[j] = arr[k];
		arr[k] = last;
	}
	return true;
}