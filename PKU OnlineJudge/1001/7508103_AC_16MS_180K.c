#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
int main()
{
	char num[7],num2[201],num3[201];
	int s,i,j,point,x;
	while(scanf("%s",num)!=EOF)
	{
		scanf("%d",&s);
		if(s==1)
		{
			if(num[0]=='0')
			{
				for(i=0;i<7;i++)
				{
					if(num[i]!='0') break;
				}
				for(j=0;num[i]!=0;j++)
				{
					num[j]=num[i];
					i++;
				}
				num[j]=0;
			}
			x=0;
			for(i=0;i<7;i++)
			{
				if(num[i]=='.')
				{
					x=1;
					break;
				}
			}
			if(num[strlen(num)-1]=='0'&&x==1)
			{
				for(i=strlen(num)-1;i>=0;i--)
				{
					if(num[i]!='0') break;
				}
				if(num[i]=='.') i--;
				num[i+1]=0;
			}
			if(num[strlen(num)-1]=='.') num[strlen(num)-1]=0;
			printf("%s\n",num);
			continue;
		}
		for(i=strlen(num)-1;i>=0;i--)
		{
			if(num[i]=='.') break;
		}
		point=strlen(num)-1-i;
		if(num[i]!='.') point=0;
		j=6;
		for(i=strlen(num)-1;i>=0;i--)
		{
			if(num[i]=='.') continue;
			num[j]=num[i]-'0';
			j--;
		}
		for(i=j;i>=0;i--)
			num[i]=0;
		for(i=200;i>=194;i--)
			num2[i]=num[i-194];
		for(i=193;i>=0;i--)
			num2[i]=0;
		for(x=0;x<s-1;x++)
		{
	    	for(i=200;i>=0;i--)
		    	num3[i]=0;
    		for(i=6;i>=0;i--)
	    	{
		    	for(j=200;j>=0;j--)
	    		{
					if(j+i-6<0) break;
		    		num3[j+i-6]+=num[i]*num2[j];
					if(j+i-6>0)
					{
						num3[j+i-7]+=(floor((double)num3[j+i-6]/10));
						num3[j+i-6]=num3[j+i-6]%10;
					}
	    		}
	    	}
	    	for(j=200;j>=0;j--)
		    	num2[j]=num3[j];
		}
		for(i=0;i<201;i++)
			num3[i]+='0';
		for(i=0;i<201;i++)
		{
			if(i==201-point*s) break;
			if(num3[i]!='0') break;
		}
		for(j=0;j<201;j++)
		{
			if(i==201-point*s) break;
			num3[j]=num3[i];
			i++;
		}
		num3[j]='.';
		for(j=j+1;i<201;j++)
		{
			num3[j]=num3[i];
			i++;
		}
		if(num3[j-1]=='0')
		{
			for(i=j-1;i>=0;i--)
			{
				if(num3[i]!='0') break;
			}
			if(num3[i]=='.') i--;
			num3[i+1]=0;
		}
		else num3[j]=0;
		if(point==0)
		{
			for(i=j-1;i>=0;i--)
			{
				if(num3[i]=='.')
				{
					num3[i]=0;
					break;
				}
			}
		}
		printf("%s\n",num3);
	}
	return 0;
}