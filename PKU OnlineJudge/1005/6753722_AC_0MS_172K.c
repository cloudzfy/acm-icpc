#include <stdio.h>
#include <math.h>
int main()
{
	int i,n;
	double x,y,year;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%lf %lf",&x,&y);
		year=floor(3.14*(x*x+y*y)/2/50)+1;
		printf("Property %d: This property will begin eroding in year %.0f.\n",i+1,year);
	}
	printf("END OF OUTPUT.\n");
	return 0;
}