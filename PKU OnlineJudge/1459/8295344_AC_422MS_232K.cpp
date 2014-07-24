#include <iostream>
#include <queue>
using namespace std;
int f[102][102],g[102][102];

int EK(int s,int t,int m)
{
	queue<int> q;
	memset(f,0,sizeof(f));
	int pre[102],r[102],u,v,result=0;
	while(1)
	{
		memset(r,0,sizeof(r));
		r[100]=100000;
		q.push(s);
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
						r[v]=r[u];
					else
						r[v]=g[u][v]-f[u][v];
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
	char str[50];
	int n,np,nc,m,u,v,z,result;
	while(scanf("%d%d%d%d",&n,&np,&nc,&m)!=EOF)
	{
		memset(g,0,sizeof(g));
		while(m--)
		{
			scanf("%s",str);
			sscanf(str,"(%d,%d)%d",&u,&v,&z);
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
		result=EK(100,101,101);
		printf("%d\n",result);
	}
	return 0;
}