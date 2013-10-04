int maxConsSum(const vector<int> &arr) {
	int maxv = 0, len = arr.size();
	if(len < 1) return maxv;
	int cur = arr[0];
	if(cur > maxv) maxv = cur;
	for(int i = 1; i < len;i++)
	{
		if(cur > 0)
			cur += arr[i];
		else
			cur = arr[i];
		if(cur > maxv) maxv = cur;
	}
	return maxv;
}