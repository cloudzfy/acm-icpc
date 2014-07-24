#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int cmp(const void *a,const void *b)
{
	return *(int*)b-*(int*)a;
}
int main()
{
	double sum;
	int i,j,k,l,t,n,m[100],b[100][100],p[100][100],sort[10000],dp[10000][2];
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		k=0;
		for(i=0;i<n;i++)
		{
			scanf("%d",&m[i]);
			for(j=0;j<m[i];j++)
			{
				scanf("%d %d",&b[i][j],&p[i][j]);
				sort[k]=b[i][j];
				k++;
			}
		}
		qsort(sort,k,sizeof(sort[0]),cmp);
		for(i=1;i<k;i++)
			if(sort[i]==sort[i-1])
				sort[i-1]=0;
		qsort(sort,k,sizeof(sort[0]),cmp);
		for(i=k-1;i>=0;i--)
		{
			if(sort[i]!=0) break;
		}
		k=i+1;
		for(i=0;i<k;i++)
		{
			dp[i][0]=0;
			dp[i][1]=0;
		}
		for(i=0;i<n;i++)
		{
			for(j=0;j<m[i];j++)
			{
				for(l=0;l<k;l++)
				{
					if(b[i][j]>=sort[l])
					{
						if(p[i][j]<dp[l][1]||dp[l][1]==0)
							dp[l][1]=p[i][j];
					}
				}
			}
			for(l=0;l<k;l++)
			{
				if(dp[l][1]==0)
				{
					dp[l][0]=-1;
					continue;
				}
				else if(dp[l][0]!=-1)
				{
					dp[l][0]+=dp[l][1];
					dp[l][1]=0;
				}
			}
		}
		sum=0;
		for(l=0;l<k;l++)
		{
			if(dp[l][0]!=-1)
			{
				if(sum<(double)sort[l]/(double)dp[l][0])
					sum=(double)sort[l]/(double)dp[l][0];
			}
		}
		printf("%.3f\n",sum);
	}
	return 0;
}