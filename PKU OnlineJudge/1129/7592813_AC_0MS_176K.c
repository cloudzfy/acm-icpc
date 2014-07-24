#include <stdio.h>
#include <string.h>
int al[26][26],b[26],n,Bool;
int dfs(int data,int num)
{
	int i,j;
	if(data>=n) return 1;
	for(i=1;i<=num;i++)
	{
		Bool=1;
		b[data]=i;
		for(j=0;j<n;j++)
		{
			if(al[data][j]==1&&b[data]==b[j]) Bool=0;
		}
		if(Bool==1&&dfs(data+1,num)==1) return 1;
		b[data]=0;
	}
	return 0;
}

int main()
{
	char data[28];
	int i,j;
	for(;;)
	{
		scanf("%d",&n);
		if(n==0) break;
		memset(al,0,sizeof(al));
		for(j=0;j<n;j++)
		{
			scanf("%s",data);
			for(i=2;data[i]!=0;i++)
				al[data[0]-'A'][data[i]-'A']=al[data[i]-'A'][data[0]-'A']=1;
		}
		for(i=1;i<4;i++)
		{
			memset(b,0,sizeof(b));
			if(dfs(0,i)==1) break;
		}
		if(i==1) printf("1 channel needed.\n");
		else printf("%d channels needed.\n",i);
	}
	return 0;
}