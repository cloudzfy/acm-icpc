#include <stdio.h>
#include <string.h>
int main()
{
	struct string
	{
		char string[50];
		int measure;
	};
	struct string str[100];
	struct string tmp;
	int n,m,i,j,k;
	scanf("%d %d",&n,&m);
	for(i=0;i<m;i++)
	{
		scanf("%s",str[i].string);
		str[i].measure=0;
		for(j=0;j<n;j++)
		{
			for(k=j+1;k<n;k++)
			{
				if(str[i].string[j]>str[i].string[k])
				{
					str[i].measure++;
				}
			}
		}
	}
	for(i=0;i<m;i++)
	{
		for(j=i+1;j<m;j++)
		{
			if(str[i].measure>str[j].measure)
			{
				strcpy(tmp.string,str[i].string);
				strcpy(str[i].string,str[j].string);
				strcpy(str[j].string,tmp.string);
				tmp.measure=str[i].measure;
				str[i].measure=str[j].measure;
				str[j].measure=tmp.measure;
			}
		}
	}
	for(i=0;i<m;i++)
	{
		printf("%s\n",str[i].string);
	}
	return 0;
}