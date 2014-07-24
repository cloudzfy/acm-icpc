/* POJ 3764
 * TRIE + 异或位运算
 * 注意xor是关键字
 * Memory:16772K	Time:954MS
 */
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <queue>
using namespace std;
#define N 100000
int next[N],visited[N],xor1[N],total,n;
struct e
{
	int u,v,w,next;
}edge[N*2];
struct node
{
	struct node *next[2];
}trie[N*31],*head;
void bfs()
{
	int u,v,i;
	queue<int> q;
	visited[0]=1;
	q.push(0);
	while(!q.empty())
	{
		u=q.front();
		q.pop();
		visited[u]=1;
		for(i=next[u];i!=-1;i=edge[i].next)
		{
			v=edge[i].v;
			if(!visited[v])
			{
				xor1[v]=xor1[u]^edge[i].w;
				q.push(v);
			}
		}
	}
}

void buildtree()
{
	int x,i,j;
	struct node *p;
	head=&trie[total++];
	memset(head->next,0,sizeof(head->next));
	for(i=0;i<n;i++)
	{
		p=head;
		for(j=30;j>=0;j--)
		{
			x=(xor1[i]>>j)%2;
			if(p->next[x]==NULL)
			{
				p->next[x]=&trie[total++];
				memset(p->next[x]->next,0,sizeof(p->next[x]->next));
			}
			p=p->next[x];
		}
	}
}

int solve()
{
	struct node *p;
	int ans,result=0,i,j;
	for(i=0;i<n;i++)
	{
		p=head;
		ans=0;
		for(j=30;j>=0;j--)
		{
			if(xor1[i]&(1<<j))
			{
				if(p->next[0]!=NULL)
				{
					p=p->next[0];
					ans=(ans<<1);
				}
				else
				{
					p=p->next[1];
					ans=(ans<<1)+1;
				}
			}
			else
			{
				if(p->next[1]!=NULL)
				{
					p=p->next[1];
					ans=(ans<<1)+1;
				}
				else
				{
					p=p->next[0];
					ans=(ans<<1);
				}
			}
		}
		if((ans^xor1[i])>result) result=(ans^xor1[i]);
	}
	return result;
}

int main()
{
	int u,v,w,i,ans;
	while(scanf("%d",&n)!=EOF)
	{
		memset(next,-1,sizeof(next));
		memset(visited,0,sizeof(visited));
		memset(xor1,0,sizeof(xor1));
		total=0;
		for(i=0;i<n-1;i++)
		{
			scanf("%d%d%d",&u,&v,&w);
			edge[i*2].u=u;
			edge[i*2].v=v;
			edge[i*2].w=w;
			edge[i*2].next=next[u];
			next[u]=i*2;
			edge[i*2+1].u=v;
			edge[i*2+1].v=u;
			edge[i*2+1].w=w;
			edge[i*2+1].next=next[v];
			next[v]=i*2+1;
		}
		bfs();
		buildtree();
		ans=solve();
		printf("%d\n",ans);
	}
	return 0;
}