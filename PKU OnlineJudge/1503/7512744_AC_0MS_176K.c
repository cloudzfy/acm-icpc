#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
int main()
{
	int i,j;
	char num[103],total[103];
	for(j=102;j>=0;j--)
		total[j]=0;
	while(scanf("%s",num)!=EOF)
	{
		if(strcmp("0",num)==0) break;
		j=102;
		for(i=strlen(num)-1;i>=0;i--)
		{
			num[j]=num[i]-'0';
			j--;
		}
		for(;j>=0;j--)
			num[j]=0;
		for(j=102;j>=0;j--)
			total[j]+=num[j];
		for(j=102;j>0;j--)
		{
			total[j-1]+=floor((double)(total[j]/10));
			total[j]=total[j]%10;
		}
	}
	for(i=0;i<103;i++)
	{
		if(total[i]!=0) break;
	}
	if(i==103&&total[102]==0)
		strcpy(total,"0");
	else
	{
		for(j=0;i<103;j++)
    	{
			total[j]=total[i]+'0';
			i++;
		}
		total[j]=0;
	}
	printf("%s\n",total);
	return 0;
}