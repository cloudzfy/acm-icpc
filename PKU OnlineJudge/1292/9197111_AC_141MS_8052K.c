/* POJ 1292
 * 线段距离关系+Prim
 * Memory:8052K Time:157MS
 */
#include <stdio.h>
#include <string.h>
#include <math.h>
struct Wall
{
	double X,Y,L;
}wall[1000];
double map[1000][1000],dis[1000];
int N,used[1000],parent[1000];
double judge(struct Wall a,struct Wall b)
{
	if(a.L>=0&&b.L>=0)
	{
		if(a.X+a.L<b.X) return sqrt((b.X-a.L-a.X)*(b.X-a.L-a.X)+(a.Y-b.Y)*(a.Y-b.Y));
		else if(b.X+b.L<a.X) return sqrt((a.X-b.L-b.X)*(a.X-b.L-b.X)+(a.Y-b.Y)*(a.Y-b.Y));
		else return fabs(a.Y-b.Y);
	}
	else if(a.L<0&&b.L<0)
	{
		if(a.Y-a.L<b.Y) return sqrt((b.Y-a.Y+a.L)*(b.Y-a.Y+a.L)+(a.X-b.X)*(a.X-b.X));
		else if(b.Y-b.L<a.Y) return sqrt((a.Y-b.Y+b.L)*(a.Y-b.Y+b.L)+(a.X-b.X)*(a.X-b.X));
		return fabs(a.X-b.X);
	}
	else if(a.L>=0&&b.L<0)
	{
		if(a.Y<b.Y)
		{
			if(a.X+a.L<b.X) return sqrt((b.X-a.X-a.L)*(b.X-a.X-a.L)+(a.Y-b.Y)*(a.Y-b.Y));
			else if(b.X<a.X) return sqrt((a.X-b.X)*(a.X-b.X)+(a.Y-b.Y)*(a.Y-b.Y));
			else return fabs(a.Y-b.Y);
		}
		else if(b.Y-b.L<a.Y)
		{
			if(a.X+a.L<b.X) return sqrt((b.X-a.X-a.L)*(b.X-a.X-a.L)+(a.Y-b.Y+b.L)*(a.Y-b.Y+b.L));
			else if(b.X<a.X) return sqrt((a.X-b.X)*(a.X-b.X)+(a.Y-b.Y+b.L)*(a.Y-b.Y+b.L));
			else return fabs(a.Y-b.Y+b.L);
		}
		else
		{
			if(a.X+a.L<b.X) return fabs(b.X-a.X-a.L);
			else if(b.X<a.X) return fabs(a.X-b.X);
			else return 0;
		}
	}
	else if(a.L<0&&b.L>=0)
	{
		if(b.Y<a.Y)
		{
			if(b.X+b.L<a.X) return sqrt((a.X-b.X-b.L)*(a.X-b.X-b.L)+(b.Y-a.Y)*(b.Y-a.Y));
			else if(a.X<b.X) return sqrt((b.X-a.X)*(b.X-a.X)+(b.Y-a.Y)*(b.Y-a.Y));
			else return fabs(b.Y-a.Y);
		}
		else if(a.Y-a.L<b.Y)
		{
			if(b.X+b.L<a.X) return sqrt((a.X-b.X-b.L)*(a.X-b.X-b.L)+(b.Y-a.Y+a.L)*(b.Y-a.Y+a.L));
			else if(a.X<b.X) return sqrt((b.X-a.X)*(b.X-a.X)+(b.Y-a.Y+a.L)*(b.Y-a.Y+a.L));
			else return fabs(b.Y-a.Y+a.L);
		}
		else
		{
			if(b.X+b.L<a.X) return fabs(a.X-b.X-b.L);
			else if(a.X<b.X) return fabs(b.X-a.X);
			else return 0;
		}
	}
	return 1000000;
}
void prim()
{
	int i,mark,x=0;
	double min,total=0;
	int times=N-1;
	used[x]=1;
	while(times--)
	{
		for(i=0;i<N;i++)
		{
			if(used[i]) continue;
			if(dis[i]>map[x][i])
			{
				dis[i]=map[x][i];
			}
		}
		min=1000000;
		for(i=0;i<N;i++)
		{
			if(used[i])continue;
			if(min>dis[i])
			{
				min=dis[i];
				mark=i;
				parent[mark]=x;
			}
		}
		x=mark;
		used[x]=1;
	}
}

int main()
{
	int i,j;
	double result;
	while(scanf("%d",&N)!=EOF)
	{
		if(N==0)break;
		for(i=0;i<N;i++)
		{
			scanf("%lf%lf%lf",&wall[i].X,&wall[i].Y,&wall[i].L);
		}
		memset(map,0,sizeof(map));
		for(i=0;i<N;i++)
		{
			map[i][i]=-1;
			for(j=i+1;j<N;j++)
			{
				map[i][j]=judge(wall[i],wall[j]);
				map[j][i]=map[i][j];
			}
		}
		memset(used,0,sizeof(used));
		memset(parent,-1,sizeof(parent));
		for(i=0;i<N;i++)
		{
			dis[i]=1000000;
		}
		dis[0]=0;
		prim();
		result=0;
		for(i=1;i!=-1;i=parent[i])
		{
			if(dis[i]>result)
				result=dis[i];
		}
		printf("%.2f\n",result);
	}
	return 0;
}