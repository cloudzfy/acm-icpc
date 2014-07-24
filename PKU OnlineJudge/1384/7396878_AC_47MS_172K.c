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
		if(f!=0) x[0]=0;
		for(j=1;j<=f;j++)
		{
			x[j]=-1;
		}
		for(i=0;i<n;i++)
		{
			scanf("%d %d",&p,&w);
			for(j=w;j<=f;j++)
				if(x[j-w]!=-1)
					if(x[j]==-1||x[j]>x[j-w]+p) x[j]=x[j-w]+p;
		}
		if(x[f]==-1) printf("This is impossible.\n");
		else printf("The minimum amount of money in the piggy-bank is %d.\n",x[f]);
	}
	return 0;
}