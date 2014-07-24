#include <stdio.h>
#include <string.h>
#include <math.h>
int main()
{
	double a,b,i,j,t;
	while(scanf("%lf %lf",&a,&b)!=EOF)
	{
		i=(int)(a/b);
		if((a/b)-floor(a/b)<0.5)
			i=floor(a/b);
		else
			i=floor(a/b)+1;
		j=1;
		printf("%.0f\/%.0f\n",i,j);
		t=fabs(a/b-i/j);
		for(j=2;j<=b;j++)
		{
			if((a/b*j)-floor(a/b*j)<0.5)
				i=floor(a/b*j);
			else
				i=floor(a/b*j)+1;
			if(t>fabs(a/b-i/j))
			{
				printf("%.0f\/%.0f\n",i,j);
				t=fabs(a/b-i/j);
			}
		}
		printf("\n");
	}
	return 0;
}