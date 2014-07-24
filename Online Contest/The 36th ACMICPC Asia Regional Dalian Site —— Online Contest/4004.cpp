#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int N,M;
int dp[500010],tmp[500010];
int cmp(const void *a,const void *b)
{
	return *((int *)a)-*((int *)b);
}
int count(int g)
{
    int ans=0;
    int pn=0,i;
    for(i=1;i<=N;i++)
    {
        ans+=dp[i];
        if(ans>=g)
        {
            if(ans>g) i--;
            ans=0;
            pn++;
            if(pn==M) break;
        }
    }
    
    if(i==N||i==N+1) return 0;
    else return 1;    
}
int main()
{
	int L,high,i;
	while(scanf("%d%d%d",&L,&N,&M)!=EOF)
	{
		memset(dp,0,sizeof(dp));
		high=0;
		for(i=1;i<=N;i++)
		{
			scanf("%d",&tmp[i]);
		}
		qsort(tmp+1,N,sizeof(tmp[1]),cmp);
		for(i=1;i<=N;i++)
		{
			dp[i]=tmp[i]-tmp[i-1];
		}
		dp[i]=L-tmp[i-1];
		high=L;
		N++;
        int low=high/N;
        int mid;
        while(low<=high)
        {
            mid=(high+low)/2;
            if(0==count(mid)) high=mid-1;
            else low=mid+1;
        }
        printf("%d\n",low);
    }
    return 0;
}