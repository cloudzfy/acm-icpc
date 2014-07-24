#include <stdio.h>
int h[109][109],dp[109][109],r,c,result;
int height(int i,int j)
{
	int center,left,right,up,down;
	center=-1;
	if(j==0||h[i][j]<h[i][j-1]) left=-1;
	else left=height(i,j-1);
	if(center<left) center=left;
	if(j==c-1||h[i][j]<h[i][j+1]) right=-1;
	else right=height(i,j+1);
	if(center<right) center=right;
	if(i==0||h[i][j]<h[i-1][j]) up=-1;
	else up=height(i-1,j);
	if(center<up) center=up;
	if(i==r-1||h[i][j]<h[i+1][j]) down=-1;
	else down=height(i+1,j);
	if(center<down) center=down;
	dp[i][j]=center+1;
	if(result<dp[i][j]) result=dp[i][j];
	return dp[i][j];
}

int main()
{
	int i,j;
	while(scanf("%d %d",&r,&c)!=EOF)
	{
		for(i=0;i<r;i++)
		{
			for(j=0;j<c;j++)
			{
				scanf("%d",&h[i][j]);
				dp[i][j]=-1;
			}
		}
		for(i=0;i<r;i++)
		{
			for(j=0;j<c;j++)
			{
				if(dp[i][j]==-1) height(i,j);
			}
		}
		printf("%d\n",result+1);
	}
	return 0;
}