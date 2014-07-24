#include <stdio.h>
int main()
{
	long int i,j,n,m,c,w,f[12881];
	scanf("%d %d",&n,&m);
	for(j=0;j<m+1;j++)
		f[j]=0;
	for(i=0;i<n;i++)
	{
		scanf("%d %d",&c,&w);
		for(j=m;j>=c;j--)
		{
			if(f[j]<f[j-c]+w)
			{
				f[j]=f[j-c]+w;
			}
		}
	}
	printf("%d\n",f[m]);
	return 0;
}