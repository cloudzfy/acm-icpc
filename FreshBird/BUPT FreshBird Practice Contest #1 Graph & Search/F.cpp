#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <queue>
using namespace std;
int map[100][100],position[100],value[100],used[100],result,n,m;
void dfs(int v,int k,int posh,int posl)
{
	int i,high,low;
	used[k]=1;
	for(i=0;i<n;i++)
	{
		if(used[i])continue;
		if(position[i]>posl+m||position[i]<posh-m) continue;
		if(map[k][i]==-1) continue;
		if(result>v+map[k][i]+value[i])
		{
			result=v+map[k][i]+value[i];
		}
		if(position[i]<posl) low=position[i];
		else low=posl;
		if(position[i]>posh) high=position[i];
		else high=posh;
		dfs(v+map[k][i],i,high,low);
	}
	used[k]=0;
}
int main()
{
	queue<int> q;
	int i,x,j,t,v;
	memset(map,-1,sizeof(map));
	memset(used,0,sizeof(used));
	scanf("%d%d",&m,&n);
	for(i=0;i<n;i++)
	{
		scanf("%d%d%d",&value[i],&position[i],&x);
		for(j=0;j<x;j++)
		{
			scanf("%d%d",&t,&v);
			map[i][t-1]=v;
		}
	}
	result=value[0];
	dfs(0,0,position[0],position[0]);
	printf("%d\n",result);
	return 0;
}