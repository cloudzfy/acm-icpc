/* POJ 2836
 * 状态压缩Dp
 * Memory:292K	Time:125MS
 * 注意考虑三点以上情况
 */
#include <stdio.h>
#include <string.h>
#include <math.h>
#define INF 16843009
int dp[(1<<15)];
int point[15][2];
int main()
{
	int n,i,j,k,area,x,status;
	while(scanf("%d",&n)!=EOF)
	{
		if(n==0)break;
		for(i=0;i<n;i++)
		{
			scanf("%d%d",&point[i][0],&point[i][1]);
		}
		memset(dp,1,sizeof(dp));
		dp[0]=0;
		for(i=0;i<n;i++)
		{
			for(j=i+1;j<n;j++)
			{
				if(point[i][0]==point[j][0]) area=abs(point[i][1]-point[j][1]);
				else if(point[i][1]==point[j][1]) area=abs(point[i][0]-point[j][0]);
				else area=abs(point[i][0]-point[j][0])*abs(point[i][1]-point[j][1]);
				status=(1<<i)|(1<<j);
				for(k=0;k<n;k++)
				{
					if((point[k][0]-point[i][0])*(point[k][0]-point[j][0])<=0&&(point[k][1]-point[i][1])*(point[k][1]-point[j][1])<=0)
						status|=(1<<k);
				}
				for(x=0;x<(1<<n);x++)
				{
					if(dp[x]==INF)continue;
					if((x|status)==x) continue;
					if(dp[x|status]>dp[x]+area)
						dp[x|status]=dp[x]+area;
				}
			}
		}
		printf("%d\n",dp[(1<<n)-1]);
	}
	return 0;
}