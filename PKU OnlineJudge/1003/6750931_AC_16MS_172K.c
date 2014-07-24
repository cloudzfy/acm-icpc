#include <stdio.h>
int main()
{
	double card,length;
	int i;
	for(;;)
	{
		card=0;
		scanf("%lf",&length);
		if(length==0.00) break;
		for(i=2;;i++)
		{
			card+=(1.0/i);
			if(length<=card) break;
		}
		printf("%d card(s)\n",i-1);
	}
	return 0;
}