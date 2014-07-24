#include <iostream>
#include <cstring>
#include <queue>
using namespace std;
int f[102][102],g[102][102];

int EK(int s,int t,int m)
{
	int pre[102],r[102],result=0,u,v;
	queue<int> q;
	memset(f,0,sizeof(f));
	while(1)
	{
		q.push(s);
		memset(r,0,sizeof(r));
		r[0]=100000000;
		while(!q.empty())
		{
			u=q.front();
			q.pop();
			for(v=1;v<=m;v++)
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
	int m,n,pig[1000],guest[1000],t,add,result,i,j,a;
	memset(g,0,sizeof(g));
	memset(guest,0,sizeof(guest));
	scanf("%d%d",&m,&n);
	for(i=0;i<m;i++)
	{
		scanf("%d",&pig[i]);
	}
	for(j=1;j<=n;j++)
	{
		scanf("%d",&a);
		add=0;
		while(a--)
		{
			scanf("%d",&t);
			if(pig[t-1]!=0)
			{
				add+=pig[t-1];
				pig[t-1]=0;
				guest[t-1]=j;
			}
			else if(guest[t-1]!=0)
				g[guest[t-1]][j]=10000000;
		}
		scanf("%d",&g[j][101]);
		g[0][j]=add;
	}
	result=EK(0,101,101);
	printf("%d\n",result);
	return 0;
}