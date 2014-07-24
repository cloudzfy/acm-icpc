#include <stdio.h>
int main()
{
	int i,j;
	char str1[1001],str2[1001];
	while(gets(str1))
	{
		j=0;
		for(i=0;str1[i]!=0;i++)
		{
			if(str1[i]=='y'&&str1[i+1]=='o'&&str1[i+2]=='u')
			{
				str2[j]='w';
				str2[j+1]='e';
				j+=2;
				i+=2;
			}
			else
			{
				str2[j]=str1[i];
				j++;
			}
		}
		str2[j]=0;
		printf("%s\n",str2);
	}
	return 0;
}