#include <stdio.h>
#include <string.h>
int main()
{
	int i,j,x[251][200],n;
	memset(x,0,sizeof(x));
	x[0][199]=1;
	x[1][199]=1;
	x[2][199]=3;
	for(i=3;i<=250;i++)
	{
		for(j=199;j>0;j--)
		{
			x[i][j]+=(x[i-1][j]+x[i-2][j]*2);
			x[i][j-1]=(x[i][j]-x[i][j]%10)/10;
			x[i][j]=x[i][j]%10;
		}
	}
	while(scanf("%d",&n)!=EOF)
	{
		for(i=0;i<200;i++)
		{
			if(x[n][i]!=0) break;
		}
		if(i==200) printf("0");
		for(;i<200;i++)
			printf("%d",x[n][i]);
		printf("\n");
	}
	return 0;
}