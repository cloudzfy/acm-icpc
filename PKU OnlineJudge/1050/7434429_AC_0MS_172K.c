#include <stdio.h>
int main()
{
	long int sum=0,result=0;
	int i,j,k,n,m[100][100];
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			scanf("%d",&m[i][j]);
			if(result<m[i][j]) result=m[i][j];
		}
	}
	for(i=0;i<n;i++)
	{
		for(j=i+1;j<n;j++)
		{
			sum=0;
			for(k=0;k<n;k++)
			{
				m[i][k]+=m[j][k];
				sum+=m[i][k];
				if(result<sum) result=sum;
				if(sum<0) sum=0;
			}
		}
	}
	printf("%d\n",result);
	return 0;
}