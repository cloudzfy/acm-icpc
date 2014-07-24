#include <stdio.h>
int main()
{
	int a1,a2,b1,b2,c1,c2;
	scanf("%d%d%d",&a1,&b1,&c1);
	scanf("%d%d%d",&a2,&b2,&c2);
	if(a1==0&&b1==0&&a2==0&&b2==0)
	{
		if(c1!=0||c2!=0)
		{
			printf("0\n");
		}
		else
		{
			printf("-1\n");
		}
	}
	else if(a1==0&&b1==0)
	{
		if(c1==0)printf("-1\n");
		else printf("0\n");
	}
	else if(a2==0&&b2==0)
	{
		if(c2==0)printf("-1\n");
		else printf("0\n");
	}
	else if(a1==0&&a2==0)
	{
		if(b2*c1!=c2*b1)
		{
			printf("0\n");
		}
		else
		{
			printf("-1\n");
		}
	}
	else if(b1==0&&b2==0)
	{
		if(a2*c1!=c2*a1)
		{
			printf("0\n");
		}
		else
		{
			printf("-1\n");
		}
	}
	else if(a1*b2==b1*a2&&a1*c2==c1*a2)
	{
		printf("-1\n");
	}
	else if(a1*b2==b1*a2)
	{
		printf("0\n");
	}
	else
	{
		printf("1\n");
	}
	return 0;
}