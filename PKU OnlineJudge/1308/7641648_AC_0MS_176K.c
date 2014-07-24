#include <stdio.h>
#include <math.h>
#include <string.h>

int main()
{
	int i,a,b,tree[1001],set[1001],result,t=1,root,max;
	for(;;)
	{
		result=1;
		max=0;
		scanf("%d%d",&a,&b);
		if(a==-1&&b==-1) break;
		memset(tree,-1,sizeof(tree));
		memset(set,0,sizeof(set));
		if(a==0&&b==0) result=2;
		for(;;)
		{
			if(a==0&&b==0) break;
			set[a]=1;
			set[b]=1;
			if(a==b) result=0;
			if(result==1)
			{
				if(a>max) max=a;
				else if(b>max) max=b;
				if(tree[b]==-1) tree[b]=a;
				else result=0;
			}
			scanf("%d%d",&a,&b);
		}
		root=0;
		if(result==1)
		{
			for(i=1;i<=max;i++)
			{
				if(tree[i]==-1&&set[i]==1) root++;
			}
			if(root!=1) result=0;
		}
		if(result>=1)
			printf("Case %d is a tree.\n",t);
		else
			printf("Case %d is not a tree.\n",t);
		t++;
	}
	return 0;
}