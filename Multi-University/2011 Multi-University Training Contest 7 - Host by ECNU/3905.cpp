#include <stdio.h>
#include <string.h>
int data[1001],dp[1001][1001],sum[1001],rest[1001];
int main()
{
	int n,m,l,i,j;
	while(scanf("%d%d%d",&n,&m,&l)!=EOF)
	{
		for(i=1;i<=n;i++)
		{
			scanf("%d",&data[i]);
		}
		sum[1]=data[1];
		for(i=2;i<=n;i++)sum[i]=sum[i-1]+data[i];
		memset(dp,0,sizeof(dp));
		memset(rest,0,sizeof(rest));
		for(i=1;i<=n;i++)
		{
			for(j=0;j<=m&&j<=i;j++)
			{
				if(j>0)dp[i][j]=dp[i-1][j-1];
				if(dp[i-1][j]>dp[i][j])dp[i][j]=dp[i-1][j];
				if(i-l>=j)
				{
					rest[j]=rest[j]+data[i];
					if(rest[j]<dp[i-l][j]+sum[i]-sum[i-l])
						rest[j]=dp[i-l][j]+sum[i]-sum[i-l];
				}
				if(i-l>=0&&dp[i][j]<rest[j])dp[i][j]=rest[j];
			}
		}
		printf("%d\n",dp[n][m]);
	}
	return 0;
}