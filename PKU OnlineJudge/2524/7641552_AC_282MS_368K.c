#include <stdio.h>
#include <math.h>
#include <string.h>
long int tree[50010];
void T(long int a,long int b)
{
	if(tree[b]==0)
		tree[b]=a;
	else
	{
		if(tree[b]>a)
			T(a,tree[b]);
		else if(tree[b]<a)
			T(tree[b],a);
		tree[b]=a;
	}
}

int main()
{
	long int n,m,tmp,i,a,b,t=1,result;
	for(;;)
	{
		scanf("%d%d",&n,&m);
		if(n==0&&m==0) break;
		memset(tree,0,sizeof(tree));
		for(i=0;i<m;i++)
		{
			scanf("%d%d",&a,&b);
			if(a==b) continue;
			if(a>b)
			{
				tmp=a;
				a=b;
				b=tmp;
			}
			T(a,b);
		}
		result=0;
		for(i=1;i<=n;i++)
		{
			if(tree[i]==0) result++;
		}
		printf("Case %d: %d\n",t,result);
		t++;
	}
	return 0;
}