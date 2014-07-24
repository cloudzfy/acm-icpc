#include <stdio.h>
#include <algorithm>
#include <queue>
using namespace std;
int map[2010][2010],sex[2010],n;
int bfs()
{
	int i,j,cur;
	queue<int> q;
	for(i=0;i<n;i++)
	{
		if(sex[i]!=-1)continue;
		q.push(i);
		sex[i]=0;
		while(!q.empty())
		{
			cur=q.front();
			q.pop();
			for(j=0;j<n;j++)
			{
				if(map[cur][j])
				{
					if(cur==j) return 0;
					if(sex[j]!=-1)
					{
						if(sex[j]==sex[cur])return 0;
					}
					else
					{
						sex[j]=(sex[cur]+1)%2;
						q.push(j);
					}
				}
			}
		}
	}
	return 1;
}

int main()
{
	int ans,i,t,m,a,b;
	scanf("%d",&t);
	for(i=1;i<=t;i++)
	{
		memset(sex,-1,sizeof(sex));
		memset(map,0,sizeof(map));
		scanf("%d%d",&n,&m);
		while(m--)
		{
			scanf("%d%d",&a,&b);
			map[a-1][b-1]=1;
			map[b-1][a-1]=1;
		}
		ans=bfs();
		if(i>1)printf("\n");
		printf("Scenario #%d:\n",i);
		if(!ans)printf("Suspicious bugs found!\n");
		else printf("No suspicious bugs found!\n");
	}
	return 0;
}