#include <stdio.h>
#include <string.h>
int f[15001][21];
int main()
{
	int i,j,k,C,G,h[20],w;
	scanf("%d %d",&C,&G);
		memset(f,0,sizeof(f));
		f[7500][0]=1;
		for(i=0;i<C;i++)
			scanf("%d",&h[i]);
		for(i=0;i<G;i++)
		{
			scanf("%d",&w);
			for(j=0;j<C;j++)
			{
				if(h[j]<0)
				{
					for(k=15000;k>=-w*h[j];k--)
					{
						if(f[k][i]!=0)
						{
							f[k+w*h[j]][i+1]+=f[k][i];
						}
					}
				}
				else
				{
					for(k=1;k<=15000-w*h[j];k++)
					{
						if(f[k][i]!=0)
						{
							f[k+w*h[j]][i+1]+=f[k][i];
						}
					}
				}
			}
		}
		printf("%d\n",f[7500][G]);
	return 0;
}