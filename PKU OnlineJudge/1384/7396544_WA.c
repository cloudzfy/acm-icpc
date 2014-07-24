#include <stdio.h>
int main()
{
	long int i,j,e,f,n,p,w,x[10001];
	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d %d %d",&e,&f,&n);
		f=f-e;
		for(j=0;j<=f;j++)
		{
			x[j]=0;
		}
		scanf("%d %d",&p,&w);
		for(j=f;j>=w;j--)
		{
			if(j%w==0) x[j]=p*j/w;
		}
		for(i=1;i<n;i++)
		{
			scanf("%d %d",&p,&w);
			if(x[w]==0) x[w]=p;
			for(j=w;j<=f;j++)
				if(x[j]>x[j-w]+p) x[j]=x[j-w]+p;
		}
		if(x[f]==0&&f!=0) printf("This is impossible.\n");
		else printf("The minimum amount of money in the piggy-bank is %d.\n",x[f]);
	}
	return 0;
}