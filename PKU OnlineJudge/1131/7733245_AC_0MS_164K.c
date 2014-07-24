#include <stdio.h>
#include <string.h>
char x[200],rest[200];
void divide()
{
	int i;
	for(i=0;i<200;i++)
	{
		if(rest[i]>=8)
		{
			rest[i]-=8;
			x[i]+=1;
			i--;
		}
		else
		{
			x[i+1]=(rest[i]*10+rest[i+1])/8;
			rest[i+1]=(rest[i]*10+rest[i+1])%8;
			rest[i]=0;
		}
	}
}			
int main()
{
	int i,j;
	char num[200];
	while(scanf("%s",num)!=EOF)
	{
		printf("%s [8] = ",num);
		memset(x,0,200);
		memset(rest,0,200);
		for(i=0;num[i]!=0;i++){}
		rest[0]=num[i-1]-'0';
		divide();
		for(j=0;j<200;j++)
			rest[j]=x[j];
		for(i=i-2;i>1;i--)
		{
			rest[0]=num[i]-'0';
			divide();
			for(j=0;j<200;j++)
				rest[j]=x[j];
		}
		for(i=199;i>=0;i--)
		{
			if(rest[i]!=0) break;
		}
		for(;i>0;i--)
		{
			rest[i+1]=rest[i]+'0';
		}
		rest[1]='.';
		rest[0]='0';
		printf("%s [10]\n",rest);
	}
	return 0;
}