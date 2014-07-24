#include <stdio.h>
#include <string.h>
int add[26];
void swap(char *a,char *b)
{
	char tmp;
	tmp=*a;
	*a=*b;
	*b=tmp;
}
int main()
{
	int odd,t,i,j,result,length,mark,pos,count,pastodd;
	char str[110];
	scanf("%d",&t);
	while(t--)
	{
		memset(add,0,sizeof(add));
		odd=0;
		pos=-1;
		scanf("%s",str);
		for(i=0;str[i]!=0;i++)
		{
			add[str[i]-'a']++;
		}
		for(i=0;i<26;i++)
		{
			if(add[i]%2!=0)
			{
				odd++;
				pos=i;
			}
		}
		if(odd>1)
		{
			printf("Impossible\n");
			continue;
		}
		pastodd=0;
		result=0;
		length=(int)strlen(str);
		for(i=0;i<length;i++)
		{
			mark=-1;
			for(j=i+1;j<length-i+pastodd;j++)
			{
				if(str[i]==str[j])
				{
					mark=j;
				}
			}
			if(mark==-1)
			{
				pastodd=1;
				continue;
			}
			for(j=mark;j<length-i-1+pastodd;j++)
			{
				swap(&str[j],&str[j+1]);
				result++;
			}
		}
		if(odd==1)
		{
			count=0;
			for(i=0;i<length;i++)
			{
				if(str[i]==pos+'a')
				{
					count++;
					if(count==add[pos]/2+1)
					{
						for(j=i;j<length/2;j++)
						{
							swap(&str[j],&str[j+1]);
							result++;
						}
						break;
					}
				}
			}
		}
		printf("%d\n",result);
	}
	return 0;
}