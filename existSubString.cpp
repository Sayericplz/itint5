#include <algorithm>
vector<string> strs;

// 预处理初始化
void initWithString(char *str) {
	strs.clear();
	int len = strlen(str);
	string s(str);
	for(int i = 0; i < len;i++)
	{
		string tmp = s.substr(i,min(len,i+10));
		if(!find(strs.begin(),strs.end(),tmp))
			strs.push_back(tmp);
	}
	sort(strs.begin(),strs.end());
}
// 如果query是str的字串,返回true,否则返回false
bool existSubString(char *query) {
	int n = strs.size();
	int l = 0,r = n-1;
	string q(query);
	while(l <= r)
	{
		int m = (l+r)/2;
		if(q.size() <= strs[m].size() && q == strs[m].substr(0,q.size()))
			return true;
		else if(q > strs[m])
			l = m+1;
		else
			r = m-1;
	}
	return false;
}