#include <stdio.h>
#include <string.h>
#include <math.h>
int main()
{
	double H,Vx,Vy,t,V1,V2,V3,g=9.8,result,result1,result2,result3;
	double t1,Vx1,Vy1,h1;
	char color[7];
	while(scanf("%lf",&H)!=EOF)
	{
		scanf("%s",color);
		if(strcmp(color,"Red")==0)
		{
			scanf("%lf%lf",&Vx,&Vy);
			result=Vx*(Vy+sqrt(Vy*Vy+2*g*H))/g;
			printf("%.3f\n",result);
		}
		else if(strcmp(color,"Yellow")==0)
		{
			scanf("%lf%lf%lf",&Vx,&Vy,&t);
			t1=(Vy+sqrt(Vy*Vy+2*g*H))/g;
			if(t1<t) result=t1*Vx;
			else
			{
				h1=Vy*t-0.5*g*t*t+H;
				Vy1=(Vy-g*t)*2;
				Vx1=Vx*2;
				result=Vx1*(Vy1+sqrt(Vy1*Vy1+2*g*h1))/g+Vx*t;
			}
			printf("%.3f\n",result);
		}
		else if(strcmp(color,"Blue")==0)
		{
			scanf("%lf%lf%lf%lf%lf%lf",&Vx,&Vy,&t,&V1,&V2,&V3);
			t1=(Vy+sqrt(Vy*Vy+2*g*H))/g;
			if(t1<t)
			{
				result=t1*Vx;
				printf("%.3f\n",result);
			}
			else
			{
				h1=Vy*t-0.5*g*t*t+H;
				Vy1=Vy-g*t;
				result1=V1*(Vy1+sqrt(Vy1*Vy1+2*g*h1))/g+Vx*t;
				result2=V2*(Vy1+sqrt(Vy1*Vy1+2*g*h1))/g+Vx*t;
				result3=V3*(Vy1+sqrt(Vy1*Vy1+2*g*h1))/g+Vx*t;
				printf("%.3f %.3f %.3f\n",result1,result2,result3);
			}
		}
	}
	return 0;
}