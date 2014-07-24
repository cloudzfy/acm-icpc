#include <stdio.h>
#include <string.h>
int deadline[10001];
int main()
{
	int n,total,sum,p,d,i,j,tmp;
	while(scanf("%d",&n)!=EOF)
	{
		total=0;
		memset(deadline,0,sizeof(deadline));
		for(i=0;i<n;i++)
		{
			scanf("%d%d",&p,&d);
			if(total<d)total=d;
			if(deadline[d]==0)
			{
				deadline[d]=p;
			}
			else
			{
				for(j=d;j>0;j--)
				{
					if(deadline[j]<p)
					{
						tmp=deadline[j];
						deadline[j]=p;
						p=tmp;
					}
				}
			}
		}
		sum=0;
		for(i=1;i<=total;i++)
		{
			sum+=deadline[i];
		}
		printf("%d\n",sum);
	}
	return 0;
}