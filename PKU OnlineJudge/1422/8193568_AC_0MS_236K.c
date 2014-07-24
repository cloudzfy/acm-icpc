#include <stdio.h>
#include <string.h>

int map[121][121],visited[121],match[121],no_of_intersections,no_of_streets;

int dfs(int k)
{
	int i;
	for(i=1;i<=no_of_intersections;i++)
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
	int t,i,s,e,result;
	scanf("%d",&t);
	while(t--)
	{
		memset(map,0,sizeof(map));
		memset(match,0,sizeof(match));
		scanf("%d%d",&no_of_intersections,&no_of_streets);
		for(i=0;i<no_of_streets;i++)
		{
			scanf("%d%d",&s,&e);
			map[s][e]=1;
		}
		result=0;
		for(i=1;i<=no_of_intersections;i++)
		{
			memset(visited,0,sizeof(visited));
			if(dfs(i)) result++;
		}
		printf("%d\n",no_of_intersections-result);
	}
	return 0;
}