/* POJ 2240
 * 最短路问题：Bellman-Ford算法
 * Memory:176K	Time:63MS
 */

#include <stdio.h>
#include <string.h>
#define MAXN 30
#define MAXM 10000
struct Edge
{
	int ci,cj;
	double rij;
}edge[MAXM];
char name[MAXN][20];
double dis[MAXN];
int N,M;
int BellmanFord(int v0)
{
	int k,i;
	memset(dis,0,sizeof(dis));
	dis[v0]=1;
	for(k=0;k<N;k++)//按邻接表建图，为N-1次，为了成为一个环，必须比一般的多走一次。
	{
		for(i=0;i<M;i++)
		{
			if(dis[edge[i].ci]*edge[i].rij>dis[edge[i].cj])
				dis[edge[i].cj]=dis[edge[i].ci]*edge[i].rij;
		}
	}
	if(dis[v0]>1) return 1;
	return 0;
}

int main()
{
	int i,k,T=1,ans;
	char a[20],b[20];
	while(scanf("%d",&N)!=EOF)
	{
		if(N==0)break;
		for(i=0;i<N;i++)
		{
			scanf("%s",name[i]);
		}
		scanf("%d",&M);
		for(k=0;k<M;k++)
		{
			scanf("%s%lf%s",a,&edge[k].rij,b);
			for(i=0;i<N;i++)
			{
				if(strcmp(name[i],a)==0) break;
			}
			edge[k].ci=i;
			for(i=0;i<N;i++)
			{
				if(strcmp(name[i],b)==0) break;
			}
			edge[k].cj=i;
		}
		for(i=0;i<N;i++)
		{
			ans=BellmanFord(i);
			if(ans)break;
		}
		if(ans)printf("Case %d: Yes\n",T);
		else printf("Case %d: No\n",T);
		T++;
	}
	return 0;
}