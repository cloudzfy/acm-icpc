#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char str[20000][51];
int cmp(const void *a,const void *b)
{
	return strcmp((char*)a,(char*)b);
}
int main()
{
	int n,result,i,j;
	while(scanf("%d",&n)==1)
	{
		result=0;
		for(i=0;i<n;i++)
		{
			scanf("%s",str[i]);
		}
		qsort(str,n,sizeof(str[0]),cmp);
		for(i=0;i<n-1;i++)
		{
			for(j=0;str[i][j]!=0&&str[i+1][j]!=0;j++)
			{
				if(str[i][j]!=str[i+1][j])
				{
					break;
				}
			}
			if(result<j) result=j;
		}
		printf("%d\n",result);
	}
	return 0;
}