#include <stdio.h>
#include <string.h>
#define MAXN 1010
#define MAXS 110
#define INF 16843009
int data[MAXN],dp[MAXN][MAXS];
int main()
{
	int N,La,Lb,S,i,j,k,result;
	while(scanf("%d",&N)!=EOF)
	{
		if(N==0) break;
		scanf("%d%d%d",&Lb,&La,&S);
		for(i=1;i<=N;i++)
		{
			scanf("%d",&data[i]);
		}
		memset(dp,1,sizeof(dp));
		dp[0][0]=0;
		for(i=1;i<=N;i++)
		{
			dp[i][0]=dp[i-1][0]+data[i];
			for(j=1;j<=S;j++)
			{
				if(dp[i-1][j]!=INF) dp[i][j]=dp[i-1][j]+data[i];
				for(k=La;k<=Lb;k++)
				{
					if(i-k<0||j<1)continue;
					if(dp[i][j]>dp[i-k][j-1])
						dp[i][j]=dp[i-k][j-1];
				}
			}
		}
		result=10000000;
		for(i=0;i<=S;i++)
		{
			if(result>dp[N][i])
				result=dp[N][i];
		}
		printf("%d\n",result);
	}
	return 0;
}