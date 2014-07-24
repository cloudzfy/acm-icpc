#include <stdio.h>
#include <string.h>
int main()
{
	int i,j,x[100][100];
	memset(x,0,sizeof(x));
	while(scanf("%d%d%d",&x[0][99],&x[1][99],&x[2][99])!=EOF)
	{
		for(i=3;i<100;i++)
		{
			for(j=99;j>0;j--)
			{
				x[i][j]+=(x[i-1][j]+x[i-2][j]+x[i-3][j]);
				x[i][j-1]=(x[i][j]-x[i][j]%10)/10;
				x[i][j]=x[i][j]%10;
			}
		}
		for(i=0;i<100;i++)
		{
			if(x[99][i]!=0) break;
		}
		if(i==100) printf("0");
		for(;i<100;i++)
			printf("%d",x[99][i]);
		printf("\n");
		memset(x,0,sizeof(x));
	}
	return 0;
}