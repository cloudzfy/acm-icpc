#include <stdio.h>
#include <string.h>
int map[100][100],data[100][100][11][3];
int main()
{
	char step[101],str[101];
	int n,m,k,i,j,l,tmp,result,x,mark,rest,rest2,mark2;
	scanf("%d%d%d",&n,&m,&k);
	memset(data,-1,sizeof(data));
	for(i=0;i<n;i++)
	{
		scanf("%s",str);
		for(j=m-1;j>=0;j--)
		{
			map[i][j]=str[j]-'0';
		}
	}
	for(j=0;j<m;j++)
	{
		data[n-1][j][map[n-1][j]%(k+1)][0]=map[n-1][j];
	}
	for(i=n-2;i>=0;i--)
	{
		for(j=0;j<m;j++)
		{
			for(l=0;l<k+1;l++)
			{
				if(j>0&&data[i+1][j-1][l][0]!=-1)
				{
					tmp=(map[i][j]+data[i+1][j-1][l][0])%(k+1);
					if(data[i][j][tmp][0]<map[i][j]+data[i+1][j-1][l][0])
					{
						data[i][j][tmp][0]=map[i][j]+data[i+1][j-1][l][0];
						data[i][j][tmp][1]=j-1;
						data[i][j][tmp][2]=l;
					}
				}
				if(j<m-1&&data[i+1][j+1][l][0]!=-1)
				{
					tmp=(map[i][j]+data[i+1][j+1][l][0])%(k+1);
					if(data[i][j][tmp][0]<map[i][j]+data[i+1][j+1][l][0])
					{
						data[i][j][tmp][0]=map[i][j]+data[i+1][j+1][l][0];
						data[i][j][tmp][1]=j+1;
						data[i][j][tmp][2]=l;
					}
				}
			}
		}
	}
	result=-1;
	mark=-1;
	for(j=0;j<m;j++)
	{
		if(data[0][j][0][0]>result)
		{
			result=data[0][j][0][0];
			mark=j;
		}
	}
	if(result!=-1)
	{
		rest=0;
		x=n-1;
		step[x]=0;
		for(i=0;i<n-1;i++)
		{
			if(data[i][mark][rest][1]-mark==-1)
			{
				step[--x]='R';
			}
			else
			{
				step[--x]='L';
			}
			mark2=mark;
			rest2=rest;
			mark=data[i][mark2][rest2][1];
			rest=data[i][mark2][rest2][2];
		}
	}
	printf("%d\n",result);
	if(result!=-1)
	{
		printf("%d\n",mark+1);
		printf("%s\n",step);
	}
	return 0;
}