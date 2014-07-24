/* POJ 2148
 * 计算几何+缩点+图着色
 * 比较难，但是关键还是在于忘记图着色的做法
 * Memory:244K	Time:1500MS
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXN 100
#define MAXM 10
struct Point
{
	int x,y;
}point[MAXN][100];
struct Segment
{
	struct Point start,end;
};
int edge[MAXN],map[MAXM][MAXM],color[MAXM],mark[MAXM],country[MAXN],N,M;
char name[MAXM][21];
int multiply(struct Point start,struct Point end,struct Point origin)
{
	return (start.x-origin.x)*(end.y-origin.y)-(end.x-origin.x)*(start.y-origin.y);
}

int pointCmp(struct Point a,struct Point b)
{
	if(a.x==b.x&&a.y==b.y) return 1;
	return 0;
}
int online(struct Segment l,struct Point p)
{
	return (multiply(l.end,p,l.start)==0&&
		(p.x-l.end.x)*(p.x-l.start.x)<=0&&(p.y-l.end.y)*(p.y-l.start.y)<=0
		&&!pointCmp(p,l.start)&&!pointCmp(p,l.end));
}

int judge(struct Segment a,struct Segment b)
{
	int num=0;
	if(online(a,b.start))num++;
	if(online(a,b.end))num++;
	if(online(b,a.start))num++;
	if(online(b,a.end))num++;
	if(pointCmp(a.start,b.start))num++;
	if(pointCmp(a.start,b.end))num++;
	if(pointCmp(a.end,b.start))num++;
	if(pointCmp(a.end,b.end))num++;
	if(num>1) return 1;
	return 0;
}

int dfs(int k,int clr)
{
	int i,j,flag;
	if(k>=M)return 1;
	for(i=1;i<=clr;i++)
	{
		flag=1;
		color[k]=i;
		for(j=0;j<M;j++)
		{
			if(map[k][j]&&color[k]==color[j])flag=0;
		}
		if(flag&&dfs(k+1,clr)) return 1;
		color[k]=0;
	}
	return 0;
}

int main()
{
	char str[21];
	int i,j,k,l,x,y,flag;
	struct Segment a,b;
	while(scanf("%d",&N)!=EOF)
	{
		if(N==0)break;
		M=0;
		memset(edge,0,sizeof(edge));
		for(i=0;i<N;i++)
		{
			scanf("%s",str);
			flag=0;
			for(j=0;j<M;j++)
			{
				if(strcmp(str,name[j])==0)
				{
					flag=1;
					country[i]=j;
					break;
				}
			}
			if(!flag)
			{
				strcpy(name[M],str);
				country[i]=M;
				M++;
			}
			while(1)
			{
				scanf("%d",&x);
				if(x==-1)break;
				scanf("%d",&y);
				point[i][edge[i]].x=x;
				point[i][edge[i]].y=y;
				edge[i]++;
			}
		}
		memset(map,0,sizeof(map));
		for(i=0;i<N;i++)
		{
			for(k=i+1;k<N;k++)
			{
				if(country[i]==country[k])continue;
				for(j=0;j<edge[i]&&!map[country[i]][country[k]];j++)
				{
					for(l=0;l<edge[k];l++)
					{
						a.start=point[i][j];
						a.end=point[i][(j+1)%edge[i]];
						b.start=point[k][l];
						b.end=point[k][(l+1)%edge[k]];
						if(judge(a,b))
						{
							map[country[i]][country[k]]=1;
							map[country[k]][country[i]]=1;
							break;
						}
					}
				}
			}
		}
		for(i=1;i<=M;i++)
		{
			memset(color,0,sizeof(color));
			if(dfs(0,i))break;
		}
		printf("%d\n",i);
	}
	return 0;
}