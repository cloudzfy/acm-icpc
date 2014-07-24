#include <stdio.h>
long long data[100000];
int main()
{
	int t,T;
	long long cost,n,a,b,i;
	scanf("%d",&T);
	for(t=1;t<=T;t++)
	{
		scanf("%I64d%I64d%I64d",&n,&a,&b);
		for(i=0;i<n;i++)
		{
			scanf("%I64d",&data[i]);
		}
		cost=2*a+n*b;
		for(i=1;i<n;i++)
		{
			if(2*a<(data[i]-data[i-1]-1)*b)
				cost+=2*a;
			else
				cost+=(data[i]-data[i-1]-1)*b;
		}
		printf("Case #%d: %I64d\n",t,cost);
	}
	return 0;
}