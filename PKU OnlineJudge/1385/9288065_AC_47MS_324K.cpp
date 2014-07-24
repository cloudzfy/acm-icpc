/*
 * POJ 1385
 * 计算几何：简单多边形重心
 * Memory:324K	Time:47MS
 */
#include <stdio.h>
#include <math.h>
#define eps 1e-15
struct Point
{
	double x,y;
}point[1000000];
double multiply(struct Point start,struct Point end,struct Point origin)
{
	return (start.x-origin.x)*(end.y-origin.y)-(end.x-origin.x)*(start.y-origin.y);
}
struct Point gravitycenter(struct Point polygon[],int n)
{
	int i;
	double area=0,mu;
	struct Point p,origin;
	origin.x=origin.y=0;
	p.x=p.y=0;
	for(i=0;i<n;i++)
	{
		mu=multiply(polygon[i],polygon[(i+1)%n],origin);
		area+=mu;
		p.x+=(polygon[i].x+polygon[(i+1)%n].x)*mu;
		p.y+=(polygon[i].y+polygon[(i+1)%n].y)*mu;
	}
	p.x/=(3*area);
	p.y/=(3*area);
	return p;
}
int main()
{
	int T,N,i;
	struct Point p;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&N);
		for(i=0;i<N;i++)
		{
			scanf("%lf%lf",&point[i].x,&point[i].y);
		}
		p=gravitycenter(point,N);
		printf("%.2f %.2f\n",p.x,p.y);
	}
	return 0;
}