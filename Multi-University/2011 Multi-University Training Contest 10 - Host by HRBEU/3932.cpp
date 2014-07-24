#include <stdio.h>
#include <math.h>
#define eps 1e-10
struct Point
{
	double x,y;
}point[1000];
struct Circle
{
	struct Point origin;
	double r;
};
int sig(double k)
{
	return (k<-eps)?-1:(k>eps);
}
double dist(struct Point a,struct Point b)
{
	return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
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
struct Circle MiniDisc(struct Point p[],int n)
{
	int i,j,k;
	struct Circle d;
	d.origin.x=(p[0].x+p[1].x)/2;
	d.origin.y=(p[0].y+p[1].y)/2;
	d.r=dist(d.origin,p[0]);
	for(i=2;i<n;i++)
	{
		if(sig(dist(p[i],d.origin)-d.r)>0)
		{
			d.origin.x=(p[0].x+p[i].x)/2;
			d.origin.y=(p[0].y+p[i].y)/2;
			d.r=dist(d.origin,p[0]);
			for(j=1;j<i;j++)
			{
				if(sig(dist(p[j],d.origin)-d.r)>0)
				{
					d.origin.x=(p[i].x+p[j].x)/2;
					d.origin.y=(p[i].y+p[j].y)/2;
					d.r=dist(d.origin,p[i]);
					for(k=0;k<j;k++)
					{
						if(sig(dist(p[k],d.origin)-d.r)>0)
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
	int i,N,X,Y;
	struct Circle d;
	while(scanf("%d%d%d",&X,&Y,&N)!=EOF)
	{
		for(i=0;i<N;i++)
		{
			scanf("%lf%lf",&point[i].x,&point[i].y);
		}
		if(N==1)
		{
			printf("(%.1f,%.1f).\n",point[0].x,point[0].y);
			printf("0.0\n");
		}
		else
		{
			d=MiniDisc(point,N);
			printf("(%.1f,%.1f).\n",d.origin.x,d.origin.y);
			printf("%.1f\n",d.r);
		}
	}
	return 0;
}