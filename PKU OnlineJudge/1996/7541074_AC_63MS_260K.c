#include <stdio.h>
#include <string.h>
int main()
{
	int i,j,k,l,n,m,t,p[101],q[101],tmp[10001],tmp2[10001],r[10001];
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d %d",&n,&m);
		for(i=0;i<=n;i++)
			scanf("%d",&p[i]);
		for(i=0;i<=m;i++)
			scanf("%d",&q[i]);
		memset(tmp,0,sizeof(int)*10001);
		memset(r,0,sizeof(int)*10001);
		for(i=0;i<=n;i++)
		{
			memset(tmp2,0,sizeof(int)*10001);
			if(i>1)
			{
				for(j=0;j<=m*(i-1);j++)
					for(k=0;k<=m;k++)
						tmp2[j+k]+=tmp[j]*q[k];
				for(j=0;j<=m*i;j++)
					tmp[j]=tmp2[j];
			}
			else if(i==1)
			{
				for(j=0;j<=m;j++)
					tmp[j]=q[j];
			}
			else
				tmp[0]=1;
			for(j=0;j<=m*i;j++)
				r[j]+=p[i]*tmp[j];
		}
		printf("%d",r[0]);
		for(i=1;i<=m*n;i++)
			printf(" %d",r[i]);
		printf("\n");
	}
	return 0;
}