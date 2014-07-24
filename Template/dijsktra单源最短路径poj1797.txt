#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int map[1005][1005],have[1005],step[1005],n;
void search()
{
	int now=1,max,i=1,j,count=n-1;
	have[1]=1;
	while(count--)
	{
		max=0;
		for(j=2;j<=n;j++)
		{
			if(have[j]==1) continue;
			if(map[i][j]!=-1)
			{
				if(step[i]>=map[i][j]&&step[j]<map[i][j])
					step[j]=map[i][j];
				else if(step[i]<map[i][j]&&step[j]<step[i])
					step[j]=step[i];
			}
			if(max<step[j])
			{
				max=step[j];
				now=j;
			}
		}
		if(n==now) break;
		have[now]=1;
		i=now;
	}
}
int main()
{
	int i,j,m,t,t1=1,s,e,w;
	scanf("%d",&t);
	while(t--)
	{
		memset(map,-1,sizeof(map));
		memset(step,-1,sizeof(step));
		memset(have,0,sizeof(have));
		scanf("%d%d",&n,&m);
		for(i=0;i<m;i++)
		{
			scanf("%d%d%d",&s,&e,&w);
			map[s][e]=w;
			map[e][s]=w;
		}
		step[1]=9999999;
		search();
		printf("Scenario #%d:\n%d\n\n",t1,step[n]);
		t1++;
	}
	return 0;
}

