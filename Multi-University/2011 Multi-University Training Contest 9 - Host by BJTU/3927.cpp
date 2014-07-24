#include <stdio.h>
int map[200][200];
int main()
{
	int t,i,n,x,j,k;
	scanf("%d",&t);
	for(i=1;i<=t;i++)
	{
		scanf("%d",&n);
		x=1;
		for(j=0;j<n;j++)
		{
			for(k=0;k<n-1;k++)
			{
				map[j][k]=x++;
			}
		}
		for(j=0;j<n;j++)
		{
			map[j][n-1]=x++;
		}
		printf("Case #%d:\n",i);
		for(j=0;j<n;j++)
		{
			printf("%d",map[j][0]);
			for(k=1;k<n;k++)
			{
				printf(" %d",map[j][k]);
			}
			printf("\n");
		}
	}
	return 0;
}