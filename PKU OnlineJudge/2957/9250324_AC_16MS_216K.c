/* POJ 2957
 * 计算几何（外接圆圆心）
 * 注意：题目不难，考想法，但是一时没想出来
 * Memory:216K	Time:0MS
 */
#include <stdio.h>
#include <math.h>
#define eps 1e-8
struct Point
{
	double x,y;
}point[3];
//求外接圆圆心
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
int main()
{
	int T,k1,k2,i;
	struct Point q;
	double pi=acos(-1.0),dis,alpha;
	while(scanf("%d%d%d",&T,&k1,&k2)!=EOF)
	{
		if(T==0)break;
		for(i=0;i<3;i++)
		{
			scanf("%lf%lf",&point[i].x,&point[i].y);
		}
		dis=sqrt(point[0].x*point[0].x+point[0].y*point[0].y);
		alpha=atan2(point[0].y,point[0].x)+2*pi*(double)k1/(double)T;
		point[0].x=dis*cos(alpha);
		point[0].y=dis*sin(alpha);
		dis=sqrt(point[2].x*point[2].x+point[2].y*point[2].y);
		alpha=atan2(point[2].y,point[2].x)-2*pi*(double)k2/(double)T;
		point[2].x=dis*cos(alpha);
		point[2].y=dis*sin(alpha);
		q=cocircle(point[0],point[1],point[2]);
		dis=sqrt(q.x*q.x+q.y*q.y);
		printf("%.0f\n",dis);
	}
	return 0;
}