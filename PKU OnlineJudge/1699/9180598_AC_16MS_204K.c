/* POJ 1699
 * 状态压缩DP（状态比较难看得出，不过还是挺有价值的）
 * Memory:204K Time:16MS
 */
#include <stdio.h>
#include <string.h>
#define INF 16843009
char str[10][21];
int map[10][10],dp[1<<10][10];
int main()
{
	int T,N,i,j,k,flag,l,x,result,a,b;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&N);
		for(i=0;i<N;i++)
		{
			scanf("%s",str[i]);
		}
		memset(map,0,sizeof(map));
		for(i=0;i<N;i++)
		{
			map[i][i]=(int)strlen(str[i]);
			for(j=0;j<N;j++)
			{
				if(i==j)continue;
				a=(int)strlen(str[i]);
				b=(int)strlen(str[j]);
				for(k=((a>b)?a-b:0);k<a;k++)
				{
					flag=1;
					for(l=0;l+k<a;l++)
					{
						if(str[i][l+k]!=str[j][l])
						{
							flag=0;
							break;
						}
					}
					if(flag)
					{
						map[i][j]=a-k;
						break;
					}
				}
			}
		}
		memset(dp,1,sizeof(dp));
		for(x=0;x<N;x++)
		{
			dp[1<<x][x]=map[x][x];
		}
		for(i=0;i<(1<<N);i++)
		{
			for(j=0;j<N;j++)
			{
				if((i&(1<<j))==0)continue;
				for(k=0;k<N;k++)
				{
					if(j==k)continue;
					if(dp[i-(1<<j)][k]==INF)continue;
					if(dp[i][j]>dp[i-(1<<j)][k]+map[j][j]-map[k][j])
						dp[i][j]=dp[i-(1<<j)][k]+map[j][j]-map[k][j];
				}
			}
		}
		result=INF;
		for(i=0;i<N;i++)
		{
			if(result>dp[(1<<N)-1][i])
				result=dp[(1<<N)-1][i];
		}
		printf("%d\n",result);
	}
	return 0;
}