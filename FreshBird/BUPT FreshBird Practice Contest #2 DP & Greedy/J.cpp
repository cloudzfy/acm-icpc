#include <stdio.h>
int main()
{
	int a,b,c,d,e,f;
	scanf("%d%d%d%d%d%d",&a,&b,&c,&d,&e,&f);
	if(c==0)
	{
		if(d!=0)printf("Ron\n");
		else printf("Hermione\n");
	}
	else if(a==0)
	{
		if(b!=0&&d!=0)printf("Ron\n");
		else printf("Hermione\n");
	}
	else if(e==0)
	{
		if(f!=0&&b!=0&&d!=0)printf("Ron\n");
		else printf("Hermione\n");
	}
	else if(b*d*f>a*c*e)
	{
		printf("Ron\n");
	}
	else printf("Hermione\n");
	return 0;
}