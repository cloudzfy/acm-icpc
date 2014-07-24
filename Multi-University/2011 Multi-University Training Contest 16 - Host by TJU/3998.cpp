#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
#define INF 100000
#define MAXN 100000
int dp[MAXN],data[MAXN],mark[MAXN];
int main()
{
	int N,i,j,s,num,maxlen;
	while(scanf("%d",&N)!=EOF)
	{
		for(i=0;i<N;i++)
		{
			scanf("%d",&data[i]);
		}
		memset(mark,0,sizeof(mark));
		s=0;
		num=1;
		while(1)
		{
			memset(dp,1,sizeof(dp));
			maxlen=-INF;
			for(i=0;i<N;i++)
			{
				if(mark[i])continue;
				j=lower_bound(dp,dp+N,data[i])-dp;
				dp[j]=data[i];
				if(j>maxlen)
				{
					maxlen=j;
					mark[i]=1;
				}
			}
			if(s<maxlen+1)s=maxlen+1;
			else if(s==maxlen+1)num++;
			else break;
		}
		printf("%d\n%d\n",s,num);
	}
	return 0;
}