#include <stdio.h>
#include <string.h>
int main()
{
	int i,j,k,tmp,n,key[200],mod[200];
	char string[201],result[201];
	for(;;)
	{
		scanf("%d",&n);
		if(n==0) break;
		for(i=0;i<n;i++)
		{
			scanf("%d",&key[i]);
		}
		for(i=0;i<n;i++)
		{
			mod[i]=1;
			if(key[i]==i+1) continue;
			tmp=key[i];
			mod[i]=0;
			do
			{
				tmp=key[tmp-1];
				mod[i]++;
			}while(tmp!=key[i]);
		}
		for(;;)
		{
			scanf("%d",&k);
			if(k==0) break;
			getchar();
			gets(string);
			for(i=strlen(string);i<n;i++)
			{
				string[i]=' ';
			}
			string[i]=0;
			for(i=0;i<n;i++)
			{
				result[i]=0;
			}
			for(i=0;string[i]!=0&&i<n;i++)
			{
				tmp=key[i];
				for(j=1;j<k%mod[i];j++)
				{
					tmp=key[tmp-1];
				}
				if(k%mod[i]==0) tmp=i+1;
				result[tmp-1]=string[i];
			}
			result[n]=0;
			for(i=strlen(result)-1;;i--)
			{
				if(result[i]!=' ')
				{
					result[i+1]=0;
					break;
				}
			}
			printf("%s\n",result);
		}
		printf("\n");
	}
	return 0;
}