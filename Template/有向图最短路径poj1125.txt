#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int mark[101],g[101][101],n;
void search(int i)
{
	int j;
	for(j=1;j<=n;j++)
	{
		if(i==j) continue;
		if(g[i][j]!=-1&&mark[i]+g[i][j]<mark[j])
		{
			mark[j]=mark[i]+g[i][j];
			search(j);
		}
	}
}
int main()
{
	int p,t,i,j,k,min,max,x;
	for(;;)
	{
		scanf("%d",&n);
		if(n==0) break;
		memset(g,-1,sizeof(g));
		min=-1;
		for(i=0;i<n;i++)
		{
			scanf("%d",&k);
			for(j=0;j<k;j++)
			{
				scanf("%d%d",&p,&t);
				g[i+1][p]=t;
			}
		}
		if(n==1)
		{
			printf("1 0\n");
			continue;
		}
		for(i=1;i<=n;i++)
		{
			for(j=0;j<=n;j++)
				mark[j]=1000000;
			mark[i]=0;
			search(i);
			max=-1;
			for(j=1;j<=n;j++)
			{
				if(i==j) continue;
				if(mark[j]==1000000)
				{
					max=-1;
					break;
				}
				if(mark[j]>max)
					max=mark[j];
			}
			if((min>max&&max!=-1)||(min==-1))
			{
				min=max;
				x=i;
			}
		}
		if(min==-1) printf("disjoint\n");
		else printf("%d %d\n",x,min);
	}
	return 0;
}