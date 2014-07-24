#include <stdio.h>
#include <string.h>
int map[1001][501],match[501][1001],visited[501],mid,n,m;
int dfs(int k)
{
	int i,j,v;
	for(i=1;i<=m;i++)
	{
		if(map[k][i]&&!visited[i])
		{
			visited[i]=1;
			if(match[i][0]<mid)
			{
				match[i][++match[i][0]]=k;
				return 1;
			}
			else
			{
				for(j=1;j<=mid;j++)
				{
					if(dfs(match[i][j]))
					{
						match[i][j]=k;
						return 1;
					}
				}
			}
		}
	}
	return 0;
}

int multimatch()
{
	int i;
	for(i=1;i<=m;i++)
		match[i][0]=0;
	for(i=1;i<=n;i++)
	{
		memset(visited,0,sizeof(visited));
		if(!dfs(i))
			return 0;
	}
	return 1;
}

int main()
{
	int f,i,left,right;
	char tmp[16];
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		if(n==0&&m==0) break;
		memset(map,0,sizeof(map));
		for(i=1;i<=n;i++)
		{
			scanf("%s",tmp);
			while(1)
			{
				scanf("%d",&f);
				map[i][f+1]=1;
				if(getchar()=='\n')break;
			}
		}
		left=1;
		right=n;
		while(left<right)
		{
			mid=(left+right)/2;
			if(multimatch())
				right=mid;
			else
				left=mid+1;
		}
		printf("%d\n",right);
	}
	return 0;
}