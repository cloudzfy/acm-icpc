#include <stdio.h>
#include <string.h>
char str[100001],match[100001];
int next[100001];
void setNext(int start,int end)
{
	int i=start,j=start-1;
	next[i]=start-1;
	while(i<=end)
	{
		if(j==start-1||match[i]==match[j])
		{
			i++;
			j++;
			next[i]=j;
		}
		else j=next[j];
	}
}
void init()
{
	int start,end,i=0,j=0,k;
	if(match[0]!='*')
	{
		for(i=0;str[i]!=0&&match[i]!=0;i++)
		{
			if(match[i]=='*')break;
			if(match[i]=='?')continue;
			if(match[i]!=str[i])
			{
				printf("NO\n");
				return;
			}
		}
		if(match[i]!='*')
		{
			if(match[i]==0&&str[i]==0)
			{
				printf("YES\n");
			}
			else
			{
				printf("NO\n");
			}
			return;
		}
	}
	j=i+1;
	while(1)
	{
		while(match[j]=='*')j++;
		start=j;
		for(;match[j]!=0;j++)
		{
			if(match[j]=='*')break;
		}
		end=j-1;
		if(start>end) break;
		if(match[j]==0)
		{
			for(j--,k=(int)strlen(str)-1;k>=0&&j>=0&&match[j]!='*';k--,j--)
			{
				if(match[j]=='?')continue;
				if(match[j]!=str[k])
				{
					printf("NO\n");
					return;
				}
			}
			if((match[j]=='*'||j==-1)&&k+1>=i) printf("YES\n");
			else printf("NO\n");
			return;
		}
		setNext(start,end);
		for(j=start;str[i]!=0&&j<=end;i++,j++)
		{
			if(match[j]=='?')continue;
			if(j!=start-1&&str[i]!=match[j])
			{
				j=next[j]-1;
				i--;
			}
		}
		if(j<=end)
		{
			printf("NO\n");
			return;
		}
	}
	printf("YES\n");
}



int main()
{
	while(scanf("%s%s",str,match)!=EOF)
	{
		init();
	}
}