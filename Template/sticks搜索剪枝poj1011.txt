#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
int m,b,length,sum,used[64],stick[64];
cmp(const void *a,const void *b)
{
	return (*(int *)b)-(*(int *)a);
}
void dfs(int k,int now,int finish)
{
	int i,pre=-1;
	if(finish==sum/m)
		b=1;
	else if(now==m)
		dfs(0,0,finish+1);
	else
	{
		for(i=k;i<length;i++)
		{
			if(now+stick[i]<=m&&used[i]==0&&stick[i]!=pre)
			{
				used[i]=1;
				dfs(k+1,now+stick[i],finish);
				used[i]=0;
				pre=stick[i];
				if(b||k==0) return;
			}
		}
	}
}

int main()
{
	int i,j;
	for(;;)
	{
		scanf("%d",&length);
		if(length==0) break;
		sum=0;
		b=0;
		for(i=0;i<length;i++)
		{
			scanf("%d",&stick[i]);
			sum+=stick[i];
		}
		qsort(stick,length,sizeof(stick[0]),cmp);
		for(m=stick[0];m<=sum;m++)
		{
			if(sum%m!=0) continue;
			for(j=0;j<length;j++)
				used[j]=0;
			dfs(0,0,0);
			if(b==1) break;
		}
		printf("%d\n",m);
	}
	return 0;
}