#include <stdio.h>
#include <string.h>
int num[110],match[10],length,lengthm,tmp[110],tmp2[110];
int x[110];
char a[102],b[9];
int minus()
{
	int bit=0,ans,p,i;
	for(i=0;i<=length+1;i++)
	{
		if(tmp[i]-num[i]<0)
		{
			tmp[i+1]--;
			x[i]=tmp[i]-num[i]+10;
		}
		else x[i]=tmp[i]-num[i];
		if(x[i])bit=i;
	}
	if(bit>8)return -1;
	else
	{
		p=1;
		ans=0;
		for(i=0;i<=bit;i++)
		{
			ans+=x[i]*p;
			p*=10;
		}
	}
	return ans;
}

int main()
{
	int i,times,t,result,j,flag,ans,over;
	scanf("%d",&times);
	for(t=1;t<=times;t++)
	{
		scanf("%s%s",a,b);
		result=11111111;
		length=(int)strlen(a);
		lengthm=(int)strlen(b);
		memset(num,0,sizeof(num));
		for(i=0,j=length-1;a[i]!=0;i++,j--)
		{
			num[i]=a[j]-'0';
		}
		for(i=0,j=lengthm-1;b[i]!=0;i++,j--)
		{
			match[j]=b[i]-'0';
		}
		over=1;
		if(length<lengthm)
		{
			memset(tmp,0,sizeof(tmp));
			for(i=0;i<lengthm;i++)tmp[i]=match[i];
			length=lengthm;
			result=minus();
			over=0;
		}
		for(i=0;i<=length-lengthm+1&&over;i++)
		{
			if(lengthm==1&&match[0]==0&&i==length-lengthm+1)continue;
			flag=1;
			memset(tmp,0,sizeof(tmp));
			for(j=i+lengthm-1;j>=i;j--)
			{
				if(num[j]>match[j-i])
				{
					flag=0;
					break;
				}
				else if(num[j]<match[j-i])
				{
					flag=2;
					break;
				}
			}
			if(flag==1)
			{
				result=0;
				break;
			}
			for(j=0;j<length;j++) tmp[j]=num[j];
			if(!flag)
			{
				tmp[i+lengthm]++;
				if(tmp[i+lengthm]>9)
				{
					for(j=i+lengthm;j<=length;j++)
					{
						if(tmp[j]>9)
						{
							tmp[j+1]++;
							tmp[j]=tmp[j]%10;
						}
					}
				}
			}
			for(j=i+lengthm-1;j>=i;j--)
			{
				tmp[j]=match[j-i];
			}
			for(;j>=0;j--)
			{
				tmp[j]=0;
			}
			memset(x,0,sizeof(x));
			ans=minus();
			if(ans==-1)continue;
			if(ans<result)result=ans;
		}
		printf("Case #%d: %d\n",t,result);
	}
	return 0;
}