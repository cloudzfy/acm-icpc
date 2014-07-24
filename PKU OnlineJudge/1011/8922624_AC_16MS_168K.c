/*
 * 经典题：深度优先搜索+剪枝
 * 重写：2011/7/18
*/

#include <stdio.h>
#include <stdlib.h>

int m,stick[64],used[64],sum,n;
int cmp(const void *a,const void *b)
{
	return (*(int *)b)-(*(int *)a);
}

int dfs(int k,int finish,int now)
{
	int i,b,pre=-1;
	if(now==m)
	{
		finish++;//已完成的木棍数
		k=0;
		now=0;
	}
	if(finish==sum/m)
	{
		return 1;
	}
	for(i=k;i<n;i++)
	{
		if(used[i]==0&&stick[i]+now<=m&&pre!=stick[i])
		{
			used[i]=1;
			b=dfs(i+1,finish,now+stick[i]);
			used[i]=0;//注意used[i]=0的位置。
			if(b==1) return 1;
			if(k==0) return 0;//剪枝：如果剩余的最长木棍不合适，则不满足。
			pre=stick[i];//剪枝：去掉无效的重复。
		}
	}
	return 0;
}
 int main()
 {
	 int i;
	 while(scanf("%d",&n)!=EOF)
	 {
		 if(n==0) break;
		 sum=0;
		 for(i=0;i<n;i++)
		 {
			 scanf("%d",&stick[i]);
			 sum+=stick[i];
		 }
		 qsort(stick,n,sizeof(stick[0]),cmp);
		 for(m=stick[0];m<=sum;m++)
		 {
			 if(sum%m!=0) continue;
			 for(i=0;i<n;i++)
			 {
				 used[i]=0;
			 }
			 if(dfs(0,0,0)) break;
		 }
		 printf("%d\n",m);
	 }
	 return 0;
 }