#include <stdio.h>
#include <math.h>
struct Point
{
	int x,y;
}point[100];
int multiply(struct Point start,struct Point end,struct Point origin)
{
	return (start.x-origin.x)*(end.y-origin.y)-(end.x-origin.x)*(start.y-origin.y);
}
int gcd(int a,int b)
{
	int tmp;
	while(b)
	{
		tmp=b;
		b=a%b;
		a=tmp;
	}
	return a;
}
int main()
{
	struct Point origin;
	int i,N,t,T,A,E,I;
	origin.x=0;
	origin.y=0;
	scanf("%d",&T);
	for(t=1;t<=T;t++)
	{
		scanf("%d",&N);
		for(i=0;i<N;i++)
		{
			scanf("%d%d",&point[i].x,&point[i].y);
			if(i!=0)
			{
				point[i].x+=point[i-1].x;
				point[i].y+=point[i-1].y;
			}
		}
		A=0;
		for(i=0;i<N;i++)
		{
			A+=multiply(point[i],point[(i+1)%N],origin);
		}
		A=abs(A);
		E=0;
		for(i=0;i<N;i++)
		{
			E+=gcd(abs(point[i].x-point[(i+1)%N].x),abs(point[i].y-point[(i+1)%N].y));
		}
		I=(A-E+2)/2;
		printf("Scenario #%d:\n%d %d %.1f\n\n",t,I,E,(double)A/2);
	}
	return 0;
}