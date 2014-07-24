#include <stdio.h>
#include <string.h>
long long max[50][4];
int x[250000];
int data[5000];
int main()
{
	int n,m,l,i,j;
	long long sum,result=-10000,total;
	memset(max,-10000,sizeof(max));
	scanf("%d%d",&n,&m);
	for(i=0;i<n;i++)
	{
		scanf("%d",&l);
		for(j=0;j<l;j++)
		{
			scanf("%d",&data[j]);
		}
		sum=0;
		for(j=0;j<l;j++)
		{
			sum+=data[j];
			if(sum>max[i][3]) max[i][3]=sum;
			if(sum<0) sum=0;
		}
		sum=0;
		total=0;
		for(j=0;j<l;j++)
		{
			total+=data[j];
			sum+=data[j];
			if(sum>max[i][0]) max[i][0]=sum;
		}
		max[i][2]=total;
		sum=0;
		for(j=l-1;j>=0;j--)
		{
			sum+=data[j];
			if(sum>max[i][1]) max[i][1]=sum;
		}
	}
	for(i=0;i<m;i++)
	{
		scanf("%d",&x[i]);
		x[i]--;
	}
	sum=max[x[0]][1];
	if(max[x[0]][3]>result) result=max[x[0]][3];
	for(i=1;i<m;i++)
	{
		if(sum+max[x[i]][0]>result)
		{
			result=sum+max[x[i]][0];
		}
		if(sum>result)
		{
			result=sum;
		}
		sum+=max[x[i]][2];
		if(max[x[i]][3]>result) result=max[x[i]][3];
		if(sum<0||sum<max[x[i]][1])//×¢ÒâÕâµã
		{
			sum=max[x[i]][1];
		}
	}
	printf("%I64d\n",result);
	return 0;
}