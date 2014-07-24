#include <stdio.h>
int main()
{
	int day[100],i,j,n,q,date,m;
	for(;;)
	{
		scanf("%d %d",&n,&q);
		if(n==0&&q==0) break;
		for(i=0;i<100;i++)
		{
			day[i]=0;
		}
		for(i=0;i<n;i++)
		{
			scanf("%d",&m);
			for(j=0;j<m;j++)
			{
				scanf("%d",&date);
				day[date-1]++;
			}
		}
		for(i=0;i<100;i++)
		{
			if(day[i]==n) break;
		}
		if(day[i]!=n)
		{
			for(i=0;i<100;i++)
			{
				if(day[i]>=q) break;
			}
		}
		if(day[i]>=q) printf("%d\n",i+1);
		else printf("0\n");
	}
	return 0;
}