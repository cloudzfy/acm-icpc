#include <stdio.h>
#include <string.h>
int main()
{
	int b=0,i,j,s,tmp,position[10001],disk[10001],n,k,x=1;
	memset(position,0,sizeof(position));
	memset(disk,0,sizeof(disk));
	scanf("%d%d",&n,&k);
	while(k--)
	{
		scanf("%d",&s);
		while(s--)
		{
			scanf("%d",&tmp);
			position[x]=tmp;
			disk[tmp]=x;
			x++;
		}
	}
	for(i=1;i<=n;i++)
	{
		if(position[i]!=i&&position[i]!=0) b=1;
	}
	if(b==0) printf("No optimization needed\n");
	while(b==1)
	{
		x=1;
		while(x==1)
		{
			x=0;
			for(i=1;i<=n;i++)
			{
				if(position[i]==i)
				{
					position[i]=0;
					x=1;
					continue;
				}
				if(position[i]!=0&&disk[i]==0)
				{
					printf("%d %d\n",position[i],i);
					disk[i]=i;
					disk[position[i]]=0;
					position[i]=0;
					x=1;
				}
			}
		}
		for(i=1;i<=n;i++)
		{
			if(position[i]!=0&&disk[i]!=0)
			{
				for(j=n;j>0;j--)
				{
					if(disk[j]==0) break;
				}
				printf("%d %d\n",i,j);
				disk[j]=disk[i];
				disk[i]=0;
				position[disk[j]]=j;
				break;
			}
		}
		b=0;
		for(i=1;i<=n;i++)
		{
			if(position[i]!=0) b=1;
		}
	}
	return 0;
}