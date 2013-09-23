int isValidSudoku(int arr[]) {
	bool f[10];
	for(int i = 0;i < 10; i++)
		f[i] = false;
	for(int i = 0;i < 9;i++)
	{
		for(int j = 0;j < 9;j++)
		{
			int n = arr[i*9+j];
			if(n < 1 || n > 9 || f[n])
				return 0;
			f[n] = true;
		}
		for(int j = 0;j < 10;j++)
			f[j] = false;
	}
	for(int i = 0;i < 9;i++)
	{
		for(int j = 0;j < 9;j++)
		{
			int n = arr[j*9+i];
			if(n < 1 || n > 9 || f[n])
				return 0;
			f[n] = true;
		}
		for(int j = 0;j < 10;j++)
			f[j] = false;
	}
	int inc1 = 0, inc2 = 0;
	for(int i = 0;i < 9;i++)
	{
		for(int j = 0;j < 9;j++)
		{
			int n = arr[i*3+j+inc1+inc2];
			if(n < 1|| n > 9 || f[n])
				return 0;
			f[n] = true;
			if(j % 3 == 2) inc2+=6;
		}
		if(i % 3 == 2) inc1+=18;
		inc2 = 0;
		for(int j = 0;j < 10;j++)
			f[j] = false;
	}
	return 1;
}