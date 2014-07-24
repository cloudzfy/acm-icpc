#include <stdio.h>
#include <string.h>
char type[2000][8];
int map[2000][2000];

int size(i,j)
{
	int k,size=0;
	for(k=0;k<7;k++)
	{
		if(type[i][k]!=type[j][k])size++;
	}
	return size;
}

int main()
{
	int i,j,x,n,m,mark[2000],dis[2000],result;
	while(scanf("%d",&n)!=EOF)
	{
		if(n==0) break;
		result=0;
		for(i=0;i<n;i++)
			scanf("%s",type[i]);
		for(i=0;i<n;i++)
		{
			map[i][i]=0;
			for(j=i+1;j<n;j++)
			{
				map[i][j]=size(i,j);
				map[j][i]=map[i][j];
			}
		}
		memset(mark,0,sizeof(mark));
		dis[0]=0;
		for(i=1;i<n;i++)
			dis[i]=10;
		for(i=0;i<n;i++)
		{
			m=10;
			for(j=0;j<n;j++)
			{
				if(mark[j]==0&&dis[j]<m)
				{
					m=dis[j];
					x=j;
				}
			}
			result+=m;
			mark[x]=1;
			for(j=0;j<n;j++)
			{
				if(mark[j]==0&&dis[j]>map[x][j])
					dis[j]=map[x][j];
			}
		}
		printf("The highest possible quality is 1/%d.\n",result);
	}
	return 0;
}