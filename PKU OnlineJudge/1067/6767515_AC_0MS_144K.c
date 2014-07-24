#include <stdio.h>
#include <math.h>
int main()
{
	int a,b,tmp;
	double s;
	while(scanf("%d %d",&a,&b)!=EOF)
	{
		if(a>b)
		{
			tmp=a;
			a=b;
			b=tmp;
		}
		s=sqrt(5.0);
		if(a==(int)((b-a)*(s+1)/2)) printf("0\n");
		else printf("1\n");
	}
	return 0;
}