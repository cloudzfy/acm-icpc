#include <stdio.h>
#include <string.h>
int q[10000][3];
int v[10000];
int parent[10000];
void insert(int index,int value)
{
	int i;
	int tmp;
	for(i=0;i<3;i++)
	{
		if(q[index][i]<value)
		{
			tmp=q[index][i];
			q[index][i]=value;
			value=tmp;
		}
	}
}
int main()
{
	int n,i,p,m;
	int query;
	while(scanf("%d",&n)!=EOF)
	{
		memset(parent,-1,sizeof(parent));
		memset(q,-1,sizeof(q));
		scanf("%d",&v[0]);
		insert(0,v[0]);
		parent[0]=-1;
		for(i=1;i<n;i++)
		{
			scanf("%d%d",&p,&v[i]);
			parent[i]=p;
			insert(i,v[i]);
		}
		for(i=0;i<n;i++)
		{
			p=parent[i];
			while(p!=-1)
			{
				insert(p,v[i]);
				p=parent[p];
			}
		}
		scanf("%d",&m);
		while(m--)
		{
			scanf("%d",&query);
			for(i=0;i<3;i++)
			{
				if(q[query][i]==-1) break;
			}
			if(i!=3)printf("-1\n");
			else printf("%d %d %d\n",q[query][0],q[query][1],q[query][2]);
		}
	}
	return 0;
}