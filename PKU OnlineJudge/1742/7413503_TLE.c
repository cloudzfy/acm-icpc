#include <stdio.h>
int main()
{
	long int i,j,k,n,m,a[100],c[100],f[100001],result;
	for(;;)
	{
		scanf("%d %d",&n,&m);
		if(n==0&&m==0) break;
		result=0;
		if(m<=0)
		{
			printf("0\n");
			continue;
		}
		f[0]=1;
		for(i=1;i<=m;i++)
		{
			f[i]=0;
		}
		for(i=0;i<n;i++)
		{
			scanf("%d",&a[i]);
		}
		for(i=0;i<n;i++)
		{
			scanf("%d",&c[i]);
		}
		for(i=0;i<n;i++)
		{
			for(k=1;k*2<=c[i];k*=2)
			{
				for(j=m;j>=k*a[i];j--)
				{
					if(f[j-k*a[i]]!=0&&f[j]!=1)
					{
						f[j]=1;
						result++;
					}
				}
			}
			k=c[i]-k+1;
			for(j=m;j>=k*a[i];j--)
			{
				if(f[j-k*a[i]]!=0&&f[j]!=1)
					{
						f[j]=1;
						result++;
					}
			}
		}
		printf("%d\n",result);
	}
	return 0;
}