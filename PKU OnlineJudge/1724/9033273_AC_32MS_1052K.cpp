#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

struct edge
{
	int from,to,length,toll,next;
}edge[10000];
struct node
{
	int id,length,cost;
};
int next[101],cost[101],n,k;
struct cmp{
     bool operator() (struct node a,struct node b)
     {
         if(a.length==b.length)return a.cost>b.cost;
		 return a.length>b.length;
     }
};

int bfs()
{
	int i;
	priority_queue<struct node,vector<struct node>,cmp> q;
	struct node cur;
	struct node now;
	cur.id=1;
	cur.length=0;
	cur.cost=0;
	q.push(cur);
	while(!q.empty())
	{
		cur=q.top();
		q.pop();
		if(cur.id==n) return cur.length;
		for(i=next[cur.id];i!=-1;i=edge[i].next)
		{
			if(cur.cost+edge[i].toll>k)continue;
			now.id=edge[i].to;
			now.length=cur.length+edge[i].length;
			now.cost=cur.cost+edge[i].toll;
			q.push(now);
		}
	}
	return -1;
}
int main()
{
	int i,r;
	memset(next,-1,sizeof(next));
	scanf("%d%d%d",&k,&n,&r);
	for(i=0;i<r;i++)
	{
		scanf("%d%d%d%d",&edge[i].from,&edge[i].to,&edge[i].length,&edge[i].toll);
		edge[i].next=next[edge[i].from];
		next[edge[i].from]=i;
	}
	printf("%d\n",bfs());
	return 0;
}
