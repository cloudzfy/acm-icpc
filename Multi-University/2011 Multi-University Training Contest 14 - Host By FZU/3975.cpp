#include <stdio.h>
#include <math.h>
#define eps 1e-8
int main()
{
	int t,T;
	double x1,x2,x3,v1,v2,v3,a,b,c,A,B,result,g=10,pi=3.1415926;
	scanf("%d",&T);
	for(t=1;t<=T;t++)
	{
		scanf("%lf%lf%lf",&x1,&x2,&x3);
		scanf("%lf%lf%lf",&v1,&v2,&v3);
		scanf("%lf%lf%lf",&a,&b,&c);
		A=(v3*sin(c)-v1*sin(a))*(v2*cos(b)-v1*cos(a))-(v3*cos(c)-v1*cos(a))*(v2*sin(b)-v1*sin(a));
		B=(x2-x1)*(v3*sin(c)-v1*sin(a))-(x3-x1)*(v2*sin(b)-v1*sin(a));
		printf("Case #%d: ",t);
		
		if(a==0 || b==0 || c==0 || a==pi || b==pi ||c==pi)printf("-1\n");
		else if(fabs(A)<eps)
		{
			if(v1==v2 && v2==v3 && v1==0)printf("-1\n");
			else if(fabs(B)<eps)printf("Multiply answer\n");
			else printf("-1\n");
		}
		else if(B>eps && A<-eps)
		{
			result=-B/A;
			if(v1*sin(a)*result-0.5*g*result*result<eps)printf("-1\n");
			else if(v2*sin(b)*result-0.5*g*result*result<eps)printf("-1\n");
			else if(v3*sin(c)*result-0.5*g*result*result<eps)printf("-1\n");
			else printf("%.4f\n",result);
		}
		else if(B<-eps && A>eps)
		{
			result=-B/A;
			if(v1*sin(a)*result-0.5*g*result*result<eps)printf("-1\n");
			else if(v2*sin(b)*result-0.5*g*result*result<eps)printf("-1\n");
			else if(v3*sin(c)*result-0.5*g*result*result<eps)printf("-1\n");
			else printf("%.4f\n",result);
		}
		else printf("-1\n");
	}
	return 0;
}