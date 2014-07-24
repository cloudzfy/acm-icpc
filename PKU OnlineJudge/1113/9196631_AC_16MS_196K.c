#include <stdio.h>
#include <stdlib.h>
#include <math.h>
struct Point
{
	int x,y;
}point[1000],res[1000];
int N;
int cmp(const void *a,const void *b)
{
	if(((struct Point*)a)->y==((struct Point*)b)->y)
		return ((struct Point*)a)->x-((struct Point*)b)->x;
	return ((struct Point*)a)->y-((struct Point*)b)->y;
}
int product(struct Point cur,struct Point now,struct Point last)
{
	if((cur.x-now.x)*(now.y-last.y)-(now.x-last.x)*(cur.y-now.y)<0) return 1;
	return 0;
}
int Graham_Scan()
{
	int top=1,len,i;
	qsort(point,N,sizeof(point[0]),cmp);
	if(N==0) return 0;
	res[0]=point[0];
	if(N==1) return 1;
	res[1]=point[1];
	if(N==2) return 2;
	res[2]=point[2];
	for(i=2;i<N;i++)
	{
		while(top&&!product(point[i],res[top],res[top-1])) top--;
		res[++top]=point[i];
	}
	len=top;
	res[++top]=point[N-2];
	for(i=N-3;i>=0;i--)
	{
		while(len<top&&!product(point[i],res[top],res[top-1])) top--;
		res[++top]=point[i];
	}
	return top;
}
int main()
{
	double pi=3.1415926,result;
	int L,i,num;
	while(scanf("%d%d",&N,&L)!=EOF)
	{
		for(i=0;i<N;i++)
		{
			scanf("%d%d",&point[i].x,&point[i].y);
		}
		num=Graham_Scan();
		result=2*pi*L;
		for(i=1;i<num;i++)
		{
			result+=sqrt((double)((res[i].x-res[i-1].x)*(res[i].x-res[i-1].x)+(res[i].y-res[i-1].y)*(res[i].y-res[i-1].y)));
		}
		result+=sqrt((double)((res[0].x-res[i-1].x)*(res[0].x-res[i-1].x)+(res[0].y-res[i-1].y)*(res[0].y-res[i-1].y)));
		printf("%.0f\n",result);
	}
	return 0;
}