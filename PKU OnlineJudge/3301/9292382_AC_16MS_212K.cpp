/* POJ 3301
 * 三分法+计算几何
 * Memory:212K	Time:16MS
 */
#include <stdio.h>
#include <math.h>
#include <algorithm>
using namespace std;
#define eps 1e-10
#define PI acos(-1.0)
#define MAX 510
int N;
struct Point
{
	double x,y;
}point[30];
double cal(double a)
{
	double left=MAX,right=-MAX,top=-MAX,bottom=MAX,x,y;
	int i;
	for(i=0;i<N;i++)
	{
		x=point[i].x*cos(a)-point[i].y*sin(a);
		y=point[i].y*cos(a)+point[i].x*sin(a);
		if(y>top)top=y;
		if(y<bottom)bottom=y;
		if(x<left)left=x;
		if(x>right)right=x;
	}
	return max(top-bottom,right-left);
}
double solve()
{
	double mid,midmid,left=0,right=PI;
	while(right-left>eps)
	{
		mid=(left+right)/2;
		midmid=(mid+right)/2;
		if(cal(mid)<cal(midmid))right=midmid;
		else left=mid;
	}
	return cal(mid);
}
int main()
{
	double a;
	int T,i;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&N);
		for(i=0;i<N;i++)
		{
			scanf("%lf%lf",&point[i].x,&point[i].y);
		}
		a=solve();
		printf("%.2f\n",a*a);
	}
	return 0;
}