#include <stdio.h>
int main()
{
	int room[200],i,j,k,t,n,tmp,a,b,result;
	scanf("%d",&t);
	for(i=0;i<t;i++)
	{
		scanf("%d",&n);
		for(j=0;j<200;j++)
		{
			room[j]=0;
		}
		for(j=0;j<n;j++)
		{
			scanf("%d %d",&a,&b);
			if(a>b)
			{
				tmp=a;
				a=b;
				b=tmp;
			}
			if(a%2==1) a=(a+1)/2;
			else a=a/2;
			if(b%2==1) b=(b+1)/2;
			else b=b/2;
			for(k=a-1;k<b;k++) room[k]++;
		}
		result=0;
		for(j=0;j<200;j++)
		{
			if(room[j]>result) result=room[j];
		}
		printf("%d\n",result*10);
	}
	return 0;
}