/* POJ 1273
 * Dinic算法
 */

#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <queue>
using namespace std;

int map[200][200],level[200],used[200],m;
int bfs(int s,int t)
{
	int u,i;
	queue<int> q;
	q.push(s);
	while(!q.empty())
	{
		u=q.front();
		q.pop();
		for(i=0;i<m;i++)
		{
			if(level[i]==-1&&map[u][i])
			{
				level[i]=level[u]+1;
				q.push(i);
			}
		}
	}
	if(level[t]==-1)return 0;
	return 1;
}

int dfs(int s,int t,int limit)
{
	int flow=0,tmp,i;
	if(s==t)return limit;
	used[s]=1;
	for(i=0;i<m;i++)
	{
		if(level[i]-level[s]==1&&map[s][i]&&!used[i])
		{
			tmp=dfs(i,t,min(limit,map[s][i]));
			limit-=tmp;
			map[s][i]-=tmp;
			map[i][s]+=tmp;
			flow+=tmp;
			if(!limit)break;
		}
	}
	used[s]=0;
	return flow;
}
int dinic()
{
	int flow=0,tmp;
	while(1)
	{
		memset(level,-1,sizeof(level));
		level[0]=0;
		if(!bfs(0,m-1)) return flow;
		memset(used,0,sizeof(used));
		tmp=dfs(0,m-1,1000000);
		if(!tmp)return flow;
		flow+=tmp;
	}
}
int main()
{
	int n,ans,s,e,c;
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		memset(map,0,sizeof(map));
		while(n--)
		{
			scanf("%d%d%d",&s,&e,&c);
			map[s-1][e-1]+=c;
		}
		ans=dinic();
		printf("%d\n",ans);
	}
	return 0;
}