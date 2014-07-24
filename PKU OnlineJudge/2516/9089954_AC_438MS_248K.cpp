/* POJ 2516
 * SPFA+最小费用最大流
 * Memory:248K	Time:422MS
 */
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <queue>
using namespace std;
#define INF 16843009
int need[50][50],supply[50][50],cost[100][100];
int needK[50],supplyK[50],capacity[100][100],dis[100],pre[100];
int visited[100],result,N,M,K;
int spfa()
{
	int u,i;
	queue<int> q;
	memset(dis,1,sizeof(dis));
	memset(visited,0,sizeof(visited));
	dis[0]=0;
	q.push(0);
	while(!q.empty())
	{
		u=q.front();
		q.pop();
		visited[u]=1;
		for(i=0;i<=N+M+1;i++)
		{
			if(capacity[u][i]&&dis[i]>dis[u]+cost[u][i])
			{
				dis[i]=dis[u]+cost[u][i];
				pre[i]=u;
				if(!visited[i])
				{
					visited[i]=1;
					q.push(i);
				}
			}
		}
		visited[u]=0;
	}
	if(dis[N+M+1]>100000)return 0;
	return 1;
}
void end()
{
	int i,sum=INF;
	for(i=N+M+1;i!=0;i=pre[i])
	{
		if(sum>capacity[pre[i]][i])
			sum=capacity[pre[i]][i];
	}
	for(i=N+M+1;i!=0;i=pre[i])
	{
		capacity[pre[i]][i]-=sum;
		capacity[i][pre[i]]+=sum;
		result+=sum*cost[pre[i]][i];
	}
}
int main()
{
	int i,j,k,flag;
	while(scanf("%d%d%d",&N,&M,&K)!=EOF)
	{
		if(N==0)break;
		memset(needK,0,sizeof(needK));
		for(i=0;i<N;i++)
		{
			for(j=0;j<K;j++)
			{
				scanf("%d",&need[i][j]);
				needK[j]+=need[i][j];
			}
		}
		memset(supplyK,0,sizeof(supplyK));
		for(i=0;i<M;i++)
		{
			for(j=0;j<K;j++)
			{
				scanf("%d",&supply[i][j]);
				supplyK[j]+=supply[i][j];
			}
		}
		flag=1;
		for(i=0;i<K;i++)
		{
			if(supplyK[i]<needK[i])
			{
				flag=0;
				break;
			}
		}
		result=0;
		for(i=0;i<K;i++)
		{
			memset(capacity,0,sizeof(capacity));
			memset(cost,0,sizeof(cost));
			for(j=1;j<=N;j++)
			{
				for(k=1;k<=M;k++)
				{
					scanf("%d",&cost[k][j+M]);
					cost[j+M][k]=-cost[k][j+M];
					capacity[k][j+M]=INF;
				}
			}
			if(!flag)continue;
			for(j=1;j<=M;j++)
			{
				capacity[0][j]=supply[j-1][i];
			}
			for(j=M+1;j<=N+M;j++)
			{
				capacity[j][N+M+1]=need[j-M-1][i];
			}
			while(spfa()) end();
		}
		if(!flag)printf("-1\n");
		else printf("%d\n",result);
	}
	return 0;
}