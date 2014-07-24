#include <stdio.h>
#include <string.h>
int map[101][301],visited[301],match[301],n;

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
	int p,t,c,s,i,j,result;
	scanf("%d",&t);
	while(t--)
	{
		memset(map,0,sizeof(map));
		memset(match,0,sizeof(match));
		scanf("%d%d",&p,&n);
		for(i=0;i<p;i++)
		{
			scanf("%d",&c);
			for(j=0;j<c;j++)
			{
				scanf("%d",&s);
				map[i+1][s]=1;
			}
		}
		result=0;
		for(i=1;i<=p;i++)
		{
			memset(visited,0,sizeof(visited));
			if(dfs(i)) result++;
		}
		if(result==p) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}