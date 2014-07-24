#include <stdio.h>
#include <math.h>
#include <string.h>
int minv[21],mins[21];
int n,m,min,s=100000,result=0;
int MIN(int a,int b)
{
	if(a<b) return a;
	else return b;
}
void dfs(int v1,int m1,int r,int h)
{
	int tmp,maxr,maxh,i,j,k;
	if(m1==0)
	{
		if(v1==0)
		{
			result=1;
			if(min<s) s=min;
		}
		return;
	}
	if(minv[m1]>v1) return;
	maxr=MIN((int)sqrt((v1-minv[m1-1])*1.0/m1),r);
	for(i=maxr;i>=m1;i--)
	{
		maxh=MIN((v1-minv[m1-1])/(i*i),h);
		for(j=maxh;j>=m1;j--)
		{
			tmp=0;
			for(k=0;k<m1;k++)
				tmp+=(i-k)*(i-k)*(j-k);
			if(v1>tmp) break;
			tmp=v1-i*i*j;
			if(m1==m)
			{
				if(i*i<s)
					min=i*i;
				else
				{
					tmp=v1;
					continue;
				}
			}
			min+=2*i*j;
			if(min>s)
			{
				tmp=v1;
				min-=2*i*j;
				continue;
			}
			dfs(tmp,m1-1,i-1,j-1);
			min-=2*i*j;
		}
	}
}
int main()
{
	int i;
	scanf("%d%d",&n,&m);
	minv[0]=0;
	mins[0]=0;
	for(i=1;i<=m;i++)
	{
		minv[i]=minv[i-1]+i*i*i;
		mins[i]=mins[i-1]+2*i*i;
	}
	dfs(n,m,1000,1000);
	if(result==0) s=0;
	printf("%d\n",s);
	return 0;
}