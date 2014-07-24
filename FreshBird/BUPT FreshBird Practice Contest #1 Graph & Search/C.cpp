#include <stdio.h>
#include <math.h>
#include <string.h>
double map[50][50],dis[50],result;
int point[50][2],used[50];
int n;
void prim(int k)
{
	int i,mark,x;
	double min,total=0;
	int times=n-2;
	if(k==0)x=1;
	else x=0;
	used[x]=1;
	while(times--)
	{
		for(i=0;i<n;i++)
		{
			if(i==k) continue;
			if(used[i]) continue;
			if(dis[i]>map[x][i])
			{
				dis[i]=map[x][i];
			}
		}
		min=100000;
		for(i=0;i<n;i++)
		{
			if(i==k) continue;
			if(used[i])continue;
			if(min>dis[i])
			{
				min=dis[i];
				mark=i;
			}
		}
		x=mark;
		used[x]=1;
		total+=min;
	}
	if(result>total)result=total;
}

int main()
{
	int t,i,j;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(i=0;i<n;i++)
		{
			scanf("%d%d",&point[i][0],&point[i][1]);
		}
		if(n==1)
		{
			printf("0.00\n");
			continue;
		}
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				map[i][j]=sqrt((double)((point[i][0]-point[j][0])*(point[i][0]-point[j][0])+(point[i][1]-point[j][1])*(point[i][1]-point[j][1])));
				map[j][i]=map[i][j];
			}
		}
		result=100000;
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				dis[j]=100000;
			}
			memset(used,0,sizeof(used));
			prim(i);
		}
		printf("%.2f\n",result);
	}
	return 0;
}