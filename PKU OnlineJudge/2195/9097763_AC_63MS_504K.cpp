/* POJ 2195
 * 最小费用最大流算法
 */
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <algorithm>
#include <queue>
using namespace std;
#define INF 16843009
char map[100][101];
int house[101][2],man[101][2],cost[202][202],result;
int dis[202],pre[202],visited[202],capacity[202][202];
int N;
int spfa()
{
	int u,v;
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
		for(v=0;v<=N;v++)
		{
			if(capacity[u][v]&&dis[v]>dis[u]+cost[u][v])
			{
				dis[v]=dis[u]+cost[u][v];
				pre[v]=u;
				if(!visited[v])
				{
					visited[v]=1;
					q.push(v);
				}
			}
		}
		visited[u]=0;
	}
	if(dis[N]==INF) return 0;
	return 1;
}

void end()
{
	int sum=INF,i;
	for(i=N;i!=0;i=pre[i])
	{
		if(sum>capacity[pre[i]][i])
			sum=capacity[pre[i]][i];
	}
	for(i=N;i!=0;i=pre[i])
	{
		capacity[pre[i]][i]-=sum;
		capacity[i][pre[i]]+=sum;
		result+=sum*cost[pre[i]][i];
	}
}

int main()
{
	int m,h,i,j,M;
	while(scanf("%d%d",&N,&M)!=EOF)
	{
		if(N==0&&M==0)break;
		m=1;
		h=1;
		for(i=0;i<N;i++)
		{
			scanf("%s",map[i]);
			for(j=0;map[i][j]!=0;j++)
			{
				if(map[i][j]=='H')
				{
					house[h][0]=i;
					house[h][1]=j;
					h++;
				}
				else if(map[i][j]=='m')
				{
					man[m][0]=i;
					man[m][1]=j;
					m++;
				}
			}
		}
		m--;
		h--;
		result=0;
		memset(cost,0,sizeof(cost));
		memset(capacity,0,sizeof(capacity));
		for(i=1;i<=h;i++)
		{
			for(j=1;j<=m;j++)
			{
				cost[i][j+h]=abs(house[i][0]-man[j][0])+abs(house[i][1]-man[j][1]);
				cost[j+h][i]=-cost[i][j+h];
				capacity[i][j+h]=INF;
			}
		}
		N=h+m+1;
		for(i=1;i<=h;i++)
		{
			capacity[0][i]=1;
		}
		for(i=h+1;i<=h+m;i++)
		{
			capacity[i][N]=1;
		}
		while(spfa())end();
		printf("%d\n",result);
	}
	return 0;
}