/* POJ 1273
 * 最大流 SAP模板
 * Memory:336K	Time:16MS
 */

#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <queue>
using namespace std;
#define INF 2000000000
#define MAXN 200
int h[MAXN];/*距离标号，h[i]表示从i结点到汇点最短距离路径经过的结点数*/
int num[MAXN];/*记录距离标号为i的结点个数num[i]*/
int pre[MAXN];/*记录路径*/
int g[MAXN][MAXN];

void getMark(int end)/*获得距离标号*/
{
	int u,v;
	queue<int> q;
	memset(h,0,sizeof(h));
	memset(num,0,sizeof(num));
	q.push(end);
	while(!q.empty())
	{
		u=q.front();
		q.pop();
		for(v=0;v<end;v++)
		{
			if(!h[v]&&g[v][u]>0)
			{
				h[v]=h[u]+1;
				num[h[v]]++;
				q.push(v);
			}
		}
	}
}

int findAllowArc(int i,int end)/*寻找i结点的允许弧*/
{
	int j;
	for(j=0;j<=end;j++)
	{
		if(g[i][j]>0&&h[i]==h[j]+1)
			return j;
	}
	return -1;/*没有允许弧*/
}

int reLabel(int i,int end)/*从新寻找i的距离标号*/
{
	int j,m=INF;
	for(j=0;j<=end;j++)
	{
		if(g[i][j]>0)
		{
			m=min(m,h[j]+1);
		}
	}
	if(m!=INF) return m;
	return end+1;
}

int getMaxFlow(int begin,int end)/*获取最大网络流*/
{
	int i,j,flow=0,d;
	memset(pre,-1,sizeof(pre));
	getMark(end);/*初始化距离标号*/
	num[0]=end+1;
	i=begin;/*从源点开始沿最短路增流*/
	while(h[begin]<=end)
	{
		j=findAllowArc(i,end);/*找i的允许弧*/
		if(j>=0)/*存在允许弧*/
		{
			pre[j]=i;/*记录路径*/
			i=j;
			if(i==end)/*找到汇点，一条最短路径找到，则增流*/
			{
				d=INF;
				i=end;
				while(i!=begin)
				{
					d=min(d,g[pre[i]][i]);
					i=pre[i];
				}
				i=end;
				while(i!=begin)
				{
					g[pre[i]][i]-=d;
					g[i][pre[i]]+=d;
					i=pre[i];
				}
				flow+=d;
			}
		}
		else/*i不存在允许弧,则需要重新更新距离标号,以求找到允许弧 */
		{
			if(num[h[i]]==0) return flow;/*GAP优化*/
			num[h[i]]--;
			h[i]=reLabel(i,end);/*重新寻找*/
			num[h[i]]++;
			if(i!=begin) i=pre[i];/*当i不为源点时，重新更新i的距离标号后,再重新从i找一遍允许弧 */
		}
	}
	return flow;
}

int main()
{
	int n,m,ans,s,e,c;
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		memset(g,0,sizeof(g));
		while(n--)
		{
			scanf("%d%d%d",&s,&e,&c);
			g[s-1][e-1]+=c;
		}
		ans=getMaxFlow(0,m-1);
		printf("%d\n",ans);
	}
	return 0;
}