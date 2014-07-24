#include <stdio.h>
#include <stdlib.h>
int cmp(const void *a,const void *b)
{
	return (*(int *)b)-(*(int *)a);
}

int main()
{
	int i,j,k,n;
	long long x[20001],sum=0,m;
	scanf("%d",&n);
	for(i=0;i<n;i++)
		scanf("%lld",&x[i]);
	qsort(x,n,sizeof(x[0]),cmp);
	for(i=n-2;i>0;i--)
	{
		m=x[i]+x[i+1];
		sum+=m;
		j=i-1;
		while(j>=0&&m>x[j])
			j--;
		for(k=i;k>j+1;k--)
			x[k]=x[k-1];
		x[k]=m;
	}
	sum+=x[0]+x[1];
	printf("%lld\n",sum);
	return 0;
}