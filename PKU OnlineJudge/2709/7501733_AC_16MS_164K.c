#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int cmp(const void *a,const void *b)
{
	if(*(int *)a>*(int *)b) return -1;
	else if(*(int *)a==*(int *)b) return 0;
	else return 1;
}

int main()
{
	int i,N,c[12],G,num,x;
	for(;;)
	{
		scanf("%d",&N);
		if(N==0) break;
		memset(c,0,12);
		for(i=0;i<N;i++)
			scanf("%d",&c[i]);
		scanf("%d",&G);
		qsort(c,N,sizeof(c[0]),cmp);
		x=c[0];
		num=0;
		while(x>0)
		{
			x-=50;
			num++;
		}
		for(i=0;i<N;i++)
			c[i]=50*num-c[i];
		while(G>0)
		{
			qsort(c,N,sizeof(c[0]),cmp);
			if(c[2]<=0)
			{
				num++;
				for(i=0;i<N;i++)
					c[i]+=50;
			}
			c[0]--;
			c[1]--;
			c[2]--;
			G--;
		}
		printf("%d\n",num);
	}
	return 0;
}