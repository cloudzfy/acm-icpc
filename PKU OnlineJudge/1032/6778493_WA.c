#include <stdio.h>
int main()
{
	int i=1,j,n,sum=0;
	while(scanf("%d",&n)!=EOF)
	{
		i=1;
		sum=0;
		do
		{
			i++;
			sum+=i;
		}while(sum+i+1<=n);
		if(sum==n)
		{
			printf("2");
			for(j=3;j<=i;j++)
			{
				printf(" %d",j);
			}
		}
		else if((n-sum)%(i-1)!=0)
		{
			printf("2");
			for(j=3+(n-sum)/(i-1);j<i+1-(n-sum)%(i-1)+(n-sum)/(i-1);j++)
			{
				printf(" %d",j);
			}
			for(j=i+2-(n-sum)%(i-1)+(n-sum)/(i-1);j<=i+1+(n-sum)/(i-1);j++)
			{
				printf(" %d",j);
			}
		}
		else
		{
			printf("%d",2+(n-sum)/(i-1));
			for(j=3+(n-sum)/(i-1);j<i+1+(n-sum)/(i-1);j++)
			{
				printf(" %d",j);
			}
		}
		printf("\n");
	}
	return 0;
}