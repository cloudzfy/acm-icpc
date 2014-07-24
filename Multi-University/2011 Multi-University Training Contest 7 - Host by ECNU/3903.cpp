#include <stdio.h>
#include <math.h>
int main()
{
	int t;
	long long a,b,c,n,m,k,tmp;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%I64d%I64d%I64d%I64d%I64d%I64d",&a,&b,&c,&n,&m,&k);
		tmp=(long long)sqrt((long double)(4*b*b*c*c-(b*b+c*c-a*a)*(b*b+c*c-a*a)));
		if(tmp*tmp+(b*b+c*c-a*a)*(b*b+c*c-a*a)!=4*b*b*c*c)
		{
			printf("NO\n");
		}
		else printf("YES\n");
	}
	return 0;
}