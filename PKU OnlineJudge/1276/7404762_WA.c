#include <stdio.h>
int main()
{
	long int i,j,k,cash,N,n,d,f[100001];
	while(scanf("%d",&cash)!=EOF)
	{
		scanf("%d",&N);
		f[0]=1;
		for(i=1;i<=cash;i++)
		{
			f[i]=0;
		}
		for(i=0;i<N;i++)
		{
			scanf("%d %d",&n,&d);
			if(n==0) continue;
			for(k=1;k*2<=n;k*=2)
			{
				for(j=cash;j>=k*d;j--)
				{
					if(f[j-k*d]!=0) f[j]=1;
				}
			}
			if(k!=n)
			{
				k=n-k+1;
				for(j=cash;j>=k*d;j--)
				{
					if(f[j-k*d]!=0) f[j]=1;
				}
			}
		}
		for(i=cash;i>=0;i--)
			if(f[i]!=0) break;
		printf("%d\n",i);
	}
	return 0;
}