#include <stdio.h>
int main()
{
	int i;
	double total=0,dollar;
	for(i=0;i<12;i++)
	{
		scanf("%lf",&dollar);
		total+=dollar;
	}
	total/=12;
	printf("$%.2f\n",total);
	return 0;
}