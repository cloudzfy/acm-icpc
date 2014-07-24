#include<stdio.h>
#include<string.h>
const long long mod =1000000007;
const int N = 1001;
long long data[N][N];
long long dp[1010][1010];

void NGetM(int m, int n)
{
        int min, i, j;
        data[0][0] = 1; 
        for( i = 1; i <= m; ++i ) data[i][0] = 0;
        for( i = 0; i <= m; ++i ) data[i][i+1] = 0;
        for( i = 1; i <= m; ++i ){
             if( i < n ) min = i;
             else min = n;
             for( j = 1; j <= min; ++j ){
                  data[i][j] = ((long long)j*data[i-1][j] + data[i-1][j-1])% mod;
             }
        }
}
long long compute(int m ,int n){
     int i;
	 long long B;
     NGetM(m, m);
     B=0;
     for( i=1; i <= n; ++i ){
         B += data[m][i];
         B=B%mod;
     }
     return B;
}

int main()
{
	int n,r,k,m,i,j;
	long long tem;
	while(scanf("%d%d%d%d",&n,&r,&k,&m)!=EOF)
	{
		memset(dp,0,sizeof(dp));
		for(i=1;i<=n;i++)
		{
			if((i-1)%k==0)dp[i][(i-1)/k+1]=1;
			dp[i][1]=(long long)i;
		}
		for(j=2;j<=r;j++)
		{
			for(i=k*(j-1)+2;i<=n;i++)
			{
				dp[i][j]=(dp[i-1][j]+dp[i-k][j-1])%mod;
			}
		}
		if(m>r)
          tem = compute(r,r);
		else
          tem = compute(r,m); 
       printf("%lld\n",(tem*dp[n][r])%mod);

	}
	return 0;
}