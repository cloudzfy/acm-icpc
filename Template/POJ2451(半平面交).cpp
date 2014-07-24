/* POJ 2451
 * 计算几何：半平面交
 * 经典模板
 * Memory:1080K	Time:297MS
 */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <algorithm>
#include <deque>
using namespace std;
#define eps 1e-10
#define INF 10000
#define MAXN 20010
struct Point
{
	double x,y;
}polygon[MAXN];
struct Segment
{
	struct Point start,end;
}line[MAXN];
int total;
double at2[MAXN];
int order[MAXN];
inline void addEdge(double x1,double y1,double x2,double y2)
{
	line[total].start.x=x1;
	line[total].start.y=y1;
	line[total].end.x=x2;
	line[total].end.y=y2;
	total++;
}
//判断是否为0
inline int sig(double k)
{
	return (k<-eps)?-1:(k>eps);
}
inline double multiply(struct Point start,struct Point end,struct Point origin)
{
	return (start.x-origin.x)*(end.y-origin.y)-(end.x-origin.x)*(start.y-origin.y);
}
int cmp(const void *a,const void *b)
{
	if(sig(at2[*((int*)a)]-at2[*((int*)b)])==0)
		return sig(multiply(line[*((int*)a)].end,line[*((int*)b)].end,line[*((int*)a)].start));
	return sig(at2[*((int*)a)]-at2[*((int*)b)]);
}
//求直线交点
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
int judgein(int x,int y,int z)
{
	struct Point q=intersect_P(line[x],line[y]);
	return sig(multiply(line[z].end,q,line[z].start))<0;
}
int HalfPlaneIntersection(struct Point polygon[],int n)
{
	int i,tmpn;
	for(i=0;i<n;i++)
	{
		at2[i]=atan2(line[i].end.y-line[i].start.y,line[i].end.x-line[i].start.x);
		order[i]=i;
	}
	qsort(order,n,sizeof(order[0]),cmp);
	for(i=1,tmpn=1;i<n;i++)
	{
		if(sig(at2[order[i]]-at2[order[i-1]]))order[tmpn++]=order[i];
	}
	n=tmpn;
	deque<int> dq;
	dq.push_front(order[0]);
	dq.push_back(order[1]);
	for(i=2;i<n;i++)
	{
		while(dq.size()>=2&&judgein(dq[dq.size()-2],dq[dq.size()-1],order[i]))dq.pop_back();
		while(dq.size()>=2&&judgein(dq[1],dq[0],order[i]))dq.pop_front();
		dq.push_back(order[i]);
	}
	while(dq.size()>=2&&judgein(dq[dq.size()-2],dq[dq.size()-1],dq[0]))dq.pop_back();
	while(dq.size()>=2&&judgein(dq[1],dq[0],dq[dq.size()-1]))dq.pop_front();
	dq.push_front(dq.back());
	n=0;
	for(i=1;i<(int)dq.size();i++)
	{
		polygon[n++]=intersect_P(line[dq[i-1]],line[dq[i]]);
	}
	return n;
} 
int main()
{
	int i,N;
	double x1,y1,x2,y2,area;
	total=0;
	scanf("%d",&N);
	for(i=0;i<N;i++)
	{
		scanf("%lf%lf%lf%lf",&x1,&y1,&x2,&y2);
		addEdge(x1,y1,x2,y2);
	}
	//下面是构造一个大矩形边界
	addEdge(0,0,INF,0);
	addEdge(INF,0,INF,INF);
	addEdge(INF,INF,0,INF);
	addEdge(0,INF,0,0);
	N=HalfPlaneIntersection(polygon,total);
	area=0;//求多边形面积
	for(i=0;i<N;i++)
	{
		area+=polygon[i].x*polygon[(i+1)%N].y-polygon[(i+1)%N].x*polygon[i].y;
	}
	area=fabs(area)/2;
	printf("%.1f\n",area);
	return 0;
}