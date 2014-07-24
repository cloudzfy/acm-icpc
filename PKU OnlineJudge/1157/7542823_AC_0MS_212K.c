#include <stdio.h>
#include <string.h>
int main()
{
	int dp[100][100],a[100][100],i,j,f,v,sum;
	while(scanf("%d %d",&f,&v)!=EOF)
	{
		for(i=0;i<f;i++)
		{
			for(j=0;j<v;j++)
			{
				scanf("%d",&a[i][j]);
				dp[i][j]=-5000;
			}
		}
		dp[0][0]=a[0][0];
		for(j=1;j<v;j++)
		{
			if(dp[0][j-1]>a[0][j])
				dp[0][j]=dp[0][j-1];
			else
				dp[0][j]=a[0][j];
		}
		for(i=1;i<f;i++)
		{
			for(j=i;j<v;j++)
			{
				if(dp[i][j-1]>dp[i-1][j-1]+a[i][j])
					dp[i][j]=dp[i][j-1];
				else
					dp[i][j]=dp[i-1][j-1]+a[i][j];
			}
		}
		sum=-5000;
		for(j=f-1;j<v;j++)
			if(sum<dp[f-1][j])
				sum=dp[f-1][j];
		printf("%d\n",sum);
	}
	return 0;
}