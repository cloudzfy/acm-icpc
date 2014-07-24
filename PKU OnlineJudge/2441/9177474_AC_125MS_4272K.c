#include <stdio.h>
#include <string.h>
int cow[20],dp[1<<20];
int main()
{
	int N,M,P,i,j,x,k,result;
	while(scanf("%d%d",&N,&M)!=EOF)
	{
		memset(cow,0,sizeof(cow));
		for(i=0;i<N;i++)
		{
			scanf("%d",&P);
			while(P--)
			{
				scanf("%d",&x);
				cow[i]|=(1<<(x-1));
			}
		}
		if(N>M)
		{
			printf("0\n");
			continue;
		}
		memset(dp,0,sizeof(dp));
		dp[0]=1;
		for(i=0;i<N;i++)
		{
			for(j=(1<<M)-1;j>=0;j--)
			{
				if(dp[j]==0)continue;
				for(k=0;k<M;k++)
				{
					if((cow[i]&(1<<k))==0)continue;
					if((j&(1<<k))!=0)continue;
					dp[j|(1<<k)]+=dp[j];
				}
				dp[j]=0;
			}
		}
		result=0;
		for(i=0;i<(1<<M);i++)
			result+=dp[i];
		printf("%d\n",result);
	}
	return 0;
}