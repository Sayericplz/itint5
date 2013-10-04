int maxConsSum2(const vector<int> &arr) {
	int len = arr.size(), sum = 0, maxv = 0,minv = 0;
	if(len < 1) return 0;
	int cur = 0;
	for(int i = 0; i < len;i++)
	{
		sum += arr[i];
		if(cur > 0)
			cur += arr[i];
		else
			cur = arr[i];
		if(cur > maxv) maxv = cur;
	}
	cur = 0;
	for(int i = 0; i < len;i++)
	{
		if(cur < 0)
			cur += arr[i];
		else
			cur = arr[i];
		if(cur < minv) minv = cur;
	}
	if(sum-minv > maxv) maxv = sum-minv;
	return maxv;
}