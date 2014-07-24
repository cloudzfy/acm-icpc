/* POJ 1039
 * 计算几何（叉积）
 * 注意：本来是一道很简单的题，但是卡在x可能是负数上了。
 * Memory:200K	Time:47MS
 */
#include <stdio.h>
#define INF 100000
#define eps 1e-10
struct Point
{
	double x,y;
}point[2][20];
struct Segment
{
	struct Point start,end;
};
double multiply(struct Point start,struct Point end,struct Point origin)
{
	return (start.x-origin.x)*(end.y-origin.y)-(end.x-origin.x)*(start.y-origin.y);
}
double intersect_P(struct Segment a,struct Segment b)
{
	double dot1,dot2;
	dot1=multiply(a.end,a.start,b.start);
	dot2=multiply(b.end,a.start,a.end);
	return (b.start.x*dot2+b.end.x*dot1)/(dot2+dot1);
}
int main()
{
	double result,ans;
	struct Segment a,b;
	int i,j,k,l,m,N,flag;
	while(scanf("%d",&N)!=EOF)
	{
		if(N==0)break;
		for(i=0;i<N;i++)
		{
			scanf("%lf%lf",&point[0][i].x,&point[0][i].y);
			point[1][i].x=point[0][i].x;
			point[1][i].y=point[0][i].y-1;
		}
		result=-INF;
		flag=0;
		for(i=0;i<N&&!flag;i++)
		{
			for(j=i+1;j<N&&!flag;j++)
			{
				for(k=0;k<2&&!flag;k++)
				{
					for(l=0;l<2&&!flag;l++)
					{
						ans=-INF;
						a.start=point[k][i];
						a.end=point[l][j];
						flag=1;
						for(m=0;m<N;m++)
						{
							if(multiply(point[l][j],point[0][m],point[k][i])<-eps)
							{
								flag=0;
								if(m==0)break;
								b.start=point[0][m-1];
								b.end=point[0][m];
								ans=intersect_P(a,b);
								break;
							}
							if(multiply(point[l][j],point[1][m],point[k][i])>eps)
							{
								flag=0;
								if(m==0)break;
								b.start=point[1][m-1];
								b.end=point[1][m];
								ans=intersect_P(a,b);
								break;
							}
						}
						if(ans>result)result=ans;
					}
				}
			}
		}
		if(!flag)printf("%.2f\n",result);
		else printf("Through all the pipe.\n");
	}
	return 0;
}