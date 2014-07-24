/* POJ 1185
 * 状态压缩DP
 * Memory:1816K  Time:329MS
 */

#include <stdio.h>
#include <string.h>
char str[100][11];
int N,M,total,map[100],dp[100][65][65];
struct s
{
	int sta,num;
}status[65];
void init()
{
	int num,tmp,i;
	total=0;
	for(i=0;i<(1<<M);i++)
	{
		if((i&(i<<1))||(i&(i<<2)))continue;
		status[total].sta=i;
		tmp=i;
		num=0;
		while(tmp)
		{
			if(tmp&1)num++;
			tmp>>=1;
		}
		status[total++].num=num;
	}
}

int main()
{
	int i,j,k,x,result;
	scanf("%d%d",&N,&M);
	memset(map,0,sizeof(map));
	for(i=0;i<N;i++)
	{
		scanf("%s",str[i]);
		for(j=0;str[i][j]!=0;j++)
		{
			map[i]<<=1;
			if(str[i][j]=='H')map[i]++;
		}
	}
	init();
	memset(dp,-1,sizeof(dp));
	for(i=0;i<total;i++)
	{
		if(status[i].sta&map[0])continue;
		dp[0][i][0]=status[i].num;
	} 
	for(x=1;x<N;x++)
	{
		for(i=0;i<total;i++)
		{
			if(status[i].sta&map[x])continue;
			for(j=0;j<total;j++)
			{
				if(status[i].sta&status[j].sta)continue;
				for(k=0;k<total;k++)
				{
					if(status[i].sta&status[k].sta)continue;
					if(dp[x-1][j][k]==-1)continue;
					if(dp[x][i][j]<dp[x-1][j][k]+status[i].num)
						dp[x][i][j]=dp[x-1][j][k]+status[i].num;
				}
			}
		}
	}
	result=0;
	for(i=0;i<total;i++)
	{
		for(j=0;j<total;j++)
		{
			if(result<dp[N-1][i][j])
				result=dp[N-1][i][j];
		}
	}
	printf("%d\n",result);
	return 0;
}