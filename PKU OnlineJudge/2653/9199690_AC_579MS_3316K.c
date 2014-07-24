#include <stdio.h>
#define EPS 1e-8
struct Point
{
	double x1,y1,x2,y2;
}stick[100000];
int top[1000];
int crossProduct(double x1,double x2,double y1,double y2)
{
	if(x1*y2-x2*y1<EPS) return -1;
	return 1;
}
int intersect(struct Point a,struct Point b)
{
	int ans1,ans2,ans3,ans4;
	ans1=crossProduct(b.x1-a.x1,a.x2-a.x1,b.y1-a.y1,a.y2-a.y1);
	ans2=crossProduct(b.x2-a.x1,a.x2-a.x1,b.y2-a.y1,a.y2-a.y1);
	ans3=crossProduct(a.x1-b.x1,b.x2-b.x1,a.y1-b.y1,b.y2-b.y1);
	ans4=crossProduct(a.x2-b.x1,b.x2-b.x1,a.y2-b.y1,b.y2-b.y1);
	if(ans1*ans2==-1&&ans3*ans4==-1)
		return 1;
	return 0;
}
int main()
{
	int i,j,total,N,ans;
	while(scanf("%d",&N)!=EOF)
	{
		if(N==0)break;
		for(i=0;i<N;i++)
		{
			scanf("%lf%lf%lf%lf",&stick[i].x1,&stick[i].y1,&stick[i].x2,&stick[i].y2);
		}
		total=0;
		for(i=0;i<N;i++)
		{
			ans=0;
			for(j=i+1;j<N;j++)
			{
				ans=intersect(stick[i],stick[j]);
				if(ans)break;
			}
			if(!ans) top[total++]=i+1;
		}
		printf("Top sticks: %d",top[0]);
		for(i=1;i<total;i++)
			printf(", %d",top[i]);
		printf(".\n");
	}
	return 0;
}