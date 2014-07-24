#include <stdio.h>
#include <string.h>
char str[50010];
int c[50010],N;
void add(int i,int value)
{
	while(i<=N)
	{
		c[i]+=value;
		i+=(i&(-i));
	}
}
int getSum(int i)
{
	int s=0;
	while(i>0)
	{
		s+=c[i];
		i-=(i&(-i));
	}
	return s;
}
int main()
{
	int i,j;
	char ch[2],tmp1[4],tmp2[4];
	int t,T,M,left,right,op,k;
	scanf("%d",&T);
	for(t=1;t<=T;t++)
	{
		memset(c,0,sizeof(c));
		scanf("%d%d",&N,&M);
		scanf("%s",str);
		for(i=2;str[i]!=0;i++)
		{
			if(str[i-2]=='w'&&str[i-1]=='b'&&str[i]=='w')
				add(i,1);
		}
		printf("Case %d:\n",t);
		while(M--)
		{
			scanf("%d",&op);
			if(op==0)
			{
				scanf("%d%d",&left,&right);
				if(right-left>=2) printf("%d\n",getSum(right)-getSum(left+1));
				else printf("0\n");
			}
			else
			{
				scanf("%d%s",&k,ch);
				for(i=0;i<3;i++)
				{
					if(k+2-i>=N)continue;
					if(k-i<0)continue;
					for(j=0;j<3;j++)
					{
						tmp1[j]=str[k+j-i];
						if(j==i)tmp2[j]=ch[0];
						else tmp2[j]=str[k+j-i];
					}
					tmp1[j]=0;
					tmp2[j]=0;
					if(strcmp(tmp1,"wbw")==0&&strcmp(tmp2,"wbw")!=0)
					{
						add(k-i+2,-1);
					}
					else if(strcmp(tmp1,"wbw")!=0&&strcmp(tmp2,"wbw")==0)
					{
						add(k-i+2,1);
					}
				}
				str[k]=ch[0];
			}
		}
	}
	return 0;
}