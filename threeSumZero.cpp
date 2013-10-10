typedef tuple<int, int, int> ABC; //存放a,b,c三元组
//返回所有满足条件的(a,b,c)三元组
vector<ABC> threeSumZero(vector<int> &arr) {
	set<ABC> s;
	vector<ABC> res;
	if(arr.size() < 3) return res; 
	sort(arr.begin(),arr.end());
	for(int i = 0;i < arr.size()-2;i++)
	{
		int j = i+1,k = arr.size()-1;
		while(j < k)
		{
			int sum = arr[i] + arr[j] + arr[k];
			if(sum < 0 ||(j > i+1 && arr[j] == arr[j-1]))
				j++;
			else if(sum > 0 || (k < arr.size()-1 && arr[k] == arr[k+1]))
				k--;
			else 
			{
				ABC tmp(arr[i],arr[j],arr[k]);
				s.insert(tmp);
				j++;k--;
			}
		}
	}
	for(set<ABC>::iterator it = s.begin();it != s.end();it++)
		res.push_back(*it);
	return res;
}