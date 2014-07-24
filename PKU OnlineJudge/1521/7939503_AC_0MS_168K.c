#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int cmp(const void *a,const void *b)
{
	return (*(int *)b)-(*(int *)a);
}

int main()
{
	int tmp,num[129],i,total,x,y,add[129],sum,con,length;
	char str[10000];
	while(scanf("%s",str)!=EOF)
	{
		if(strcmp(str,"END")==0) break;
		memset(num,0,sizeof(num));
		memset(add,0,sizeof(add));
		for(i=0;str[i]!=0;i++)
			num[str[i]]++;
		length=i;
		qsort(num,129,sizeof(num[0]),cmp);
		for(i=0;i<129;i++)
			if(num[i]==0) break;
		total=i;
		if(total==1)
		{
			printf("%d %d 8.0\n",length*8,length);
			continue;
		}
		sum=total;
		con=sum;
		tmp=1000000;
		for(i=0;i<total;i++)
		{
			if(num[i]<tmp&&add[i]==0)
			{
				tmp=num[i];
				x=i;
			}
		}
		tmp=1000000;
		for(i=0;i<total;i++)
		{
			if(num[i]<tmp&&x!=i&&add[i]==0)
			{
				tmp=num[i];
				y=i;
			}
		}
		add[x]=total;
		add[y]=total;
		num[total]=num[x]+num[y];
		total++;
		sum--;
		while(sum!=1)
		{
			tmp=1000000;
			for(i=0;i<total;i++)
			{
				if(num[i]<tmp&&add[i]==0)
				{
					tmp=num[i];
					x=i;
				}
			}
			tmp=1000000;
			for(i=0;i<total;i++)
			{
				if(num[i]<tmp&&x!=i&&add[i]==0)
				{
					tmp=num[i];
					y=i;
				}
			}
			add[x]=total;
			add[y]=total;
			num[total]=num[x]+num[y];
			total++;
			sum--;
		}
		sum=0;
		for(i=0;i<con;i++)
		{
			x=i;
			y=0;
			while(add[x]!=0)
			{
				x=add[x];
				y++;
			}
			sum+=y*num[i];
		}
		printf("%d %d %.1f\n",length*8,sum,(double)length/sum*8);
	}
	return 0;
}