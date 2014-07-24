#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <queue>
using namespace std;
struct Edge
{
	int from,to,weight,next;
}edge[80000];
int next[40000],used[40000],dis[40000],result;
int bfs(int k)
{
	int i,mark=-1,cur;
	queue<int> q;
	q.push(k);
	memset(dis,0,sizeof(dis));
	memset(used,0,sizeof(used));
	used[k]=1;
	result=0;
	while(!q.empty())
	{
		cur=q.front();
		q.pop();
		for(i=next[cur];i!=-1;i=edge[i].next)
		{
			if(used[edge[i].to]==1)continue;
			used[edge[i].to]=1;
			q.push(edge[i].to);
			dis[edge[i].to]=dis[edge[i].from]+edge[i].weight;
			if(result<dis[edge[i].to])
			{
				result=dis[edge[i].to];
				mark=edge[i].to;
			}
		}
	}
	return mark;
}
int main()
{
	int n,m,i,from,to,weight;
	char tmp[2];
	result=0;
	memset(next,-1,sizeof(next));
	scanf("%d%d",&n,&m);
	for(i=0;i<m;i++)
	{
		scanf("%d%d%d%s",&from,&to,&weight,tmp);
		from--;
		to--;
		edge[2*i+1].from=edge[2*i].to=to;
		edge[2*i+1].to=edge[2*i].from=from;
		edge[2*i+1].weight=edge[2*i].weight=weight;
		edge[2*i].next=next[from];
		next[from]=2*i;
		edge[2*i+1].next=next[to];
		next[to]=2*i+1;
	}
	bfs(bfs(0));
	printf("%d\n",result);
	return 0;
}