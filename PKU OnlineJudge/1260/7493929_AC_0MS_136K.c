#include <stdio.h>
int main()
{
	int t,c,a[100],p[100],i,j,f[100],sum[101];
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&c);
		sum[c]=0;
		for(i=0;i<c;i++)
			sum[i]=0;
		for(i=0;i<c;i++)
		{
			scanf("%d %d",&a[i],&p[i]);
			for(j=0;j<=i;j++)
				sum[j]+=a[i];
		}
		f[0]=(a[0]+10)*p[0];
		for(i=1;i<c;i++)
		{
			f[i]=(sum[0]-sum[i+1]+10)*p[i];
			for(j=i-1;j>=0;j--)
			{
				if(f[i]>f[j]+(sum[j+1]-sum[i+1]+10)*p[i])
					f[i]=f[j]+(sum[j+1]-sum[i+1]+10)*p[i];
			}
		}
		printf("%d\n",f[c-1]);
	}
	return 0;
}