#include <stdio.h>
#include <string.h>
int num[500],stu[30001],tree[500];
void U(int a,int b)
{
	if(tree[b]==-1) tree[b]=a;
	else
	{
		if(tree[b]<a)
			U(tree[b],a);
		else if(tree[b]>a)
		{
			U(a,tree[b]);
			tree[b]=a;
		}
	}
}
int Find(int a)
{
	if(tree[a]==-1) return a;
	else return Find(tree[a]);
}
int main()
{
	int x,n,m,i,j,l,b,result,mb;
	for(;;)
	{
		scanf("%d%d",&n,&m);
		if(n==0&&m==0) break;
		memset(stu,-1,sizeof(stu));
		memset(tree,-1,sizeof(tree));
		for(i=0;i<m;i++)
		{
			scanf("%d",&num[i]);
			x=num[i];
			for(j=0;j<x;j++)
			{
				scanf("%d",&mb);
				if(stu[mb]==i)
				{
					num[i]--;
					continue;
				}
				else if(stu[mb]!=-1)
				{
					U(stu[mb],i);
					num[i]--;
				}
				else stu[mb]=i;
			}
		}
		if(stu[0]==-1) result=1;
		else
		{
			b=Find(stu[0]);
			result=0;
			for(i=0;i<m;i++)
			{
				if(tree[i]==-1)
				{
					if(i==b) result+=num[i];
				}
				else if(Find(tree[i])==b) result+=num[i];
			}
		}
		printf("%d\n",result);
	}
	return 0;
}