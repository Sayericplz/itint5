bool isInterleaving(string &str1, string &str2, string &str3) {
	int len1 = str1.size(), len2 = str2.size(), len3 = str3.size();
	if(len1 + len2 != len3) return false;
	vector<vector<bool> > flag(len1+1,vector<bool>(len2+1,false));
	flag[0][0] = true;
	for(int i = 1;i <= len1;i++)
		flag[i][0] = str1[i-1] == str3[i-1];
	for(int i = 1;i <= len2;i++)
		flag[0][i] = str2[i-1] == str3[i-1];
	for(int i = 1;i <= len1;i++)
	{
		for(int j = 1;j <= len2;j++)
		{
			flag[i][j] = (flag[i-1][j] && str1[i-1]==str3[i+j-1])||(flag[i][j-1] && str2[j-1]==str3[i+j-1]);
		}
	}
	return flag[len1][len2];
}