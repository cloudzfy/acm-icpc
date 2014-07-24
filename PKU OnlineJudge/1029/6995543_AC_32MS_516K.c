#include <stdio.h>
int main()
{
	char op[100][2];
	int i,j,l,n,k,a,b,coin[1000],x[100],judge[100][500][2],c[1000],d=0,e;
	scanf("%d %d",&n,&k);
	for(i=0;i<n;i++)
	{
		coin[i]=1;
	}
	for(i=0;i<k;i++)
	{
		scanf("%d",&x[i]);
		for(j=0;j<x[i];j++)
		{
			scanf("%d",&judge[i][j][0]);
		}
		for(j=0;j<x[i];j++)
		{
			scanf("%d",&judge[i][j][1]);
		}
		scanf("%s",op[i]);
	}
	for(i=0;i<n;i++)
	{
		d=0;
		coin[i]=0;
		for(j=0;j<k;j++)
		{
			a=0;
			b=0;
			for(l=0;l<x[j];l++)
			{
				a+=coin[judge[j][l][0]-1];
				b+=coin[judge[j][l][1]-1];
			}
			if(op[j][0]=='>'&&a>b) d=1;
			else if(op[j][0]=='='&&a==b) d=1;
			else if(op[j][0]=='<'&&a<b) d=1;
			else
			{
				d=0;
				break;
			}
		}
		if(d==0)
		{
			coin[i]=2;
			for(j=0;j<k;j++)
			{
				a=0;
				b=0;
				for(l=0;l<x[j];l++)
				{
					a+=coin[judge[j][l][0]-1];
					b+=coin[judge[j][l][1]-1];
				}
				if(op[j][0]=='>'&&a>b) d=1;
				else if(op[j][0]=='='&&a==b) d=1;
				else if(op[j][0]=='<'&&a<b) d=1;
				else
				{
					d=0;
					break;
				}
			}
		}
		c[i]=d;
		coin[i]=1;
	}
	d=0;
	for(i=0;i<n;i++)
	{
		if(c[i]==1)
		{
			e=i+1;
			d++;
		}
	}
	if(d==1) printf("%d\n",e);
	else printf("0\n");
	return 0;
}