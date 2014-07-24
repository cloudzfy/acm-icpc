/* POJ 3608
 * 计算几何（旋转卡壳）
 * 注意：重要旋转卡壳模板
 * Memory:512K	Time:125MS
 */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <algorithm>
using namespace std;
#define MAXN 20000
#define INF 10000
#define eps 1e-8
struct Point
{
	double x,y;
	Point(){}
    Point(double _x,double _y):x(_x),y(_y){}
	bool operator<(const Point q)const
	{
		if(fabs(y-q.y)<eps)return x<q.x;
		return y<q.y;
	}
	bool operator>(const Point q)const
	{
		if(fabs(y-q.y)<eps)return x>q.x;
		return y>q.y;
	}
	struct Point operator-(const Point q)const
	{
		return Point(x-q.x,y-q.y);
	}
}polygon1[MAXN],polygon2[MAXN],tmp;
int N,M;
double multiply(struct Point start,struct Point end,struct Point origin)
{
	return (start.x-origin.x)*(end.y-origin.y)-(end.x-origin.x)*(start.y-origin.y);
}
double dist(struct Point a,struct Point b)
{
	return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}
int cmp(const void *a,const void *b)
{
	if(fabs(multiply(*((struct Point*)a),*((struct Point*)b),tmp))<eps)
		return dist(*((struct Point*)a),tmp)>dist(*((struct Point*)b),tmp);
	return multiply(*((struct Point*)a),*((struct Point*)b),tmp)<0;
}
double dotProduct(struct Point start,struct Point end,struct Point origin)
{
	return (start.x-origin.x)*(end.x-origin.x)+(start.y-origin.y)*(end.y-origin.y);
}
double seg(struct Point start,struct Point end,struct Point origin)
{
	if(dotProduct(origin,start,end)>-eps&&dotProduct(origin,end,start)>-eps)
		return fabs(multiply(start,end,origin))/dist(start,end);
	return min(dist(origin,start),dist(origin,end));
}

double rotating_calipers()
{
	int i1,i2,i,s1,s2,j1,j2;
	double ans,del;
	//分别选取y坐标最大最小值，并以之为边
	tmp.x=0;
	tmp.y=INF;
	for(i=0;i<N;i++)
	{
		if(tmp>polygon1[i])
		{
			tmp=polygon1[i];
			i1=i;
		}
	}
	tmp.x=0;
	tmp.y=-INF;
	for(i=0;i<M;i++)
	{
		if(tmp<polygon2[i])
		{
			tmp=polygon2[i];
			i2=i;
		}
	}
	ans=INF;
	s1=i1;
	s2=i2;
	while(1)
	{
		j1=(i1+1)%N;
		j2=(i2+1)%M;
		ans=min(ans,seg(polygon2[i2],polygon2[j2],polygon1[i1]));
		ans=min(ans,seg(polygon2[i2],polygon2[j2],polygon1[j1]));
		ans=min(ans,seg(polygon1[i1],polygon1[j1],polygon2[i2]));
		ans=min(ans,seg(polygon1[i1],polygon1[j1],polygon2[j2]));
		del=multiply(polygon1[j1]-polygon1[i1],polygon2[j2]-polygon2[i2],Point(0,0));
		if(fabs(del)<eps)//如果平行
		{
			i1=(i1+1)%N;
			i2=(i2+1)%M;
		}
		else if(del<0)i1=(i1+1)%N;
		else i2=(i2+1)%M;
		if(i1==s1&&i2==s2)break;
	}
	return ans;
}

int main()
{
	struct Point cur;
	int i,pos;
	double result;
	while(scanf("%d%d",&N,&M)!=EOF)
	{
		if(N==0&&M==0)break;
		//极角法为凸包排序
		tmp.x=0;
		tmp.y=INF;
		for(i=0;i<N;i++)
		{
			scanf("%lf%lf",&polygon1[i].x,&polygon1[i].y);
			if(tmp>polygon1[i])
			{
				tmp=polygon1[i];
				pos=i;
			}
		}
		cur=polygon1[0];
		polygon1[0]=polygon1[pos];
		polygon1[pos]=cur;
		qsort(polygon1+1,N-1,sizeof(polygon1[0]),cmp);
		tmp.x=0;
		tmp.y=INF;
		for(i=0;i<M;i++)
		{
			scanf("%lf%lf",&polygon2[i].x,&polygon2[i].y);
			if(tmp>polygon2[i])
			{
				tmp=polygon2[i];
				pos=i;
			}
		}
		cur=polygon2[0];
		polygon2[0]=polygon2[pos];
		polygon2[pos]=cur;
		qsort(polygon2+1,M-1,sizeof(polygon2[0]),cmp);
		result=rotating_calipers();
		printf("%.5f\n",result);
	}
	return 0;
}