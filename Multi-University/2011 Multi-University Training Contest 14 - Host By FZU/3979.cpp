#include <stdio.h>
#include <stdlib.h>
struct ww
{
	double bi;
	int np;
	int mp;
	int time;
}heih[10003];
int cmp(const void *p1,const void *p2)
{
	if(((struct ww*)p1)->bi-((struct ww*)p2)->bi<0) return 1;
	else return -1;
}

int main()
{
	long long result;
	int t,j,i,sum;
	int n,m;
	scanf("%d",&t);
	for(j=1;j<=t;j++)
	{
		sum=0;
		result=0;
		scanf("%d%d",&n,&m);
		for(i=0;i<n;i++)
		{
			scanf("%d%d",&heih[i].np,&heih[i].mp);
			sum+=heih[i].mp;
			if(heih[i].np%m==0)heih[i].time=heih[i].np/m;
			else heih[i].time=heih[i].np/m+1;
			heih[i].bi=(double)heih[i].mp/(double)heih[i].time;
		}
		qsort(heih,n,sizeof(heih[0]),cmp);
		for(i=0;i<n;i++)
		{
			result+=sum*heih[i].time;
			sum-=heih[i].mp;
		}
		printf("Case #%d: %I64d\n",j,result);
	}
	return 0;
}