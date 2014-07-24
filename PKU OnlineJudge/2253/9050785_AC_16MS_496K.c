#include <stdio.h>
#include <math.h>
#include <string.h>
int point[200][2],used[200];
double map[200][200],dis[200];
int main()
{
	int t=1,n,i,j,mark;
	double result,m;
	while(scanf("%d",&n)!=EOF)
	{
		if(n==0) break;
		memset(used,0,sizeof(used));
		for(i=0;i<n;i++)
		{
			scanf("%d%d",&point[i][0],&point[i][1]);
		}
		for(i=0;i<n;i++)
		{
			for(j=i;j<n;j++)
			{
				map[i][j]=sqrt((double)((point[i][0]-point[j][0])*(point[i][0]-point[j][0])+(point[i][1]-point[j][1])*(point[i][1]-point[j][1])));
				map[j][i]=map[i][j];
			}
		}
		result=0;
		for(j=0;j<n;j++)
		{
			dis[j]=100000;
		}
		used[0]=1;
		mark=0;
		for(i=0;i<n-1;i++)
		{
			for(j=0;j<n;j++)
			{
				if(mark==j) continue;
				if(map[mark][j]<dis[j]) dis[j]=map[mark][j];
			}
			m=100000;
			for(j=0;j<n;j++)
			{
				if(!used[j]&&dis[j]<m)
				{
					m=dis[j];
					mark=j;
				}
			}
			used[mark]=j;
			if(result<m)result=m;
			if(mark==1)break;
		}
		printf("Scenario #%d\nFrog Distance = %.3f\n\n",t,result);
		t++;
	}
	return 0;
}