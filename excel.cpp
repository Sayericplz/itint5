//将十进制数转换为excel数
string decToExcel(int decNum) {
	string res = "";
	while(decNum)
	{
		int ex = (decNum-1)%26;
		char c = ex+65;
		res = c + res;
		decNum = (decNum-1)26;
	}
	return res;
}
//将excel数转换为十进制数
int excelToDec(string excelNum) {
	int res = 0;
	for(int i = 0;i < excelNum.size();i++)
	{
		int tmp = excelNum[i]-64;
		res = res*26+tmp;
	}
	return res;
}