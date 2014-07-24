#include <stdio.h>
#include <string.h>
int main()
{
	int i,j,m,n,x,map[500][500],mark[500],dis[500],t,result;
	scanf("%d",&t);
	while(t--)
	{
		result=0;
		scanf("%d",&n);
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				scanf("%d",&map[i][j]);
			}
		}
		memset(mark,0,sizeof(mark));
		dis[0]=0;
		for(i=1;i<n;i++)
			dis[i]=70000;
		for(i=0;i<n;i++)
		{
			m=70000;
			for(j=0;j<n;j++)
			{
				if(mark[j]==0&&dis[j]<m)
				{
					m=dis[j];
					x=j;
				}
			}
			if(result<m)result=m;
			mark[x]=1;
			for(j=0;j<n;j++)
			{
				if(mark[j]==0&&dis[j]>map[x][j])
					dis[j]=map[x][j];
			}
		}
		printf("%d\n",result);
	}
	return 0;
}