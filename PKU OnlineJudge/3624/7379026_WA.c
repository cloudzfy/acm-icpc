#include <stdio.h>
int main()
{
	int i,j,n,m,c,w,f[12881];
	scanf("%d %d",&n,&m);
	m++;
	for(j=0;j<m;j++)
		f[j]=0;
	for(i=0;i<n;i++)
	{
		scanf("%d %d",&c,&w);
		for(j=m-1;j>=0;j--)
		{
			if(f[j]<f[j-c]+w)
			{
				f[j]=f[j-c]+w;
			}
		}
	}
	for(j=m-2;j>=0;j--)
	{
		if(f[j]>f[m-1])
		{
			f[m-1]=f[j];
		}
	}
	printf("%d\n",f[m-1]);
	return 0;
}