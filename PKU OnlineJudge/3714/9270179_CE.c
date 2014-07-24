#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <algorithm>
using namespace std;
#define MAXN 200000
#define INF 2000000010
#define eps 1e-10
struct Point
{
	double x,y;
}point[MAXN];
int N,idx[MAXN],idy[MAXN];
inline int sig(double k)
{
	return (k<-eps)?-1:(k>eps);
}
int cmpx(const void *a,const void *b)
{
	return sig(point[*((int*)a)].x-point[*((int*)b)].x);
}
int cmpy(const void *a,const void *b)
{
	return sig(point[*((int*)a)].y-point[*((int*)b)].y);
}
inline double dist(int a,int b)
{
	if(a<N&&b<N) return INF;
	if(a>=N&&b>=N) return INF;
	return sqrt((double)((point[a].x-point[b].x)*(point[a].x-point[b].x)+(point[a].y-point[b].y)*(point[a].y-point[b].y)));
}
double judge(int left,int right)
{
	double ans;
	int i,j,mid,num;
	if(right-left==1)return dist(idx[left],idx[right]);
	if(right-left==2)
		return min(dist(idx[left],idx[left+1]),min(dist(idx[left+1],idx[left+2]),dist(idx[left+2],idx[left])));
	mid=(left+right)>>1;
	ans=min(judge(left,mid),judge(mid+1,right));
	num=0;
	for(i=left;i<=right;i++)
	{
		if(point[idx[i]].x>=point[idx[mid]].x-ans&&point[idx[i]].x<=point[idx[mid]].x+ans)
		{
			idy[num++]=idx[i];
		}
	}
	qsort(idy,num,sizeof(idy[0]),cmpy);
	for(i=0;i<num;i++)
	{
		for(j=i+1;j<num;j++)
		{
			if(point[idy[j]].y-point[idy[i]].y>=ans)break;
			ans=min(ans,dist(idy[j],idy[i]));
		}
	}
    return ans;
}
int main()
{
	double result;
	int i,T;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&N);
		for(i=0;i<N*2;i++)
		{
			scanf("%lf%lf",&point[i].x,&point[i].y);
			idx[i]=i;
		}
		qsort(idx,N*2,sizeof(idx[0]),cmpx);
		result=judge(0,2*N-1);
		printf("%.3f\n",result);
	}
	return 0;
}