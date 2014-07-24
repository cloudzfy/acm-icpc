#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int data[500000][4],c[500001],n;
int cmpx(const void *a,const void *b)
{
	return ((int*)b)[0]-((int*)a)[0];
}
int cmpy(const void *a,const void *b)
{
	return ((int*)a)[1]-((int*)b)[1];
}
void add(int i,int value)
{
	while(i>0)
	{
		if(c[i]<value) c[i]=value;
		i-=(i&(-i));
	}
}
int getMax(int i)
{
	int s=0;
	while(i<=n)
	{
		if(s<c[i]) s=c[i];
		i+=(i&(-i));
	}
	return s;
}
int main()
{
	int i,pre,result,j,mark;
	memset(data,0,sizeof(data));
	scanf("%d",&n);
	for(i=0;i<n;i++) scanf("%d",&data[i][0]);
	for(i=0;i<n;i++) scanf("%d",&data[i][1]);
	for(i=0;i<n;i++) scanf("%d",&data[i][2]);
	qsort(data,n,sizeof(data[0]),cmpy);
	pre=data[0][1];
	data[0][1]=1;
	for(i=1;i<n;i++)
	{
		if(data[i][1]>pre)
		{
			pre=data[i][1];
			data[i][1]=data[i-1][1]+1;
		}
		else data[i][1]=data[i-1][1];
	}
	qsort(data,n,sizeof(data[0]),cmpx);
	result=0;
	for(i=0;i<n;i++)
	{
		mark=n;
		for(j=i+1;j<n;j++)
		{
			if(data[j][0]!=data[i][0])
			{
				mark=j;
				break;
			}
		}
		for(j=i;j<mark;j++)
		{
			if(getMax(data[j][1]+1)>data[j][2]) result++;
			else data[j][3]=1;
		}
		for(j=i;j<mark;j++)
		{
			if(data[j][3]) add(data[j][1],data[j][2]);
		}
		i=mark-1;
	}
	printf("%d\n",result);
	return 0;
}