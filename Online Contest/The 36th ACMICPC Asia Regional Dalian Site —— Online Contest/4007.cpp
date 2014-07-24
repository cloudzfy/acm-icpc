#include <stdio.h>
#include <stdlib.h>
struct Point
{
	int x,y;
}point[1000],tmp[1000];
int cmp(const void *a,const void *b)
{
	if(((struct Point*)a)->x==((struct Point*)b)->x)
		return ((struct Point*)a)->y-((struct Point*)b)->y;
	return ((struct Point*)a)->x-((struct Point*)b)->x;
}
int cmpy(const void *a,const void *b)
{
	return ((struct Point*)a)->y-((struct Point*)b)->y;
}
int main()
{
	int i,j,k,l,N,R,ans,num,sum;
	while(scanf("%d%d",&N,&R)!=EOF)
	{
		for(i=0;i<N;i++)
		{
			scanf("%d%d",&point[i].x,&point[i].y);
		}
		ans=0;
		qsort(point,N,sizeof(point[0]),cmp);
		for(i=0;i<N;i++)
		{
			if(i>0&&point[i].x==point[i-1].x)continue;
			num=0;
			for(j=i;j<N;j++)
			{
				if(point[j].x-point[i].x<=R)
					tmp[num++]=point[j];
				else break;
			}
			qsort(tmp,num,sizeof(tmp[0]),cmpy);
			for(k=0;k<num;k++)
			{
				if(k>0&&tmp[k].y==tmp[k-1].y)continue;
				sum=0;
				for(l=k;l<num;l++)
				{
					if(tmp[l].y-tmp[k].y<=R)
						sum++;
					else break;
				}
				if(ans<sum)ans=sum;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}