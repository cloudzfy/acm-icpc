//线段树做法

#include <stdio.h>
#include <string.h>
#define M 32000
int n,c[32001],level[32001];
struct t
{
	int l,r,w;
}tree[M*3];
void maketree(int s,int t,int n)
{
	int mid;
	tree[n].l=s;
	tree[n].r=t;
	tree[n].w=0;
	if(t==s)
		return; 
	mid=(s+t)/2;
	maketree(s,mid,n*2);
	maketree(mid+1,t,n*2+1);
}
int find(int s,int t,int n)
{
	int sum=0,mid;
	if(tree[n].l==s&&tree[n].r==t)
		return tree[n].w;
	else
	{
		mid=(tree[n].l+tree[n].r)>>1;
		if(s>mid)
			sum+=find(s,t,n*2+1);
		else if(t<=mid)
			sum+=find(s,t,n*2);
		else
			sum+=find(s,mid,n*2)+find(mid+1,t,n*2+1);
		return sum;
	}
}
void insert(int x,int n)
{
	int mid;
	tree[n].w++;
	if(tree[n].l==tree[n].r&&tree[n].r==x)
		return;
	mid=(tree[n].l+tree[n].r)>>1;
	if(x<=mid)
		insert(x,n*2);
	else insert(x,n*2+1);
}

int main()
{
	int i,x,y;
	scanf("%d",&n);
	memset(level,0,sizeof(level));
	maketree(0,32000,1);
	for(i=0;i<n;i++)
	{
		scanf("%d%d",&x,&y);
		level[find(0,x,1)]++;
		insert(x,1);
	}
	for(i=0;i<n;i++)
	{
		printf("%d\n",level[i]);
	}
	return 0;
}
