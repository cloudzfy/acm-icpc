#include <stdio.h>
int main()
{
	long int i,n;
	long int a[100000],sum,left,right,result,dp[100000];
	for(;;)
	{
		scanf("%d",&n);
		if(n==0) break;
		for(i=0;i<n;i++)
			scanf("%d",&a[i]);
		result=a[0]+a[n-1];
		sum=0;
		left=a[0];
		for(i=0;i<n;i++)
		{
			sum+=a[i];
			if(sum>left) left=sum;
			if(sum<0) sum=0;
			dp[i]=left;
		}
		sum=0;
		right=a[n-1];
		for(i=n-1;i>0;i--)
		{
			sum+=a[i];
			if(sum>right) right=sum;
			if(sum<0) sum=0;
			if(dp[i-1]+right>result) result=dp[i-1]+right;
		}
		printf("%d\n",result);
	}
	return 0;
}