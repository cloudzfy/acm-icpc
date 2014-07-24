#include <stdio.h>
int main()
{
	int r,x,y;
	scanf("%x,%d,%d",&r,&x,&y);
	r=r&~(1<<(x));
	r=r|(1<<(y));
	r=r|(1<<(y-1));
	r=r&~(1<<(y-2));
	printf("%x\n",r);
	return 0;
}