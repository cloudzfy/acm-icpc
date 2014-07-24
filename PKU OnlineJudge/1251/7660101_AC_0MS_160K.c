#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct d
{
	int a,b,x;
};
struct d data[75];
int tree[27],result,num;
int cmp(const void *a,const void *b)
{
	return (*(struct d*)a).x-(*(struct d*)b).x;
}
void U(int a,int b,int x)
{
	if(tree[b]==-1)
	{
		tree[b]=a;
		result+=x;
		num++;
	}
	else if(tree[b]<a)
		U(tree[b],a,x);
	else if(tree[b]>a)
	{
		U(a,tree[b],x);
		tree[b]=a;
	}
}
int main()
{
	int i,j,n,m,x,k;
	char a1[2],a2[2];
	for(;;)
	{
		scanf("%d",&n);
		if(n==0) break;
		k=0;
		num=0;
		result=0;
		memset(tree,-1,sizeof(tree));
		for(j=0;j<n-1;j++)
		{
			scanf("%s%d",a1,&m);
			while(m--)
			{
				scanf("%s%d",a2,&x);
				data[k].a=a1[0]-'A';
				data[k].b=a2[0]-'A';
				data[k].x=x;
				k++;
			}
		}
		qsort(data,k,sizeof(data[0]),cmp);
		for(i=0;i<k;i++)
		{
			if(num==n-1) break;
			U(data[i].a,data[i].b,data[i].x);
		}
		printf("%d\n",result);
	}
	return 0;
}