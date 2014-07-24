#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
int main()
{
	char num[62],num2[62],m[2];
	int total[10],length,add[10],i,j,k,b;
	while(scanf("%s",num)!=EOF)
	{
		b=1;
		printf("%s",num);
		memset(total,0,sizeof(int)*10);
		length=strlen(num);
		j=61;
		for(i=length-1;i>=0;i--)
		{
			num[j]=num[i]-'0';
			j--;
		}
		for(;j>=0;j--)
			num[j]=0;
		for(i=0;i<62;i++)
		{
			total[num[i]]++;
		}
		for(i=2;i<=length;i++)
		{
			if(b==0) break;
			m[0]=i/10;
			m[1]=i%10;
			memset(add,0,sizeof(int)*10);
			for(j=0;j<62;j++)
				num2[j]=0;
			for(k=1;k>=0;k--)
			{
				for(j=61;j+k-2>=0;j--)
		    	{
			    	num2[j+k-1]+=num[j]*m[k];
					num2[j+k-2]+=floor((double)num2[j+k-1]/10);
					num2[j+k-1]=num2[j+k-1]%10;
				}
			}
			for(j=0;j<62;j++)
				add[num2[j]]++;
			for(j=0;j<10;j++)
			{
				if(add[j]!=total[j])
				{
					b=0;
					break;
				}
			}
			for(j=0;j<62;j++)
				num2[j]=num[j];
		}
		if(b==0) printf(" is not cyclic\n");
		else printf(" is cyclic\n");
	}
	return 0;
}