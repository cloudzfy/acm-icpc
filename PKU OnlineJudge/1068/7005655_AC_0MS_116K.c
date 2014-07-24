#include <stdio.h>
#include <string.h>
int main()
{
	int s[40],i,j,k,l,t,n,p[21],w[20],x;
	scanf("%d",&t);
	for(i=0;i<t;i++)
	{
		scanf("%d",&n);
		k=0;
		p[0]=0;
		for(j=0;j<n;j++)
		{
			scanf("%d",&p[j+1]);
			x=k;
			for(;k<p[j+1]-p[j]+x;k++)
			{
				s[k]=0;
			}
			s[k]=1;
			k++;
		}
		l=0;
		for(j=0;j<n*2;j++)
		{
			if(s[j]==1)
			{
				w[l]=0;
				for(k=j;k>=0;k--)
				{
					if(s[k]==1) w[l]++;
					if(s[k]==0)
					{
						s[k]=2;
						l++;
						break;
					}
				}
			}
		}
		printf("%d",w[0]);
		for(l=1;l<n;l++)
		{
			printf(" %d",w[l]);
		}
		printf("\n");
	}
	return 0;
}