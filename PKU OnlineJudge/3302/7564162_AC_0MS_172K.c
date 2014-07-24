#include <stdio.h>
#include <string.h>
int main()
{
	int i,j,b,t;
	char s1[101],s2[101];
	scanf("%d",&t);
	while(t--)
	{
		scanf("%s %s",s1,s2);
		j=0;
		b=0;
		for(i=0;s1[i]!=0;i++)
		{
			if(s1[i]==s2[j])
				j++;
			if(s2[j]==0)
			{
				b=1;
				break;
			}
		}
		j=0;
		for(i=strlen(s1)-1;i>=0;i--)
		{
			if(s1[i]==s2[j])
				j++;
			if(s2[j]==0)
			{
				b=1;
				break;
			}
		}
		if(b==0)
			printf("NO\n");
		else
			printf("YES\n");
	}
	return 0;
}
