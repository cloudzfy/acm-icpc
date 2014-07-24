#include <stdio.h>
#include <math.h>
double a,b,c;
double solve(double x)
{
	double tmp,t1,t2,t3;
	tmp=sqrt(a*x*x+b*x+c);
	t1=(2*a*x+b)/(4*a)*tmp;
	t2=(4*a*c-b*b)/(8*a*sqrt(a));
	t3=log(fabs(2*a*x+b+2*sqrt(a)*tmp));
	return t1+t2*t3;
}
int main()
{
	int T;
	double x0,y0,x1,y1,t,g=9.8,V0,V1,result;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%lf%lf%lf%lf%lf",&x0,&y0,&x1,&y1,&t);
		if(t==0)
		{
			printf("Impossible.\n");
			continue;
		}
		V0=(x1-x0)/t;
		V1=0.5*g*t+(y1-y0)/t;
		a=g*g;
		b=-2*V1*g;
		c=V0*V0+V1*V1;
		result=solve(t)-solve(0.0);
		printf("%.3f\n",result);
	}
	return 0;
}