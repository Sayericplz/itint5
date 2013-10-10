int gcd(int a,int b)
{
	return b?gcd(b,a%b):a;
}

bool canJump(int p, int q, int x, int y, int x2, int y2) {
	if(p == 0 && q == 0) return x==x2&&y==y2;
	int c = gcd(p,q);
	int x1 = x2-x;
	int y1 = y2-y;
	if(x1%c) return false;
	if(y1%c) return false;
	p /= c;
	q /= c;
	x1 /= c;
	y1 /= c;
	if((p-q)%2) return true;
	return (x1-y1)%2==0;
}