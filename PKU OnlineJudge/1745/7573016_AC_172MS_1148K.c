#include <stdio.h>
#include <math.h>
#include <string.h>
char dp[10001][100];
int main()
{
	int b=0,j,N,m=0,K,i,num;
	scanf("%d %d",&N,&K);
	memset(dp,0,sizeof(dp));
	dp[0][0]=1;
	for(i=0;i<N;i++)
	{
		scanf("%d",&num);
		if(num%K!=0)
		{
			num=abs(num)%K;
			for(j=0;j<100;j++)
			{
				if(dp[m][j]!=0)
					dp[m+1][(j+num)%K]=1;
			}
			for(j=99;j>=0;j--)
			{
				if(dp[m][j]!=0)
					dp[m+1][abs(j-num)%K]=1;
			}
			m++;
		}
	}
	for(i=0;i<100;i++)
		if(i%K==0&&dp[m][i]==1)
			b=1;
	if(b==1)
		printf("Divisible\n");
	else
		printf("Not divisible\n");
	return 0;
}