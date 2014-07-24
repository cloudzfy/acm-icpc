#include <stdio.h>
#include <string.h>
int map[100][100],tmp[100][100];
int main()
{
	int t,T,N,i,j,k,flag,count;
	scanf("%d",&T);
	for(t=1;t<=T;t++)
	{
		scanf("%d",&N);
		for(i=0;i<N;i++)
		{
			for(j=0;j<N;j++)
			{
				scanf("%d",&map[i][j]);
			}
		}
		memset(tmp,0,sizeof(tmp));
		flag=1;
		for(i=0;i<N&&flag;i++)
		{
			for(j=0;j<N&&flag;j++)
			{
				if(i==j)continue;
				if(!map[i][j])continue;
				for(k=0;k<N;k++)
				{
					if(i==k||j==k)continue;
					if(!map[i][k]||!map[k][j])continue;
					if(map[i][k]+map[k][j]<map[i][j])
					{
						flag=0;
						break;
					}
					else if(map[i][k]+map[k][j]==map[i][j])tmp[i][j]=1;
				}
			}
		}
		count=0;
		for(i=0;i<N&&flag;i++)
		{
			for(j=0;j<N;j++)
			{
				if(map[i][j]&&!tmp[i][j])count++;
			}
		}
		printf("Case %d: ",t);
		if(!flag)printf("impossible\n");
		else printf("%d\n",count);
	}
	return 0;
}