#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
long long c[500010];
int n;
struct AD
{
	int U,C,L;
}ad[500000];
bool cmp(struct AD a,struct AD b)
{
	if(a.U==b.U) return a.C>b.C;
	return b.U>a.U;
}
int main()
{
	int t,T,N,M,Q,i,num,k;
	scanf("%d",&T);
	for(t=1;t<=T;t++)
	{
		scanf("%d%d%d",&N,&M,&Q);
		memset(c,0,sizeof(c));
		for(i=0;i<M;i++)
		{
			scanf("%d%d%d",&ad[i].U,&ad[i].C,&ad[i].L);
		}
		sort(ad,ad+M,cmp);
		ad[0].C=1;
		c[1]+=ad[0].L;
		n=2;
		num=1;
		for(i=1;i<M;i++)
		{
			if(ad[i].U==ad[i-1].U)c[n++]+=ad[i].L;
			else
			{
				n=1;
				c[n++]+=ad[i].L;
			}
			if(num<n)num=n;
		}
		for(i=2;i<=num;i++) c[i]+=c[i-1];
		printf("Case #%d:\n",t);
		while(Q--)
		{
			scanf("%d",&k);
			if(k>num)k=num;
			printf("%I64d\n",c[k]);
		}
	}
	return 0;
}