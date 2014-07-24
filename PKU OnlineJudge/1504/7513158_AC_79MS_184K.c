#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
int main()
{
	char num1[100],num2[100],total[100];
	int t,i,j;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%s %s",num1,num2);
		i=0;
		if(num1[0]=='0')
		{
			for(;i<100;i++)
				if(num1[i]!='0') break;
		}
		for(j=0;num1[i]!=0;j++)
		{
			num1[j]=num1[i]-'0';
			i++;
		}
		for(;j<100;j++)
			num1[j]=0;
		i=0;
		if(num2[0]=='0')
		{
			for(i=0;i<100;i++)
				if(num2[i]!='0') break;
		}
		for(j=0;num2[i]!=0;j++)
		{
			num2[j]=num2[i]-'0';
			i++;
		}
		for(;j<100;j++)
			num2[j]=0;
		for(i=0;i<100;i++)
			total[i]=0;
		for(i=0;i<99;i++)
		{
			total[i]+=num1[i]+num2[i];
			total[i+1]+=floor((double)(total[i]/10));
			total[i]=total[i]%10;
		}
		if(total[0]==0)
		{
			for(i=0;i<100;i++)
			{
				if(total[i]!=0) break;
			}
			for(j=0;i<100;j++)
			{
				total[j]=total[i];
				i++;
			}
			for(;j<100;j++)
				total[j]=0;
		}
		for(i=99;i>=0;i--)
		{
			if(total[i]!=0) break;
		}
		for(;i>=0;i--)
			total[i]+='0';
		if(total[0]==0) strcpy(total,"0");
		printf("%s\n",total);
	}
	return 0;
}