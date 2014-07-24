#include <iostream>
#include <cstring>
#include <queue>
using namespace std;
int f[201][201],g[201][201];

int EK(int s,int t,int m)
{
	queue<int> q;
	int pre[201],r[201],result,u,v;
	memset(f,0,sizeof(f));
	result=0;
	while(1)
	{
		memset(r,0,sizeof(r));
		r[1]=10000001;
		q.push(s);
		while(!q.empty())
		{
			u=q.front();
			q.pop();
			for(v=1;v<=m;v++)
			{
				if(!r[v]&&g[u][v]>f[u][v])
				{
					pre[v]=u;
					q.push(v);
					if(r[u]<g[u][v]-f[u][v]) r[v]=r[u];
					else r[v]=g[u][v]-f[u][v];
				}
			}
		}
		if(r[t]==0) break;
		for(u=t;u!=s;u=pre[u])
		{
			f[pre[u]][u]+=r[t];
			f[u][pre[u]]-=r[t];
		}
		result+=r[t];
	}
	return result;
}

int main()
{
	int n,m,x,y,c,result;
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		memset(g,0,sizeof(g));
		while(n--)
		{
			scanf("%d%d%d",&x,&y,&c);
			g[x][y]+=c;
		}
		result=EK(1,m,m);
		printf("%d\n",result);
	}
	return 0;
}