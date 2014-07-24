#include <stdio.h>
char str[1000000];
int main()
{
	int t,T,i,flag,start;
	scanf("%d",&T);
	for(t=1;t<=T;t++)
	{
		flag=0;
		scanf("%s",str);
		for(i=0;str[i]!=0;i++)
		{
			if(!flag&&(str[i]==':'&&str[i+1]=='/'&&str[i+2]=='/'))
			{
				flag=1;
				start=i+3;
				i+=3;
			}
			if(flag&&(str[i]==':'||str[i]=='/'))
			{
				str[i]=0;
				break;
			}
		}
		printf("Case #%d: %s\n",t,str+start);
	}
	return 0;
}
