int findMinAllOne(int a) {
	if(a % 2 == 0 || a % 5 == 0) return -1;
	int b = 1,len = 1;
	set<int> mark;
	while(1)
	{
		b %= a;
		if(!b) return len;
		if(mark.find(b) != mark.end()) return -1;
		mark.insert(b);
		b = b*10+1;
		len ++; 
	}
}