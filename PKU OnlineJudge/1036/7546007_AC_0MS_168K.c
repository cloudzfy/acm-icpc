#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct gan
{
	int t,p,s;
}gun[100];
int cmp(const void *a,const void *b)
{
	return *(int*)a-*(int*)b;
}
int main()
{
	int N,K,T,i,j,sum;
	scanf("%d %d %d",&N,&K,&T);
	for(i=0;i<N;i++)
		scanf("%d",&gun[i].t);
	for(i=0;i<N;i++)
		scanf("%d",&gun[i].p);
	for(i=0;i<N;i++)
	{
		scanf("%d",&gun[i].s);
		if(gun[i].s>gun[i].t)
			gun[i].t=30001;
	}
	qsort(gun,N,sizeof(gun[0]),cmp);
	for(i=N-1;i>=0;i--)
		if(gun[i].t!=30001)
			break;
	N=i+1;
	for(i=0;i<N;i++)
	{
		sum=0;
		for(j=i-1;j>=0;j--)
		{
			if(abs(gun[i].t-gun[j].t)>=abs(gun[i].s-gun[j].s))
			{
				if(sum<gun[j].p)
					sum=gun[j].p;
			}
		}
		gun[i].p+=sum;
	}
	sum=0;
	for(i=N-1;i>=0;i--)
		if(gun[i].p>sum)
			sum=gun[i].p;
	printf("%d\n",sum);
	return 0;
}