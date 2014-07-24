#include <stdio.h>
#include <string.h>
#define MAX 31
int a[40][40],b[40],c[40];
int main()
{
	int T,N,i,j,y,x,flag,tmp,k;
	scanf("%d",&T);
	while(T--)
	{
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		scanf("%d",&N);
		for(i=0;i<N;i++)
		{
			scanf("%d",&x);
			memset(c,0,sizeof(c));
			j=0;
			tmp=x;
			while(tmp)
			{
				if(tmp&1)c[j]++;
				tmp>>=1;
				j++;
			}
			for(j=MAX;j>=0;j--)b[j]=(b[j]+c[j])%3;
			for(j=MAX;j>=0;j--)
			{
				if(c[j])
				{
					for(k=MAX;k>=0;k--)
					{
						a[j][k]=(a[j][k]+c[k])%3;
					}
				}
			}
		}
		x=0;
		y=0;
		flag=1;
		for(i=MAX;i>=0;i--)
		{
			if(b[i]==1)
			{
				flag=0;
				tmp=0;
				for(j=MAX;j>=0;j--)
				{
					if(a[i][j]>0)tmp^=(1<<j);
				}
				if(x==0)
				{
					x=tmp;
					break;
				}
			}
		}
		if(flag==1)
		{
			for(i=MAX;i>=0;i--)
			{
				if(b[i]==2) x^=(1<<i);
			}
			printf("%d %d\n",x,x);
		}
		else
		{
			tmp=0;
			for(i=MAX;i>=0;i--)
			{
				if(b[i]==1)tmp+=(1<<i);
				else if(b[i]==2)tmp+=(1<<(i+1));
			}
			y=tmp-x;
			if(x>y)
			{
				tmp=x;
				x=y;
				y=tmp;
			}
			printf("%d %d\n",x,y);
		}
	}
	return 0;
}