#include <stdio.h>
#include <stdlib.h>
int p[501];
int cmp(const void *a,const void *b)
{
	return *((int *)a)-*((int *)b);
}
int main()
{
	int n,ip,i,total,result;
	while(scanf("%d%d",&n,&ip)!=EOF)
	{
		for(i=0;i<n;i++)
		{
			scanf("%d",&p[i]);
		}
		qsort(p,n,sizeof(p[0]),cmp);
		total=0;
		for(i=0;i<n;i++)
		{
			if(p[i]>ip)
			{
				ip+=2;
				total++;
			}
		}
		result=ip+n-total;
		printf("%d\n",result);
	}
	return 0;
}