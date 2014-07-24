#include <stdio.h>
#include <math.h>
#define eps 1e-10
struct Point
{
	double x,y;
}point[20000];
struct Circle
{
	struct Point origin;
	double r;
};
int sig(double k)
{
	return (k<-eps)?-1:(k>eps);
}
struct Circle cocircle(struct Point a,struct Point b,struct Point c)
{
	struct Circle d;
	double u1,u2;
	u1=(b.x*b.x-a.x*a.x+b.y*b.y-a.y*a.y)/2;
	u2=(c.x*c.x-a.x*a.x+c.y*c.y-a.y*a.y)/2;
	d.origin.x=(u1*(c.y-a.y)-u2*(b.y-a.y))/((b.x-a.x)*(c.y-a.y)-(c.x-a.x)*(b.y-a.y));
	d.origin.y=(u2*(b.x-a.x)-u1*(c.x-a.x))/((b.x-a.x)*(c.y-a.y)-(c.x-a.x)*(b.y-a.y));
	d.r=sqrt((a.x-d.origin.x)*(a.x-d.origin.x)+(a.y-d.origin.y)*(a.y-d.origin.y));
	return d;
}
double dist(struct Point a,struct Point b)
{
	return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}
struct Circle MiniDisc(struct Point p[],int n,int m)
{
	int i,j,k;
	struct Circle d;
	d.origin.x=(p[0].x+p[1].x)/2;
	d.origin.y=(p[0].y+p[1].y)/2;
	d.r=dist(d.origin,p[0]);
	for(i=2;i<n+m;i++)
	{
		if((i<n&&sig(dist(p[i],d.origin)-d.r)>0)||(i>=n&&sig(dist(p[i],d.origin)-d.r)<0))
		{
			d.origin.x=(p[0].x+p[i].x)/2;
			d.origin.y=(p[0].y+p[i].y)/2;
			d.r=dist(d.origin,p[0]);
			for(j=1;j<i;j++)
			{
				if((j<n&&sig(dist(p[j],d.origin)-d.r)>0)||(j>=n&&sig(dist(p[j],d.origin)-d.r)<0))
				{
					d.origin.x=(p[i].x+p[j].x)/2;
					d.origin.y=(p[i].y+p[j].y)/2;
					d.r=dist(d.origin,p[i]);
					for(k=0;k<j;k++)
					{
						if((k<n&&sig(dist(p[k],d.origin)-d.r)>0)||(k>=n&&sig(dist(p[k],d.origin)-d.r)<0))
						{
							d=cocircle(p[i],p[j],p[k]);
						}
					}
				}
			}
		}
	}
	return d;
}

int main()
{
	int i,N,M;
	struct Circle d;
	while(scanf("%d%d",&N,&M)!=EOF)
	{
		for(i=0;i<N+M;i++)
		{
			scanf("%lf%lf",&point[i].x,&point[i].y);
		}
		d=MiniDisc(point,N,M);
		printf("%.3f %.3f\n%.3f\n",d.origin.x,d.origin.y,d.r);
	}
	return 0;
}