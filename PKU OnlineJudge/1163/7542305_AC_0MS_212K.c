#include <stdio.h>
#include <string.h>
int main()
{
	int i,j,r,num[100][100],dp[100][100],sum=0;
	scanf("%d",&r);
	for(i=0;i<r;i++)
		for(j=0;j<=i;j++)
			scanf("%d",&num[i][j]);
	dp[0][0]=num[0][0];
	for(i=1;i<r;i++)
	{
		dp[i][0]=num[i][0]+dp[i-1][0];
		for(j=1;j<i;j++)
		{
			if(dp[i-1][j]>dp[i-1][j-1])
				dp[i][j]=num[i][j]+dp[i-1][j];
			else
				dp[i][j]=num[i][j]+dp[i-1][j-1];
		}
		dp[i][i]=num[i][i]+dp[i-1][i-1];
	}
	for(i=0;i<r;i++)
		if(dp[r-1][i]>sum)
			sum=dp[r-1][i];
	printf("%d\n",sum);
	return 0;
}