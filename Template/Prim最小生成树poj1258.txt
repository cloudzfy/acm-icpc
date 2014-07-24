#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main()
{
	int m,result,x,i,j,n,map[100][100],dist[100],mark[100];
	while(scanf("%d",&n)!=EOF)
	{
		result=0;
		memset(mark,0,sizeof(mark));
		for(i=0;i<n;i++)
			dist[i]=111111;
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				scanf("%d",&map[i][j]);
			}
		}
		dist[0]=0;
		for(i=0;i<n;i++)
		{
			m=111111;
			for(j=0;j<n;j++)
			{
				if(mark[j]==0&&dist[j]<m)
				{
					x=j;
					m=dist[j];
				}
			}
			result+=m;
			mark[x]=1;
			for(j=0;j<n;j++)
			{
				if(mark[j]==0&&dist[j]>map[x][j])
					dist[j]=map[x][j];
			}
		}
		printf("%d\n",result);
	}
	return 0;
}