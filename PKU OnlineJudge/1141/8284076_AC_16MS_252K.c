#include <stdio.h>
#include <string.h>
int a[101][101],b[101][101];
char str[101];
void print(int i,int j)
{
	if(b[i][j]!=-1)
	{
		print(i,b[i][j]);
		print(b[i][j]+1,j);
	}
	else if(i==j)
	{
		if(str[i]=='('||str[i]==')')
			printf("()");
		if(str[i]=='['||str[i]==']')
			printf("[]");
	}
	else if((str[i]=='('&&str[j]==')')||(str[i]=='['&&str[j]==']'))
	{
		printf("%c",str[i]);
		if(j-i>=2)print(i+1,j-1);
		printf("%c",str[j]);
	}
}
int main()
{
	int i,j,k,l;
	while(gets(str))
	{
		if(str[0]==0)
		{
			printf("\n");
			continue;
		}
		memset(a,100000,sizeof(a));
		memset(b,-1,sizeof(b));
		for(i=0;i<strlen(str);i++)
			a[i][i]=1;
		for(i=0;i<strlen(str)-1;i++)
		{
			if((str[i]=='('&&str[i+1]==')')||(str[i]=='['&&str[i+1]==']'))
			{
				a[i][i+1]=0;
				b[i][i+1]=-1;
			}
			else
			{
				a[i][i+1]=2;
				b[i][i+1]=i;
			}
		}
		for(k=2;k<strlen(str);k++)
		{
			for(i=0;i+k<strlen(str);i++)
			{
				j=i+k;
				if((str[i]=='('&&str[j]==')')||(str[i]=='['&&str[j]==']'))
				{
					a[i][j]=a[i+1][j-1];
					b[i][j]=-1;
				}
				else
				{
					a[i][j]=a[i][i]+a[i+1][j];
					b[i][j]=i;
				}
				for(l=i+1;l<j;l++)
				{
					if(a[i][j]>a[i][l]+a[l+1][j])
					{
						a[i][j]=a[i][l]+a[l+1][j];
						b[i][j]=l;
					}
				}
			}
		}
		print(0,strlen(str)-1);
		printf("\n");
	}
	return 0;
}