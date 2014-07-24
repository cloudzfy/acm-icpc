#include <stdio.h>
#include <stdlib.h>
struct stick
{
	int l;
	int w;
}s[5000];
int cmp(const void * a, const void * b)
{
	if((*(struct stick *)a).l==(*(struct stick *)b).l)
        return (*(struct stick *)a).w -(*(struct stick *)b).w;
    return (*(struct stick *)a).l - (*(struct stick *)b).l;
}
int main()
{
	int i,j,t,n,tmp,sum;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(i=0;i<n;i++)
		{
			scanf("%d %d",&s[i].l,&s[i].w);
		}
		qsort(s,n,sizeof(s[0]),cmp);
		sum=0;
		for(i=0;i<n;i++)
		{
			if(s[i].w!=-1)
			{
				sum++;
				tmp=s[i].w;
				for(j=i+1;j<n;j++)
				{
					if(tmp<=s[j].w)
					{
						tmp=s[j].w;
						s[j].w=-1;
					}
				}
			}
		}
		printf("%d\n",sum);
	}
	return 0;
}