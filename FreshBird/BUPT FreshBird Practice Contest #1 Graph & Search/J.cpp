#include <stdio.h>
#include <string.h>
int next[10000],maxlen1[10000][2],maxlen2[10000][2],S[10000],visited[10000];
struct edge
{
	int s,t,length,next;
}edge[20000];
int dfs1(int k)
{
	int tmp,ans[2],max1[2],max2[2],i;
	max1[0]=0;
	max2[0]=0;
	max1[1]=-1;
	max2[1]=-1;
	visited[k]=1;
	for(i=next[k];i!=-1;i=edge[i].next)
	{
		if(visited[edge[i].t])continue;
		ans[0]=dfs1(edge[i].t);
		ans[0]+=edge[i].length;
		ans[1]=edge[i].t;
		if(max1[0]<ans[0])
		{
			tmp=ans[0];
			ans[0]=max1[0];
			max1[0]=tmp;
			tmp=ans[1];
			ans[1]=max1[1];
			max1[1]=tmp;
		}
		if(max2[0]<ans[0])
		{
			tmp=max2[0];
			max2[0]=ans[0];
			ans[0]=tmp;
			tmp=max2[1];
			max2[1]=ans[1];
			ans[1]=tmp;
		}
	}
	maxlen1[k][0]=max1[0];
	maxlen2[k][0]=max2[0];
	maxlen1[k][1]=max1[1];
	maxlen2[k][1]=max2[1];
	return max1[0];
}

void dfs2(int k,int p)
{
	int i,son=-1,p2=p;
	visited[k]=1;
	if(p<maxlen1[k][0])
	{
		if(p<maxlen2[k][0])
		{
			p2=maxlen2[k][0];
		}
		S[k]=maxlen1[k][0];
		p=maxlen1[k][0];
		son=maxlen1[k][1];
	}
	else
	{
		S[k]=p;
	}
	for(i=next[k];i!=-1;i=edge[i].next)
	{
		if(visited[edge[i].t])continue;
		if(edge[i].t==son)dfs2(edge[i].t,p2+edge[i].length);
		else dfs2(edge[i].t,p+edge[i].length);
	}
}
int main()
{
	int i,j,total,length,n;
	while(scanf("%d",&n)!=EOF)
	{
		memset(next,-1,sizeof(next));
		total=0;
		for(i=1;i<n;i++)
		{
			scanf("%d%d",&j,&length);
			edge[total].s=i;
			edge[total].t=j-1;
			edge[total].length=length;
			edge[total].next=next[i];
			next[i]=total;
			total++;
			edge[total].s=j-1;
			edge[total].t=i;
			edge[total].length=length;
			edge[total].next=next[j-1];
			next[j-1]=total;
			total++;
		}
		memset(visited,0,sizeof(visited));
		dfs1(0);
		memset(visited,0,sizeof(visited));
		dfs2(0,0);
		for(i=0;i<n;i++)
		{
			printf("%d\n",S[i]);
		}
	}
	return 0;
}