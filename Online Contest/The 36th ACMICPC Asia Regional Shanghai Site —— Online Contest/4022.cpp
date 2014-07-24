#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
using namespace std;
int point[100000][2],bomberx[100000][2],bombery[100000][2],bx[100000],by[100000],total[100000];
int cmp(const void *a,const void *b)
{
	if(((int*)a)[0]==((int*)b)[0])
		return ((int*)a)[1]-((int*)b)[1];
	return ((int*)a)[0]-((int*)b)[0];
}
int main()
{
	int N,M,i,j,k,x,y,c,d;
	while(scanf("%d%d",&N,&M)!=EOF)
	{
		if(N==0&&M==0)break;
		memset(total,0,sizeof(total));
		for(i=0;i<N;i++)
		{
			scanf("%d%d",&point[i][0],&point[i][1]);
		}
		x=0;
		y=0;
		for(i=0;i<M;i++)
		{
			scanf("%d%d",&c,&d);
			if(c==0)
			{
				bomberx[x][0]=d;
				bomberx[x++][1]=i;
			}
			else
			{
				bombery[y][0]=d;
				bombery[y++][1]=i;
			}
		}
		qsort(bomberx,x,sizeof(bomberx[0]),cmp);
		qsort(bombery,y,sizeof(bombery[0]),cmp);
		for(i=0;i<x;i++)bx[i]=bomberx[i][0];
		for(i=0;i<y;i++)by[i]=bombery[i][0];
		for(i=0;i<N;i++)
		{
			j=lower_bound(bx,bx+x,point[i][0])-bx;
			k=lower_bound(by,by+y,point[i][1])-by;
			if(bomberx[j][0]==point[i][0]&&bombery[k][0]==point[i][1])
			{
				if(bomberx[j][1]<bombery[k][1]) total[bomberx[j][1]]++;
				else total[bombery[k][1]]++;
			}
			else if(bomberx[j][0]==point[i][0]) total[bomberx[j][1]]++;
			else if(bombery[k][0]==point[i][1]) total[bombery[k][1]]++;
		}
		for(i=0;i<M;i++)
			printf("%d\n",total[i]);
		printf("\n");
	}
	return 0;
}