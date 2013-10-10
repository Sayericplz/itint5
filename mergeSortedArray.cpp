void mergeSortedArray(int arr1[], int arr2[], int n, int m) {
	int t = n+m-1;
	n --;m --;
	while(m >= 0 && n >= 0)
	{
		if(arr1[n] <= arr2[m])
			arr1[t--] = arr2[m--];
		else
			arr1[t--] = arr1[n--]; 
	}
	if(m >= 0)
	{
		for(int i = 0;i <= m;i++)
			arr1[i] = arr2[i];
	}
}