#include <stdio.h>
#include <string.h>
int main()
{
	int t,k,i;
	char np[65],num[65];
	long long j,N;
	scanf("%d",&t);
	while(t--)
	{
		memset(num,0,65);
		scanf("%d %s %lld",&k,np,&N);
		j=1;
		for(i=strlen(np)-1;i>0;i--)
		{
			if(N%2==0)
				num[i]='0';
			else
			{
				num[i]='1';
				if(np[i]=='p')
					N-=1;
				else
					N+=1;
			}
			N/=2;
		}
		if((N==1&&np[i]=='p')||(N==-1&&np[i]=='n'))
		{
			num[i]='1';
			printf("%s\n",num);
		}
		else if(N==0)
		{
			num[i]='0';
			printf("%s\n",num);
		}
		else
			printf("Impossible\n");
	}
	return 0;
}