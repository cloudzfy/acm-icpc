#include <stdio.h>
#include <algorithm>
#include <stack>
using namespace std;
char str[1000010];
int main()
{
	stack<int> s;
	int T,flag,i,now,tmp,num;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%s",str);
		flag=1;
		num=0;
		for(i=0;str[i]!=0;i++)
		{
			if(str[i]=='('||str[i]==')'||str[i]==',')
			{
				flag=1;
			}
			else
			{
				if(flag)num++;
				flag=0;
			}
		}
		printf("%d\n",num);
		flag=1;
		for(i=0;str[i]!=0;i++)
		{
			if(str[i]=='('||str[i]==')'||str[i]==',')
			{
				if(!flag)printf("\n");
				flag=1;
			}
			else
			{
				printf("%c",str[i]);
				flag=0;
			}
		}
		if(!flag)printf("\n");
		now=1;
		s.push(now);
		for(i=0;str[i]!=0;i++)
		{
			if(str[i]=='(')
			{
				printf("%d %d\n",(int)s.top(),++now);
				s.push(now);
			}
			else if(str[i]==',')
			{
				tmp=s.top();
				s.pop();
				printf("%d %d\n",tmp,(int)s.top());
				printf("%d %d\n",(int)s.top(),++now);
				s.push(now);
			}
			else if(str[i]==')')
			{
				tmp=s.top();
				s.pop();
				printf("%d %d\n",tmp,(int)s.top());
			}
		}
		printf("\n");
	}
	return 0;
}