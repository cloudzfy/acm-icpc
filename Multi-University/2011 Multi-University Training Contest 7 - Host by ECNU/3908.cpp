#include <stdio.h>
#include <string.h>
int data[800],A[800],B[800];
int gcd(int x, int y)
{
	int t;
	while(y>0)
	{
		t=x%y;
		x=y;
		y=t;
	}
	return x;
}
int main()
{
	int t,n,i,j,result,sum;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(i=0;i<n;i++)
		{
			scanf("%d",&data[i]);
		}
		memset(A,0,sizeof(A));
		memset(B,0,sizeof(B));
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				if(i!=j)
				{
					if(gcd(data[i],data[j])==1) A[i]++;
					else B[i]++;
				}
			}
		}
		sum=0;
		for(i=0;i<n;i++)
		{
			sum+=A[i]*B[i];
		}
		result=n*(n-1)*(n-2)/6-sum/2;
		printf("%d\n",result);
	}
	return 0;
}