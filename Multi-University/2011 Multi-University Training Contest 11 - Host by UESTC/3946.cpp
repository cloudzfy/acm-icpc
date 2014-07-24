#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;
int s[10000],b[10000];
int cmp(const void *a,const void *b)
{
	return (*(int *)b)-(*(int *)a);
}
int main()
{
	int T,t,n,m,n1,n2,i,c,result;
	scanf("%d",&T);
	for(t=1;t<=T;t++)
	{
		scanf("%d%d%d%d",&n,&m,&n1,&n2);
		memset(b,0,sizeof(b));
		memset(s,0,sizeof(s));
		for(i=1;i<=n1;i++)
		{
			scanf("%d",&b[i]);
		}
		for(i=1;i<=n2;i++)
		{
			scanf("%d",&s[i]);
		}
		qsort(b+1,n1,sizeof(b[0]),cmp);
		qsort(s+1,n2,sizeof(s[0]),cmp);
		if((n==2&&m%3==2)||(m==2&&n%3==2)) c=4;
		else c=n*m%3;
		for(i=2;i<=n1;i++) b[i]+=b[i-1];
		for(i=2;i<=n2;i++) s[i]+=s[i-1];
		n2=min(n2,(n*m-c)/3);
		result=0;
		for(i=0;i<=n2;i++)
		{
			result=max(result,s[i]+b[min(n1,(n*m-3*i)/2)]);
		}
		printf("Case #%d: %d\n",t,result);
	}
	return 0;
}