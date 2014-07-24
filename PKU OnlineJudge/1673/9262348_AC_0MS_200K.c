#include <stdio.h>
#include <math.h>
#define eps 1e-10
struct Point
{
	double x,y;
}point[3];
struct Segment
{
	struct Point start,end;
};
double dotmultiply(struct Point start,struct Point end,struct Point origin)
{
	return (start.x-origin.x)*(end.x-origin.x)+(start.y-origin.y)*(end.y-origin.y);
}
double multiply(struct Point start,struct Point end,struct Point origin)
{
	return (start.x-origin.x)*(end.y-origin.y)-(end.x-origin.x)*(start.y-origin.y);
}
double dist(struct Point a,struct Point b)
{
	return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}
double relation(struct Point p,struct Segment l)
{
	return dotmultiply(p,l.end,l.start)/(dist(l.start,l.end)*dist(l.start,l.end));
}
struct Point perpendicular(struct Point p,struct Segment l)
{
	struct Point ans;
	double r=relation(p,l);
	ans.x=l.start.x+r*(l.end.x-l.start.x);
	ans.y=l.start.y+r*(l.end.y-l.start.y);
	return ans;
}
struct Point intersect_P(struct Segment a,struct Segment b)
{
	double dot1,dot2;
	struct Point q;
	dot1=multiply(a.end,a.start,b.start);
	dot2=multiply(b.end,a.start,a.end);
	q.x=(b.start.x*dot2+b.end.x*dot1)/(dot2+dot1);
	q.y=(b.start.y*dot2+b.end.y*dot1)/(dot2+dot1);
	return q;
}
struct Point OrthoCenter(struct Point a,struct Point b,struct Point c)
{
	struct Point p;
	struct Segment l1,l2,l;
	l1.start=a;
	l.start=b;
	l.end=c;
	l1.end=perpendicular(a,l);
	l2.start=b;
	l.start=a;
	l.end=c;
	l2.end=perpendicular(b,l);
	p=intersect_P(l1,l2);
	return p;
}
int main()
{
	int i,T;
	struct Point q;
	scanf("%d",&T);
	while(T--)
	{
		for(i=0;i<3;i++)
		{
			scanf("%lf%lf",&point[i].x,&point[i].y);
		}
		q=OrthoCenter(point[0],point[1],point[2]);
		printf("%.4f %.4f\n",q.x+eps,q.y+eps);
	}
	return 0;
}