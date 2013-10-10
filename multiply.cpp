//返回a*b的结果
string multiply(const string& a, const string& b) {
	bool neg = false;
	string ta(a),tb(b);
	if(a[0] == '-')
	{
		ta = ta.substr(1);
		neg = !neg;
	}
	if(b[0] == '-')
	{
		tb = tb.substr(1);
		neg = !neg;
	}
	int alen = ta.size(),blen = tb.size();
	vector<int> res(alen+blen,0);
	for(int i = 0;i < alen;i++)
	{
		for(int j = 0;j < blen;j++)
		{
			res[alen-i+blen-j-2] += (ta[i]-48) * (tb[j]-48);
		}
	}
	for(int i = 0;i < alen+blen-1;i++)
	{
		res[i+1] += res[i]/10;
		res[i] %= 10;
	}
	int end = alen+blen-1;
	while( end >= 0 && res[end] == 0) end--;
	if(end == -1) return "0";
	string s = "";
	if(neg) s += '-';
	for(int i = end;i >= 0;i--)
		s += res[i] + 48;
	return s;
}