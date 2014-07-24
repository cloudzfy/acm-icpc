#include <stdio.h>
#include <math.h>
struct Point
{
	double x,y;
}point[3];
struct Point cocircle(struct Point a,struct Point b,struct Point c)
{
	struct Point q;
	double u1,u2;
	u1=(b.x*b.x-a.x*a.x+b.y*b.y-a.y*a.y)/2;
	u2=(c.x*c.x-a.x*a.x+c.y*c.y-a.y*a.y)/2;
	q.x=(u1*(c.y-a.y)-u2*(b.y-a.y))/((b.x-a.x)*(c.y-a.y)-(c.x-a.x)*(b.y-a.y));
	q.y=(u2*(b.x-a.x)-u1*(c.x-a.x))/((b.x-a.x)*(c.y-a.y)-(c.x-a.x)*(b.y-a.y));
	return q;
}
double dist(struct Point a,struct Point b)
{
	return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}
int main()
{
	double r;
	struct Point q;
	while(scanf("%lf%lf%lf%lf%lf%lf",&point[0].x,&point[0].y,&point[1].x,&point[1].y,&point[2].x,&point[2].y)!=EOF)
	{
		q=cocircle(point[0],point[1],point[2]);
		r=dist(q,point[0]);
		printf("(x ");
		if(q.x<=0)printf("+");
		else printf("-");
		printf(" %.3f)^2 + (y ",fabs(q.x));
		if(q.y<=0)printf("+");
		else printf("-");
		printf(" %.3f)^2 = %.3f^2\n",fabs(q.y),fabs(r));
		printf("x^2 + y^2 ");
		if(q.x<=0)printf("+");
		else printf("-");
		printf(" %.3fx ",fabs(q.x*2));
		if(q.y<=0)printf("+");
		else printf("-");
		printf(" %.3fy ",fabs(q.y*2));
		if(q.x*q.x+q.y*q.y-r*r>=0)printf("+");
		else printf("-");
		printf(" %.3f = 0\n\n",fabs(q.x*q.x+q.y*q.y-r*r));
	}
	return 0;
}