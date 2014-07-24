#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <stack>
#include <set>
using namespace std;
#pragma comment(linker, "/STACK:1024000000,1024000000") 
#define N 100010
struct e
{
	int v,w,next;
}edge[2*N];
struct q
{
	int ans,bound,next;
}query[N];
int next[N],qnext[N],visited[N];
multiset<int> mset;
multiset<int>::iterator it;
void dfs(int u)
{
	int i,v;
	for(i=qnext[u];i!=-1;i=query[i].next)
	{
		it=mset.lower_bound(query[i].bound);
		query[i].ans=(*it);
	}
	for(i=next[u];i!=-1;i=edge[i].next)
	{
		v=edge[i].v;
		if(visited[v])continue;
		visited[v]=1;
		mset.insert(-edge[i].w);
		dfs(v);
		mset.erase(mset.find(-edge[i].w));
	}
}
int main()
{
	int i,x,y,w,t,n,Q;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		memset(next,-1,sizeof(next));
		for(i=0;i<n-1;i++)
		{
			scanf("%d%d%d",&x,&y,&w);
			edge[i*2].v=y;
			edge[i*2].w=w;
			edge[i*2].next=next[x];
			next[x]=2*i;
			edge[i*2+1].v=x;
			edge[i*2+1].w=w;
			edge[i*2+1].next=next[y];
			next[y]=2*i+1;
		}
		memset(qnext,-1,sizeof(qnext));
		scanf("%d",&Q);
		for(i=0;i<Q;i++)
		{
			scanf("%d%d",&x,&y);
			query[i].bound=-y;
			query[i].ans=1;
			query[i].next=qnext[x];
			qnext[x]=i;
		}
		memset(visited,0,sizeof(visited));
		mset.clear();
		mset.insert(1);
		visited[1]=1;
		dfs(1);
		for(i=0;i<Q;i++)
		{
			printf("%d\n",-query[i].ans);
		}
	}
	return 0;
}