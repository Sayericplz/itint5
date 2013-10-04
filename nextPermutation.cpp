#include <limits.h>

void swap(int &x,int &y)
{
	int tmp = x;
	x = y;
	y = tmp;
}

bool next_permutation(vector<int> &arr) {
	int len = arr.size();
	if(len < 2) return false;
	int left = 0,right = len-1,i;
	bool flag = false;
	for(i = len-2; i >= 0;i -- )
	{
		int minv = INT_MAX;
		for(int j = i+1; j < len;j++)
		{
			if(arr[j] > arr[i] && arr[j] < minv)
			{
				minv = arr[j];
				left = i;
				right = j;
				flag = true;
			}
		}
		if(flag) break;
	}
	if(i == -1) return false;
	swap(arr[left],arr[right]);
	for(int j = left+1,k = len-1; j < k; j++,k--)
		swap(arr[j],arr[k]);
	return true;
}