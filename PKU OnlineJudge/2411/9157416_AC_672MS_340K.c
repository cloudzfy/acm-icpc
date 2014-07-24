/* POJ 2411
 * 状态压缩DP
 * Memory:340K	Time:688MS
 */

#include <stdio.h>
#include <string.h>
int h,w;
long long dp[11][2048];
int ok1(int i)
{
	int bit=0;
	while(i)
	{
		if(i&1)bit++;
		else if(bit&1)return 0;
		i>>=1;
	}
	if(bit&1)return 0;
	return 1;
}
int ok2(int j,int k)
{
	if((j|k)!=(1<<w)-1)return 0;
	return ok1(j&k);
}
int main()
{
	int i,j,k;
	while(scanf("%d%d",&h,&w)!=EOF)
	{
		if(h==0&&w==0)break;
		if((h*w)%2==1)
		{
			printf("0\n");
			continue;
		}
		memset(dp,0,sizeof(dp));
		for(i=0;i<(1<<w);i++)
		{
			if(ok1(i))
				dp[0][i]=1;
		}
		for(i=1;i<h;i++)
		{
			for(j=0;j<(1<<w);j++)
			{
				for(k=0;k<(1<<w);k++)
				{
					if(ok2(j,k))
						dp[i][j]+=dp[i-1][k];
				}
			}
		}
		printf("%lld\n",dp[h-1][(1<<w)-1]);
	}
	return 0;
}