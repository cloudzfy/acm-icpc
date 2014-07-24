#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <math.h>
using namespace std;
#define INF 30000
struct Point
{
	int x,y;
}point1[100],point2[100],res1[100],res2[100];

struct Segment
{
	struct Point start,end;
};

int cmp(const void *a,const void *b)
{
	if(((struct Point*)a)->y==((struct Point*)b)->y)
		return ((struct Point*)a)->x-((struct Point*)b)->x;
	return ((struct Point*)a)->y-((struct Point*)b)->y;
}
int multiply(struct Point start,struct Point end,struct Point origin)
{
	int ans=(start.x-origin.x)*(end.y-origin.y)-(end.x-origin.x)*(start.y-origin.y);
	if(ans>0) return 1;
	else if(ans<0) return -1;
	return 0;
}
int Graham_Scan(struct Point point[],int n,struct Point res[])
{
	int top=1,len,i;
	qsort(point,n,sizeof(point[0]),cmp);
	if(n==0) return 0;
	res[0]=point[0];
	if(n==1) return 1;
	res[1]=point[1];
	if(n==2) return 2;
	res[2]=point[2];
	for(i=2;i<n;i++)
	{
		while(top&&!(multiply(point[i],res[top],res[top-1])<0)) top--;
		res[++top]=point[i];
	}
	len=top;
	res[++top]=point[n-2];
	for(i=n-3;i>=0;i--)
	{
		while(len<top&&!(multiply(point[i],res[top],res[top-1])<0)) top--;
		res[++top]=point[i];
	}
	return top;
}

int online(struct Segment l,struct Point p)
{
	return (multiply(l.end,p,l.start)==0&&
		(l.start.x-p.x)*(l.end.x-p.x)<=0&&
		(l.start.y-p.y)*(l.end.y-p.y)<=0);
}

int intersect(struct Segment a,struct Segment b)
{
	return (max(a.start.x,a.end.x)>=min(b.start.x,b.end.x)&&
		max(b.start.x,b.end.x)>=min(a.start.x,a.end.x)&&
		max(a.start.y,a.end.y)>=min(b.start.y,b.end.y)&&
		max(b.start.y,b.end.y)>=min(a.start.y,a.end.y)&&
		multiply(b.start,a.end,a.start)*multiply(b.end,a.end,a.start)<=0&&
		multiply(a.start,b.end,b.start)*multiply(a.end,b.end,b.start)<=0);
}

int intersect_A(struct Segment a,struct Segment b)
{
	return (intersect(a,b)&&
		(!online(a,b.start))&&(!online(a,b.end))&&
		(!online(b,a.start))&&(!online(b,a.end)));
}

int InsidePolygon(struct Point polygon[],int num,struct Point q)
{
	int i,c=0;
	struct Segment l1,l2;
	l1.start=q;
	l1.end.y=INF;
	l1.end.x=INF;
	for(i=0;i<num;i++)
	{
		l2.start=polygon[i];
		l2.end=polygon[(i+1)%num];
		if(online(l2,q)) return 1;//点在多边形上
		if(intersect_A(l1,l2)||//相交且不在端点
			(online(l1,polygon[(i+1)%num])&&//第二个端点在射线上
			((!online(l1,polygon[(i+2)%num]))&&
			multiply(polygon[i],polygon[(i+1)%num],l1.start)*multiply(polygon[(i+1)%num],polygon[(i+2)%num],l1.start)>0||//前一个端点和后一个端点在射线两侧
			online(l1,polygon[(i+2)%num])&&
			multiply(polygon[i],polygon[(i+2)%num],l1.start)*multiply(polygon[(i+2)%num],polygon[(i+3)%num],l1.start)>0)))//下一条边是水平线，前一个端点和后一个端点在射线两侧
			c++;
	}
	if(c%2==1) return 0;//点在多边形内
	return 2;//点在多边形外
}
int main()
{
	int i,j,N,M,ans,wrong;
	struct Segment a,b;
	while(scanf("%d%d",&N,&M)!=EOF)
	{
		if(N==0&&M==0)break;
		for(i=0;i<N;i++)
		{
			scanf("%d%d",&point1[i].x,&point1[i].y);
		}
		for(i=0;i<M;i++)
		{
			scanf("%d%d",&point2[i].x,&point2[i].y);
		}
		N=Graham_Scan(point1,N,res1);
		M=Graham_Scan(point2,M,res2);
		wrong=0;
		for(i=0;i<M;i++)
		{
			ans=InsidePolygon(res1,N,res2[i]);
			if(ans!=2)
			{
				wrong=1;
				break;
			}
		}
		if(wrong)
		{
			printf("NO\n");
			continue;
		}
		for(i=0;i<N;i++)
		{
			ans=InsidePolygon(res2,M,res1[i]);
			if(ans!=2)
			{
				wrong=1;
				break;
			}
		}
		if(wrong)
		{
			printf("NO\n");
			continue;
		}
		for(i=0;i<N&&!wrong;i++)
		{
			for(j=0;j<M;j++)
			{
				a.start=res1[i];
				a.end=res1[(i+1)%N];
				b.start=res2[j];
				b.end=res2[(j+1)%M];
				if(intersect(a,b))
				{
					wrong=1;
					break;
				}
			}
		}
		if(wrong) printf("NO\n");
		else printf("YES\n");
	}
	return 0;
}