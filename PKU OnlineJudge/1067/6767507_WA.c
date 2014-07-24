#include <stdio.h>
int main()
{
	int a,b,tmp;
	while(scanf("%d %d",&a,&b)!=EOF)
	{
		if(a>b)
		{
			tmp=a;
			a=b;
			b=tmp;
		}
		if(a==(int)((b-a)*3.236/2.0)) printf("0\n");
		else printf("1\n");
	}
	return 0;
}