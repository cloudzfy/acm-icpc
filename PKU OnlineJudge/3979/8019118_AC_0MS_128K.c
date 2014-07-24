#include <stdio.h>
int gcd(int a,int b)
{
	int tmp;
	if(a<b)
	{
		tmp=a;
		a=b;
		b=tmp;
	}
	while(b!=0)
	{
		tmp=a%b;
		a=b;
		b=tmp;
	}
	return a;
}
int main()
{
	int a,b,c;
	char exp[8];
	while(scanf("%s",exp)!=EOF)
	{
		if(exp[3]=='+')
			a=(exp[0]-'0')*(exp[6]-'0')+(exp[4]-'0')*(exp[2]-'0');
		else
			a=(exp[0]-'0')*(exp[6]-'0')-(exp[4]-'0')*(exp[2]-'0');
		b=(exp[2]-'0')*(exp[6]-'0');
		if(a<0)
		{
			printf("-");
			a=-a;
		}
		c=gcd(a,b);
		a/=c;
		b/=c;
		if(b==1) printf("%d\n",a);
		else if(a==0) printf("0\n");
		else printf("%d/%d\n",a,b);
	}
	return 0;
}