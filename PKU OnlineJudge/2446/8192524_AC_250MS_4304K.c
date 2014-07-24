#include <stdio.h>
#include <string.h>

int visited[1025],match[1025],map[1025][1025],n,m;

int dfs(int k)
{
	int i;
	if(k>n)
		i=k-n;
	else
		i=1;
	for(;i<=k+n&&i<=m*n;i++)
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
	int k,x,y,hole[33][33],num,result,i,j;
	scanf("%d%d%d",&m,&n,&k);
	num=m*n-k;
	memset(hole,0,sizeof(hole));
	memset(match,0,sizeof(match));
	memset(map,0,sizeof(map));
	for(i=0;i<k;i++)
	{
		scanf("%d%d",&y,&x);
		hole[x][y]=1;
	}
	if(num%2==1)
	{
		printf("NO\n");
		return 0;
	}
	for(i=1;i<=m;i++)
	{
		for(j=1;j<=n;j++)
		{
			if(hole[i][j]) continue;
			if(i>1&&!hole[i-1][j])
				map[(i-1)*n+j][(i-2)*n+j]=1;
			if(j>1&&!hole[i][j-1])
				map[(i-1)*n+j][(i-1)*n+j-1]=1;
			if(i<m&&!hole[i+1][j])
				map[(i-1)*n+j][i*n+j]=1;
			if(j<n&&!hole[i][j+1])
				map[(i-1)*n+j][(i-1)*n+j+1]=1;
		}
	}
	result=0;
	for(i=1;i<=m*n;i++)
	{
		memset(visited,0,sizeof(visited));
		if(hole[(i-1-(i-1)%n)/n+1][(i-1)%n+1]) continue;
		if(dfs(i)) result++;
	}
	if(result==num)
	{
		printf("YES\n");
	}
	else
	{
		printf("NO\n");
	}
	return 0;
}