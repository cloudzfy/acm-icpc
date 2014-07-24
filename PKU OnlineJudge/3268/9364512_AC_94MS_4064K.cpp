/* POJ 3268
 * 图论：Dijkstra
 * Memory:4064K	Time:63MS
 */

#include <stdio.h>
#include <string.h>
#define INF 16843009
#define MAXN 1000
int map[MAXN][MAXN],visited[MAXN],dis[MAXN],N,ans[MAXN];
void dijkstra(int v0)
{
	int i,j,min,mark;
	memset(visited,0,sizeof(visited));
	memset(dis,1,sizeof(dis));
	dis[v0]=0;
	visited[v0]=1;
	for(i=0;i<N;i++)
	{
		if(map[v0][i]!=INF)dis[i]=map[v0][i];
	}
	for(i=0;i<N-1;i++)
	{
		min=1000000;
		for(j=0;j<N;j++)
		{
			if(!visited[j]&&min>dis[j])
			{
				min=dis[j];
				mark=j;
			}
		}
		visited[mark]=1;
		for(j=0;j<N;j++)
		{
			if(!visited[j]&&map[mark][j]+dis[mark]<dis[j])
			{
				dis[j]=dis[mark]+map[mark][j];
			}
		}
	}
}


int main()
{
	int i,j,tmp,M,X,A,B,T,result;
	scanf("%d%d%d",&N,&M,&X);
	memset(map,1,sizeof(map));
	for(i=0;i<M;i++)
	{
		scanf("%d%d%d",&A,&B,&T);
		map[A-1][B-1]=T;
	}
	dijkstra(X-1);
	for(i=0;i<N;i++)
	{
		ans[i]=dis[i];
	}
	for(i=0;i<N;i++)
	{
		for(j=i+1;j<N;j++)
		{
			tmp=map[i][j];
			map[i][j]=map[j][i];
			map[j][i]=tmp;
		}
	}
	dijkstra(X-1);
	result=0;
	for(i=0;i<N;i++)
	{
		if(result<ans[i]+dis[i])
			result=ans[i]+dis[i];
	}
	printf("%d\n",result);
	return 0;
}