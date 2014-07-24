#include <stdio.h>
long int x[10001][500];
int main()
{
	long int i,j,e,f,n,p,w;
	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d %d %d",&e,&f,&n);
		f=f-e;
		for(i=0;i<n;i++)
		{
			for(j=0;j<=f;j++)
			{
				x[i][j]=0;
			}
		}
		scanf("%d %d",&p,&w);
		for(j=f;j>=w;j--)
		{
			if(j%w==0) x[0][j]=p*j/w;
		}
		for(i=1;i<n;i++)
		{
			scanf("%d %d",&p,&w);
			for(j=0;j<w;j++)
			{
				x[i][j]=x[i-1][j];
			}
			for(j=w;j<=f;j++)
			{
				if(x[i-1][j]>=x[i][j-w]+p) x[i][j]=x[i][j-w]+p;
				else x[i][j]=x[i-1][j];
			}
			
		}
		if(x[n-1][f]==0) printf("This is impossible.\n");
		else printf("The minimum amount of money in the piggy-bank is %d.\n",x[n-1][f]);
	}
	return 0;
}