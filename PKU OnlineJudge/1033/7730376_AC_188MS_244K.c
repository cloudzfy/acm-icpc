#include <stdio.h>
#include <string.h>
int main()
{
	int index,b=0,i,s,tmp,position[10001],disk[10001],n,k,x=1;
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
	if(b==1)
	{
		for(i=1;i<=n;i++)
		{
			if(disk[i]!=i&&disk[i]!=0)
			{
				if(disk[disk[i]]==0)
				{
					printf("%d %d\n",i,disk[i]);
					disk[disk[i]]=disk[i];
					disk[i]=0;
					index=i;
					while(position[index]!=0)
					{
						printf("%d %d\n",position[index],index);
						disk[position[index]]=0;
						disk[index]=index;
						index=position[index];
					}
				}
			}
		}
		for(i=1;i<=n;i++)
		{
			if(disk[i]!=i&&disk[i]!=0)
			{
				index=i;
				for(tmp=n;tmp>=0;tmp--)
				{
					if(disk[tmp]==0) break;
				}
				printf("%d %d\n",index,tmp);
				disk[tmp]=disk[i];
				disk[i]=0;
				while(disk[tmp]!=index)
				{
					printf("%d %d\n",position[index],index);
					disk[index]=disk[position[index]];
					disk[position[index]]=0;
					index=position[index];
				}
				printf("%d %d\n",tmp,index);
				disk[index]=disk[tmp];
				disk[tmp]=0;
			}
		}
	}
	return 0;
}