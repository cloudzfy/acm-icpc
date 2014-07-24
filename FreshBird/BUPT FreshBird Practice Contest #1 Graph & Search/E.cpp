#include <stdio.h>
#include <stdlib.h>
int set[20000];
struct edge
{
	int x,y,d;
}edge[50000];
int cmp(const void *a,const void *b)
{
	return ((struct edge*)b)->d-((struct edge*)a)->d;
}
int find(int k)
{
	if(set[k]!=k)
	{
		set[k]=find(set[k]);
	}
	return set[k];
}
int main()
{
	int n,m,r,i,total,result,p,q,t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d%d",&n,&m,&r);
		for(i=0;i<r;i++)
		{
			scanf("%d%d%d",&edge[i].x,&edge[i].y,&edge[i].d);
			edge[i].y+=n;
		}
		qsort(edge,r,sizeof(edge[0]),cmp);
		for(i=0;i<n+m;i++)
		{
			set[i]=i;
		}
		total=0;
		result=0;
		for(i=0;i<r;i++)
		{
			p=find(edge[i].x);
			q=find(edge[i].y);
			if(p==q)continue;
			set[p]=q;
			total++;
			result+=edge[i].d;
			if(total==n+m-1) break;
		}
		printf("%d\n",(n+m)*10000-result);
	}
	return 0;
}