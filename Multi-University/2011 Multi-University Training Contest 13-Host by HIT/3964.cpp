#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int map[20][20],N,mark[20],visited[20],total;
char result[1000000][20];
int cmp(const void *a,const void *b)
{
	return strcmp((char*)a,(char*)b);
}
void dfs(int b,int k,int x)
{
	int i,j,l;
	mark[x++]=k;
	visited[k]=1;
	for(i=b;i<N;i++)
	{
		if(i==k)continue;
		if(!map[k][i])continue;
		if(visited[i])
		{
			if(i!=b)continue;
			for(j=0;j<x;j++)
			{
				if(mark[j]==i)break;
			}
			for(l=j;l<x;l++)
			{
				result[total][l-j]=mark[l]+'0';
			}
			result[total][l]=0;
			total++;
			continue;
		}
		dfs(b,i,x);
	}
	visited[k]=0;
	x--;
}

int main()
{
	int i,j;
	while(scanf("%d",&N)!=EOF)
	{
		for(i=0;i<N;i++)
		{
			for(j=0;j<N;j++)
			{
				scanf("%d",&map[i][j]);
			}
		}
		total=0;
		memset(result,0,sizeof(result));
		for(i=0;i<N;i++)
		{
			memset(mark,0,sizeof(mark));
			memset(visited,0,sizeof(visited));
			dfs(i,i,0);
		}
		qsort(result,total,sizeof(result[0]),cmp);
		for(i=0;i<total;i++)
		{
			printf("%s\n",result[i]);
		}
		printf("\n");
	}
	return 0;
}