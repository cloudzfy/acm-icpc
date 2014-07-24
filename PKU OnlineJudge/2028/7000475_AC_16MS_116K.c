#include <stdio.h>
int main()
{
	int day[100][2],tmp,i,j,n,q,date,m;
	for(;;)
	{
		scanf("%d %d",&n,&q);
		if(n==0&&q==0) break;
		for(i=0;i<100;i++)
		{
			day[i][0]=0;
			day[i][1]=i+1;
		}
		for(i=0;i<n;i++)
		{
			scanf("%d",&m);
			for(j=0;j<m;j++)
			{
				scanf("%d",&date);
				day[date-1][0]++;
			}
		}
		for(i=0;i<100;i++)
		{
			for(j=i+1;j<100;j++)
			{
				if(day[i][0]<day[j][0]||(day[i][0]==day[j][0]&&day[i][1]>day[j][1]))
				{
					tmp=day[i][0];
					day[i][0]=day[j][0];
					day[j][0]=tmp;
					tmp=day[i][1];
					day[i][1]=day[j][1];
					day[j][1]=tmp;
				}
			}
		}
		if(day[0][0]>=q) printf("%d\n",day[0][1]);
		else printf("0\n");
	}
	return 0;
}