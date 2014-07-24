#include <stdio.h>
#include <string.h>

int main()
{
	int x,density[20][20],input[22][22],d[16],i,j,k,t;
	scanf("%d",&t);
	for(i=0;i<16;i++)
	{
		scanf("%d",&d[i]);
	}
	for(i=0;i<22;i++)
	{
		input[0][i]=0;
		input[21][i]=0;
	}
	for(i=1;i<21;i++)
	{
		input[i][0]=0;
		input[i][21]=0;
		for(j=1;j<21;j++)
		{
			scanf("%d",&input[i][j]);
			density[i-1][j-1]=input[i][j];
		}
	}
	for(i=0;i<t;i++)
	{
		for(j=1;j<21;j++)
		{
			for(k=1;k<21;k++)
			{
				x=input[j-1][k]+input[j+1][k]+input[j][k-1]+input[j][k+1];
				if(d[x]+input[j][k]>3) density[j-1][k-1]=3;
				else if(d[x]+input[j][k]<0) density[j-1][k-1]=0;
				else density[j-1][k-1]+=d[x];
			}
		}
		for(j=1;j<21;j++)
		{
			for(k=1;k<21;k++)
			{
				input[j][k]=density[j-1][k-1];
			}
		}
	}
	for(i=0;i<20;i++)
	{
		if(density[i][0]==0) printf(".");
		else if(density[i][0]==1) printf("!");
		else if(density[i][0]==2) printf("X");
		else printf("#");
		for(j=1;j<20;j++)
		{
			if(density[i][j]==0) printf(" .");
		    else if(density[i][j]==1) printf(" !");
		    else if(density[i][j]==2) printf(" X");
		    else printf(" #");
		}
		printf("\n");
	}
	return 0;
}