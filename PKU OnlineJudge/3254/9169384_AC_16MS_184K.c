/* POJ 3254
 * 状态压缩DP（第一次完全自己做）
 * Memory:184K	Time:0MS
 */
#include <stdio.h>
#include <string.h>
#define MOD 100000000
int map[12],dp[12][400],status[400],total,M,N;
void init()
{
	int i;
	total=0;
	for(i=0;i<(1<<N);i++)
	{
		if((i&(i>>1))==0)
			status[total++]=i;
	}
}

int main()
{
	int i,j,f,x,result;
	scanf("%d%d",&M,&N);
	init();
	memset(map,0,sizeof(map));
	for(i=0;i<M;i++)
	{
		for(j=0;j<N;j++)
		{
			 scanf("%d",&f);
			 map[i]|=(((f+1)%2)<<j);
		}
	}
	memset(dp,0,sizeof(dp));
	for(i=0;i<total;i++)
	{
		if(status[i]&map[0])continue;
		dp[0][i]=1;
	}
	for(x=1;x<M;x++)
	{
		for(i=0;i<total;i++)
		{
			if(status[i]&map[x])continue;
			for(j=0;j<total;j++)
			{
				if(status[i]&status[j])continue;
				dp[x][i]=(dp[x][i]+dp[x-1][j])%MOD;
			}
		}
	}
	result=0;
	for(i=0;i<total;i++)
	{
		result+=dp[M-1][i]%MOD;
	}
	printf("%d\n",result%MOD);
	return 0;
}