#include <stdio.h>
#include <math.h>
#define eps 1e-8
struct Point
{
	int x,y;
}point[150];
double dist(struct Point a,struct Point b)
{
	return sqrt((double)((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y)));
}
double multiply(struct Point start,struct Point end,struct Point origin)
{
	return (start.x-origin.x)*(end.y-origin.y)-(end.x-origin.x)*(start.y-origin.y);
}
int main()
{
	double R,mu;
	int total,ans1,ans2,result,N,i,j;
	struct Point origin;
	while(scanf("%d%d%lf",&origin.x,&origin.y,&R)!=EOF)
	{
		if(R<0)break;
		total=0;
		result=0;
		scanf("%d",&N);
		for(i=0;i<N;i++)
		{
			scanf("%d%d",&point[total].x,&point[total].y);
			if(dist(point[total],origin)<=R)total++;
		}
		for(i=0;i<total;i++)
		{
			ans1=1;
			ans2=1;
			for(j=0;j<total;j++)
			{
				if(i==j)continue;
				mu=multiply(point[i],point[j],origin);
				if(mu<eps)ans1++;
				if(mu>-eps)ans2++;
			}
			if(result<ans1)result=ans1;
			if(result<ans2)result=ans2;
		}
		printf("%d\n",result);
	}
	return 0;
}