#include <stdio.h>
#include <string.h>
int map[100][100],visited[100],match[100],n,m;
int dfs(int r)
{
	int i;
	for(i=1;i<m;i++)
	{
		if(!visited[i]&&map[r][i])
		{
			visited[i]=1;
			if(!match[i]||dfs(match[i]))
			{
				match[i]=r;
				return 1;
			}
		}
	}
	return 0;
}

int main()
{
	int k,job,x,y,i,result;
	while(scanf("%d",&n)!=EOF)
	{
		if(n==0) break;
		scanf("%d%d",&m,&k);
		memset(map,0,sizeof(map));
		memset(match,0,sizeof(match));
		for(i=0;i<k;i++)
		{
			scanf("%d%d%d",&job,&x,&y);
			map[x][y]=1;
		}
		result=0;
		for(i=1;i<n;i++)
		{
			memset(visited,0,sizeof(visited));
			if(dfs(i)) result++;
		}
		printf("%d\n",result);
	}
	return 0;
}