#include <stdio.h>
#include <string.h>
char prime[1000001];
int main()
{
	int b,i,j,n;
	memset(prime,1,sizeof(prime));
	for(i=2;i<=1000000;i++)
	{
		if(prime[i]==1)
		{
			j=2;
			while(i*j<=1000000)
			{
				prime[i*j]=0;
				j++;
			}
		}
	}
	while(scanf("%d",&n)!=EOF)
	{
		if(n==0) break;
		b=0;
		for(i=3;i<=1000000;i++)
		{
			if(prime[n-i]==1&&prime[i]==1)
			{
				printf("%d = %d + %d\n",n,i,n-i);
				b=1;
				break;
			}
		}
		if(b==0) printf("Goldbach's conjecture is wrong.\n");
	}
	return 0;
}