/* POJ 1584
 * Memory:200K Time:0MS
 * 计算几何
 * 几点注意：取模（忘记取模WA了好几次）
 * 灵活运用叉积，不要总是套模板
 * 注意叉积与面积的关系，求解点到线段的距离
 */
#include <stdio.h>
#include <math.h>
#define eps 1e-8
#define INF 1000000
struct Point
{
	double x,y;
}point[200],res[200],tmp[200],peg;
int N;
struct Segment
{
	struct Point start,end;
};

double multiply(struct Point start,struct Point end,struct Point origin)
{
	return (start.x-origin.x)*(end.y-origin.y)-(end.x-origin.x)*(start.y-origin.y);
}

double pointDist(struct Segment l,struct Point p)
{
	return fabs(multiply(l.start,l.end,p))/sqrt((l.start.x-l.end.x)*(l.start.x-l.end.x)+(l.start.y-l.end.y)*(l.start.y-l.end.y));
}

int insidePoint()
{
	int i;
	double now ,pre=multiply(point[0],point[1],peg);
	for(i=1;i<N;i++)
	{
		now=multiply(point[i],point[(i+1)%N],peg);
		if(pre*now<eps) return 0;
		pre=now;
	}
	return 1;
}

int main()
{
	struct Segment l;
	double pegRadius,dir;
	int i,flag;
	while(scanf("%d",&N)!=EOF)
	{
		if(N<3)break;
		scanf("%lf%lf%lf",&pegRadius,&peg.x,&peg.y);
		for(i=0;i<N;i++)
		{
			scanf("%lf%lf",&point[i].x,&point[i].y);
		}
		for(i=0;i<N+1;i++)
		{
			dir=multiply(point[(i+1)%N],point[(i+2)%N],point[i%N]);
			if(fabs(dir)>=eps)break;
		}
		flag=1;
		for(i=0;i<N+1;i++)
		{
			if(multiply(point[(i+1)%N],point[(i+2)%N],point[i%N])*dir<-eps)
			{
				flag=0;
				break;
			}
		}
		if(!flag)printf("HOLE IS ILL-FORMED\n");
		else if(!insidePoint())printf("PEG WILL NOT FIT\n");
		else
		{
			flag=1;
			for(i=0;i<N;i++)
			{
				l.start=point[i];
				l.end=point[(i+1)%N];
				if(pointDist(l,peg)<pegRadius)
				{
					flag=0;
					break;
				}
			}
			if(flag)printf("PEG WILL FIT\n");
			else printf("PEG WILL NOT FIT\n");
		}
	}
	return 0;
}