/* POJ 2079
 * 计算几何（凸包+旋转卡壳）
 * 注意：求解三角形最大面积，暂未证明
 * Memory:600K Time:63MS
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

double area(int n)
{
	double ans=0,x;
	int q=1,i,j=1,m=2;
	for(i=0;i<n;i++)
	{
		while(abs(multiply(res[(m+1)%n],res[j],res[i]))>abs(multiply(res[m],res[j],res[i])))m=(m+1)%n;
		if(ans<abs(multiply(res[m],res[j],res[i])))ans=abs(multiply(res[m],res[j],res[i]));
		while(abs(multiply(res[m],res[(j+1)%n],res[i]))>abs(multiply(res[m],res[j],res[i])))j=(j+1)%n;
		if(ans<abs(multiply(res[m],res[j],res[i])))ans=abs(multiply(res[m],res[j],res[i]));
	}
	return ans;
}
int main()
{
	double result;
	int i,N;
	while(scanf("%d",&N)!=EOF)
	{
		if(N==-1)break;
		for(i=0;i<N;i++)
		{
			scanf("%d%d",&point[i].x,&point[i].y);
		}
		N=Graham_Scan(N);
		if(N<3)
		{
			printf("0.00\n");
		}
		else
		{
			result=area(N);
			printf("%.2f\n",result/2);
		}
	}
	return 0;
}