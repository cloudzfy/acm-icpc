#include <stdio.h>
int main()
{
	long int i,j,k,n,m,a[100],c[100],f[100001][2],result;
	while(scanf("%d %d",&n,&m)!=EOF)
	{
		if(n==0&&m==0) break;
		if(m<=0)
		{
			printf("0\n");
			continue;
		}
		f[0][1]=1;
		for(i=1;i<=m;i++)
			f[i][1]=0;
		for(i=0;i<n;i++)
			scanf("%d",&a[i]);
		for(i=0;i<n;i++)
			scanf("%d",&c[i]);
		for(i=0;i<n;i++)
		{
			for(j=0;j<=m;j++) f[j][0]=0;
			for(j=1;j<=m;j++)
			{
				if(f[j][1]==0&&j-a[i]>=0)
				{
					if(f[j-a[i]][1]==1&&f[j-a[i]][0]<c[i])
					{
						f[j][1]=1;
						f[j][0]=f[j-a[i]][0]+1;
					}
				}
			}
		}
		result=0;
		for(i=1;i<=m;i++)
			if(f[i][1]==1) result++;
		printf("%d\n",result);
	}
	return 0;
}