#include <stdio.h>
int main()
{
	double result,A,B,C;
	while(scanf("%lf%lf%lf",&A,&B,&C)!=EOF)
	{
		result=B-(B+C)*(B+C)/(A+B+C+C);
		printf("%.6f\n",result);
	}
	return 0;
}