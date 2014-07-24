#include <stdio.h>
#include <string.h>
int n,c[32001],level[32001];
void add(int i,int value)
{
	while(i<=32001)
	{
		c[i]+=value;
		i+=(i&(-i));
	}
}
int sum(int i)
{
	int s=0;
	while(i>0)
	{
		s+=c[i];
		i-=(i&(-i));
	}
	return s;
}
int main()
{
	int i,x,y;
	scanf("%d",&n);
	memset(level,0,sizeof(level));
	memset(c,0,sizeof(c));
	for(i=0;i<n;i++)
	{
		scanf("%d%d",&x,&y);
		level[sum(x+1)]++;
		add(x+1,1);
	}
	for(i=0;i<n;i++)
	{
		printf("%d\n",level[i]);
	}
	return 0;
}
