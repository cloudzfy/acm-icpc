#include <stdio.h>
#include <math.h>
#define PI acos(-1.0)
#define eps 1e-12
double edge[100];
int main()
{
	double left,right,mid,ans;
	int T,t,N,i;
	scanf("%d",&T);
	for(t=1;t<=T;t++)
	{
		scanf("%d",&N);
		for(i=0;i<N;i++)
		{
			scanf("%lf",&edge[i]);
		}
		left=0;
		right=1000000;
		for(i=0;i<N;i++)
		{
			if(left<fabs(edge[i]-edge[(i+1)%N]))
				left=fabs(edge[i]-edge[(i+1)%N]);
			if(right>edge[i]+edge[(i+1)%N])
				right=edge[i]+edge[(i+1)%N];
		}
		printf("Case %d: ",t);
		if(left>=right)
		{
			printf("impossible\n");
			continue;
		}
		left+=eps;
		right-=eps;
		ans=0;
		for(i=0;i<N;i++)
		{
			ans+=acos((edge[i]*edge[i]+edge[(i+1)%N]*edge[(i+1)%N]-right*right)/(2*edge[i]*edge[(i+1)%N]));
		}
		if(fabs(ans)-2*PI<-eps)
		{
			printf("impossible\n");
			continue;
		}
		ans=0;
		for(i=0;i<N;i++)
		{
			ans+=acos((edge[i]*edge[i]+edge[(i+1)%N]*edge[(i+1)%N]-left*left)/(2*edge[i]*edge[(i+1)%N]));
		}
		if(fabs(ans)-2*PI>eps)
		{
			printf("impossible\n");
			continue;
		}
		while(right-left>eps)
		{
			mid=(left+right)/2;
			ans=0;
			for(i=0;i<N;i++)
			{
				ans+=acos((edge[i]*edge[i]+edge[(i+1)%N]*edge[(i+1)%N]-mid*mid)/(2*edge[i]*edge[(i+1)%N]));
			}
			if(fabs(ans)-2*PI<0) left=mid;
			else right=mid;
		}
		printf("%.3f\n",mid);
	}
	return 0;
}