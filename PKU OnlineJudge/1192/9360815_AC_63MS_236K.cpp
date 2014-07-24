/* POJ 1192
 * 树形DP
 * Memory:236K	Time:63MS
 */

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <algorithm>
#include <vector>
using namespace std;
#define MAXN 1010
int N;
struct Point
{
	int x,y,c;
}point[MAXN];
int visited[MAXN],dp[MAXN][2];
vector<int> edge[MAXN];
void dfs(int k)
{
	int i,j;
	visited[k]=1;
	dp[k][0]=0;
	dp[k][1]=point[k].c;
	for(i=0;i<(int)edge[k].size();i++)
	{
		j=edge[k][i];
		if(visited[j])continue;
		dfs(j);
		dp[k][0]=max(dp[k][0],max(dp[j][0],dp[j][1]));
		if(dp[j][1]>0)dp[k][1]+=dp[j][1];
	}
}
int main()
{
	int i,j;
	scanf("%d",&N);
	for(i=0;i<N;i++)
	{
		scanf("%d%d%d",&point[i].x,&point[i].y,&point[i].c);
	}
	memset(visited,0,sizeof(visited));
	memset(dp,0,sizeof(dp));
	for(i=0;i<N;i++)
	{
		for(j=i+1;j<N;j++)
		{
			if(abs(point[i].x-point[j].x)+abs(point[i].y-point[j].y)==1)
			{
				edge[i].push_back(j);
				edge[j].push_back(i);
			}
		}
	}
	dfs(0);
	printf("%d\n",max(dp[0][0],dp[0][1]));
	return 0;
}