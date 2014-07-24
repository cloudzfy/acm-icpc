#include <stdio.h>
int h[100][100],dp[100][100],r,c,result=0;
int height(int i,int j)
{
	int left,right,up,down;
	if(dp[i][j]!=-1) return dp[i][j];
	if(j!=0)
	{
		if(h[i][j]<=h[i][j-1]) left=-1;
		else left=height(i,j-1);
		if(dp[i][j]<left) dp[i][j]=left;
	}
	if(j!=c-1)
	{
		if(h[i][j]<=h[i][j+1]) right=-1;
		else right=height(i,j+1);
		if(dp[i][j]<right) dp[i][j]=right;
	}
	if(i!=0)
	{
		if(h[i][j]<=h[i-1][j]) up=-1;
		else up=height(i-1,j);
		if(dp[i][j]<up) dp[i][j]=up;
	}
	if(i!=r-1)
	{
		if(h[i][j]<=h[i+1][j]) down=-1;
		else down=height(i+1,j);
		if(dp[i][j]<down) dp[i][j]=down;
	}
	dp[i][j]++;
	if(result<dp[i][j]) result=dp[i][j];
	return dp[i][j];
}

int main()
{
	int i,j;
	scanf("%d %d",&r,&c);
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
	return 0;
}