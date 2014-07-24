/* POJ 2195
 * KM算法
 */
#include <stdio.h>
#include <string.h>
#include <math.h>
#define INF 1000000
char map[100][101];
int house[101][2],man[101][2],pos[101][101];
int lx[101],ly[101],x[101],y[101],link[101];
int N,M;
int dfs(int u)
{
	int v;
	x[u]=1;
	for(v=1;v<=M;v++)
	{
		if(!y[v]&&lx[u]+ly[v]==pos[u][v])
		{
			y[v]=1;
			if(!link[v]||dfs(link[v]))
			{
				link[v]=u;
				return 1;
			}
		}
	}
	return 0;
}
int KM()
{
	int i,j,mi,k,ans;
	for(i=1;i<=N;i++)
	{
		lx[i]=pos[i][1];
		for(j=2;j<=M;j++)
		{
			if(lx[i]<pos[i][j])lx[i]=pos[i][j];
		}
	}
	memset(ly,0,sizeof(ly));
	memset(link,0,sizeof(link));
	for(i=1;i<=N;i++)
	{
		while(1)
		{
			memset(x,0,sizeof(x));
			memset(y,0,sizeof(y));
			if(dfs(i))break;
			mi=INF;
			for(j=1;j<=N;j++)
			{
				if(x[j])
				{
					for(k=1;k<=M;k++)
					{
						if(!y[k]&&mi>lx[j]+ly[k]-pos[j][k])
							mi=lx[j]+ly[k]-pos[j][k];
					}
				}
			}
			for(j=1;j<=N;j++)if(x[j])lx[j]-=mi;
			for(j=1;j<=M;j++)if(y[j])ly[j]+=mi;
		}
	}
	ans=0;
	for(i=1;i<=M;i++)
	{
		if(link[i]>0)ans+=pos[link[i]][i];
	}
	return ans;
}
int main()
{
	int m,h,i,j;
	while(scanf("%d%d",&N,&M)!=EOF)
	{
		if(N==0&&M==0)break;
		m=1;
		h=1;
		for(i=0;i<N;i++)
		{
			scanf("%s",map[i]);
			for(j=0;map[i][j]!=0;j++)
			{
				if(map[i][j]=='H')
				{
					house[h][0]=i;
					house[h][1]=j;
					h++;
				}
				else if(map[i][j]=='m')
				{
					man[m][0]=i;
					man[m][1]=j;
					m++;
				}
			}
		}
		m--;
		h--;
		memset(pos,0,sizeof(pos));
		for(i=1;i<=h;i++)
		{
			for(j=1;j<=m;j++)
			{
				pos[i][j]=-abs(house[i][0]-man[j][0])-abs(house[i][1]-man[j][1]);
			}
		}
		N=M=m;
		printf("%d\n",-KM());
	}
	return 0;
}