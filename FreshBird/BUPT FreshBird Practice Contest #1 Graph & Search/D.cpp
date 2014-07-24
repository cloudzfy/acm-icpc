#include <stdio.h>
#include <string.h>
int map[201][201],match[201],visited[201],n,m;
int dfs(int k)
{
	int i;
	for(i=1;i<=m;i++)
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
	int result,s,p,i,j;
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		memset(match,0,sizeof(match));
		memset(map,0,sizeof(map));
		for(i=0;i<n;i++)
		{
			scanf("%d",&s);
			for(j=0;j<s;j++)
			{
				scanf("%d",&p);
				map[i+1][p]=1;
			}
		}
		result=0;
		for(i=1;i<=n;i++)
		{
			memset(visited,0,sizeof(visited));
			if(dfs(i))result++;
		}
		printf("%d\n",result);
	}
	return 0;
}