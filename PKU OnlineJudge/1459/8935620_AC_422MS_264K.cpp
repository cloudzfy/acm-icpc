/*
 * 简单题：网络流
 */
#include <stdio.h>
#include <queue>
#include <algorithm>
#include <string.h>
using namespace std;
int g[102][102],f[102][102],n,result;
void EK(int s,int t)
{
	int r[102],pre[102],u,v;
	queue<int> q;
	while(1)
	{
		memset(r,0,sizeof(r));
		r[100]=100000;//初始化源点流量
		q.push(s);//BFS搜索
		while(!q.empty())
		{
			u=q.front();
			q.pop();
			for(v=0;v<=t;v++)
			{
				if(!r[v]&&g[u][v]>f[u][v])
				{
					q.push(v);
					pre[v]=u;
					if(r[u]<g[u][v]-f[u][v])
					{
						r[v]=r[u];//可提供的流量
					}
					else
					{
						r[v]=g[u][v]-f[u][v];//可被使用的流量
					}
				}
			}
		}
		if(r[t]==0) break;
		for(v=t;v!=s;v=pre[v])
		{
			f[pre[v]][v]+=r[t];//以最终流到终点的流量为准
			f[v][pre[v]]-=r[t];
		}
		result+=r[t];
	}
}
int main()
{
	int np,nc,m,u,v,z;
	char str[50];
	while(scanf("%d%d%d%d",&n,&np,&nc,&m)!=EOF)
	{
		memset(g,0,sizeof(g));
		while(m--)
		{
			scanf("%s",str);//必须事先读取到字符串
			sscanf(str,"(%d,%d)%d",&u,&v,&z);//使用sscanf
			g[u][v]=z;
		}
		while(np--)
		{
			scanf("%s",str);
			sscanf(str,"(%d)%d",&u,&z);
			g[100][u]=z;

		}
		while(nc--)
		{
			scanf("%s",str);
			sscanf(str,"(%d)%d",&u,&z);
			g[u][101]=z;
		}
		memset(f,0,sizeof(f));//注意初始化
		result=0;
		EK(100,101);//Edmonds-Karp算法
		printf("%d\n",result);
	}
	return 0;
}