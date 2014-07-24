/* POJ 2187
 * 凸包+旋转卡壳
 * Memory:564K	Time:125MS
 */
#include <stdio.h>
#include <stdlib.h>
struct Point
{
	int x,y;
}point[50000],res[50000];
int cmp(const void *a,const void *b)
{
	if(((struct Point*)a)->y==((struct Point*)b)->y)
		return ((struct Point*)a)->x-((struct Point*)b)->x;
	return ((struct Point*)a)->y-((struct Point*)b)->y;
}
int multiply(struct Point start,struct Point end,struct Point origin)
{
	return (start.x-origin.x)*(end.y-origin.y)-(end.x-origin.x)*(start.y-origin.y);
}
int Graham_Scan(int n)
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

int dist(struct Point a,struct Point b)
{
	return (a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y);
}

int rotating_calipers(int n)
{
	int ans=0,q=1,i;
	for(i=0;i<n;i++)
	{
		while(abs(multiply(res[(q+1)%n],res[(i+1)%n],res[i]))>abs(multiply(res[q],res[(i+1)%n],res[i])))
			q=(q+1)%n;
		if(ans<dist(res[i],res[q]))ans=dist(res[i],res[q]);
	}
	return ans;
}

int main()
{
	int i,N,result;
	scanf("%d",&N);
	for(i=0;i<N;i++)
	{
		scanf("%d%d",&point[i].x,&point[i].y);
	}
	N=Graham_Scan(N);
	if(N==2)
	{
		result=dist(res[0],res[1]);
		printf("%d\n",result);
	}
	else
	{
		result=rotating_calipers(N);
		printf("%d\n",result);
	}
	return 0;
}