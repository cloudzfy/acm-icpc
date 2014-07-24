#include <stdio.h>
#include <math.h>
double bitter[1000][3];
struct Point
{
	double x,y;
}peak[1000];
struct Segment
{
	struct Point start,end;
	Segment(){}
	Segment(struct Point _x,struct Point _y):start(_x),end(_y){}
};
double multiply(struct Point start,struct Point end,struct Point origin)
{
	return (start.x-origin.x)*(end.y-origin.y)-(end.x-origin.x)*(start.y-origin.y);
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
int main()
{
	double maxh,g=20,energy,v;
	int i,j,t,T,N,M,w;
	struct Segment l;
	struct Point p;
	l.start.y=-11100000;
	l.end.y=11100000;
	scanf("%d",&T);
	for(t=1;t<=T;t++)
	{
		scanf("%d%d%d",&N,&M,&w);
		maxh=-11100000;
		for(i=0;i<N;i++)
		{
			scanf("%lf%lf",&peak[i].x,&peak[i].y);
			if(peak[i].y>maxh)maxh=peak[i].y;
		}
		energy=g*maxh;
		for(i=0;i<M;i++)
		{
			scanf("%lf%lf%lf",&bitter[i][0],&bitter[i][1],&bitter[i][2]);
			for(j=1;j<N;j++)
			{
				if(bitter[i][0]>=peak[j-1].x&&bitter[i][0]<=peak[j].x)
				{
					l.start.x=bitter[i][0];
					l.end.x=bitter[i][0];
					p=intersect_P(Segment(peak[j-1],peak[j]),l);
					break;
				}
			}
			if(energy<g*p.y+0.5*bitter[i][1]*bitter[i][1])
				energy=g*p.y+0.5*bitter[i][1]*bitter[i][1];
		}
		v=sqrt((energy-g*peak[0].y)*2);
		printf("Case %d: %.2f\n",t,v);
	}
	return 0;
}