#include <stdio.h>
#include <string.h>

int map[501][501],match[501],visited[501],n;

int dfs(int k)
{
	int i;
	for(i=1;i<=n;i++)
	{
		if(!visited[i]&&map[k][i])
		{
			visited[i]=1;
			if(!match[i]||dfs(match[i]))
			{
				match[i]=k;
				return 1;
			}
		}
	}
	return 0;
}
int main()
{
	int m,a,b,i,j,k,result;
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		if(n==0&&m==0) break;
		memset(map,0,sizeof(map));
		memset(match,0,sizeof(match));
		while(m--)
		{
			scanf("%d%d",&a,&b);
			map[a][b]=1;
		}
		for(k=1;k<=n;k++)
		{
			for(i=1;i<=n;i++)
			{
				for(j=1;j<=n;j++)
				{
					if(map[i][k]+map[k][j]==2)
					{
						map[i][j]=1;
					}
				}
			}
		}
		result=0;
		for(i=1;i<=n;i++)
		{
			memset(visited,0,sizeof(visited));
			if(dfs(i)) result++;
		}
		printf("%d\n",n-result);
	}
	return 0;
}