#include <iostream>
#include <map>
#include <queue>
#include <string>
using namespace std;
map<string,int> M;
int f[402][402],g[402][402];

int EK(int s,int t,int m)
{
	queue<int> q;
	memset(f,0,sizeof(f));
	int pre[402],r[402],u,v,result=0;
	while(1)
	{
		memset(r,0,sizeof(r));
		r[0]=100000;
		q.push(s);
		while(!q.empty())
		{
			u=q.front();
			q.pop();
			for(v=1;v<=t;v++)
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
	int n,m,x,i,k;
	string a,b;
	memset(g,0,sizeof(g));
	scanf("%d",&n);
	x=1;
	for(i=0;i<n;i++)
	{
		cin>>a;
		if(M.find(a)==M.end())
		{
			M[a]=x;
			x++;
		}
		g[M[a]][401]+=1;
	}
	scanf("%d",&m);
	for(i=0;i<m;i++)
	{
		cin>>a>>b;
		if(M.find(b)==M.end())
		{
			M[b]=x;
			x++;
		}
		g[0][M[b]]+=1;
	}
	scanf("%d",&k);
	for(i=0;i<k;i++)
	{
		cin>>a>>b;
		if(M.find(a)==M.end())
		{
			M[a]=x;
			x++;
		}
		if(M.find(b)==M.end())
		{
			M[b]=x;
			x++;
		}
		g[M[a]][M[b]]=100000;
	}
	cout<<(m-EK(0,401,401))<<endl;
	return 0;
}