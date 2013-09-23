#include <vector>
using namespace std;

int selectGasStation(const vector<int> &a, const vector<int> &g) {
	vector<int> b;
	int sum = 0,n = a.size();
	for(int i = 0;i < n;i++)
	{
		int tmp = a[i] - g[i];
		sum += tmp;
		b.push_back(tmp);	
	}
	for(int i = 0;i < n;i++)
		b.push_back(b[i]);
	if(sum < 0) return -1;
	int start = 0 ,step = 0;
	sum = 0;
	while(step < n && start < n)
	{
		sum += b[start+step];
		if(sum >= 0)
		{
			step++;
		}
		else
		{
			sum = 0;
			start = start+step+1;
			step = 0;
		}
	}
	if(step == n) return start;
	return -1; 
}