#include <stdio.h>
#include <math.h>
#define eps 1e-10
struct Point
{
	double x,y;
}P[100],Q[100],tmp[200];
struct Segment
{
	struct Point start,end;
	Segment(){}
	Segment(struct Point _start,struct Point _end):start(_start),end(_end){}
};
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
	struct Segment l;
	struct Point q;
	int i,j,k,T,M,N,num,flag;
	double left,right,mid,last;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&M,&N);
		for(i=0;i<M;i++)
		{
			scanf("%lf%lf",&P[i].x,&P[i].y);
		}
		for(i=0;i<N;i++)
		{
			scanf("%lf%lf",&Q[i].x,&Q[i].y);
		}
		i=1;
		j=1;
		flag=1;
		last=0;
		l.start.x=-10000;
		l.end.x=10000;
		while(i<M&&j<N)
		{
			if(fabs(P[i].y-Q[j].y)<eps)
			{
				num=0;
				for(k=0;k<=i;k++)
					tmp[num++]=P[k];
				for(k=j;k>=0;k--)
					tmp[num++]=Q[k];
				q=gravitycenter(tmp,num);
				if(q.x<P[0].x||q.x>Q[0].x)
				{
					flag=0;
					left=last;
					right=Q[j].y;
					mid=(left+right)/2;
					while(fabs(q.x-P[0].x)>eps&&fabs(q.x-Q[0].x)>eps)
					{
						l.start.y=l.end.y=mid;
						tmp[i]=intersect_P(Segment(P[i-1],P[i]),l);
						tmp[i+1]=intersect_P(Segment(Q[j-1],Q[j]),l);
						q=gravitycenter(tmp,num);
						if(q.x<P[0].x||q.x>Q[0].x) right=mid;
						else left=mid;
						mid=(left+right)/2;
					}
					break;
				}
				last=P[i].y;
				i++;
				j++;
			}
			else if(P[i].y>Q[j].y)
			{
				num=0;
				for(k=0;k<i;k++)
					tmp[num++]=P[k];
				l.start.y=l.end.y=Q[j].y;
				tmp[num++]=intersect_P(Segment(P[i-1],P[i]),l);
				for(k=j;k>=0;k--)
					tmp[num++]=Q[k];
				q=gravitycenter(tmp,num);
				if(q.x<P[0].x||q.x>Q[0].x)
				{
					flag=0;
					left=last;
					right=Q[j].y;
					mid=(left+right)/2;
					while(fabs(q.x-P[0].x)>eps&&fabs(q.x-Q[0].x)>eps)
					{
						l.start.y=l.end.y=mid;
						tmp[i]=intersect_P(Segment(P[i-1],P[i]),l);
						tmp[i+1]=intersect_P(Segment(Q[j-1],Q[j]),l);
						q=gravitycenter(tmp,num);
						if(q.x<P[0].x||q.x>Q[0].x) right=mid;
						else left=mid;
						mid=(left+right)/2;
					}
					break;
				}
				last=Q[j].y;
				j++;
			}
			else if(P[i].y<Q[j].y)
			{
				num=0;
				for(k=0;k<=i;k++)
					tmp[num++]=P[k];
				l.start.y=l.end.y=P[i].y;
				tmp[num++]=intersect_P(Segment(Q[j-1],Q[j]),l);
				for(k=j-1;k>=0;k--)
					tmp[num++]=Q[k];
				q=gravitycenter(tmp,num);
				if(q.x<P[0].x||q.x>Q[0].x)
				{
					flag=0;
					left=last;
					right=P[i].y;
					mid=(left+right)/2;
					while(fabs(q.x-P[0].x)>eps&&fabs(q.x-Q[0].x)>eps)
					{
						l.start.y=l.end.y=mid;
						tmp[i]=intersect_P(Segment(P[i-1],P[i]),l);
						tmp[i+1]=intersect_P(Segment(Q[j-1],Q[j]),l);
						q=gravitycenter(tmp,num);
						if(q.x<P[0].x||q.x>Q[0].x) right=mid;
						else left=mid;
						mid=(left+right)/2;
					}
					break;
				}
				last=P[i].y;
				i++;
			}
		}
		if(!flag)printf("%.3f\n",mid);
		else
		{
			if(i==M)printf("%.3f\n",P[M-1].y);
			else if(j==N)printf("%.3f\n",Q[N-1].y);
		}
	}
	return 0;
}