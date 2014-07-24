#include <stdio.h>
#include <string.h>
int pow[1000],dmg[1000],queue[1000][2],used[1000];
int main()
{
	int now,fight=0,n,max,reg,i,mark,m,k=0,t=0;
	scanf("%d%d%d",&n,&max,&reg);
	now=max;
	memset(used,0,sizeof(used));
	for(i=0;i<n;i++)
	{
		scanf("%d%d",&pow[i],&dmg[i]);
	}
	while(now>0)
	{
		mark=-1;
		m=0;
		for(i=0;i<n;i++)
		{
			if(pow[i]*max>=now*100&&used[i]==0&&dmg[i]>m)
			{
				mark=i;
				m=dmg[i];
			}
		}
		if(mark!=-1)
		{
			used[mark]=1;
			queue[k][0]=t;
			queue[k][1]=mark+1;
			k++;
			fight+=dmg[mark];
		}
		if(mark==-1&&fight<=reg)
		{
			printf("NO\n");
			return 0;
		}
		now=now-fight+reg;
		if(now>max)now=max;
		t++;
	}
	printf("YES\n");
	printf("%d %d\n",t,k);
	for(i=0;i<k;i++)
	{
		printf("%d %d\n",queue[i][0],queue[i][1]);
	}
	return 0;
}