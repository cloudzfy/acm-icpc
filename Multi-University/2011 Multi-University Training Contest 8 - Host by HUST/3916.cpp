#include <stdio.h>
int data[10000];
int main()
{
	int result,t,n,i,j,left,tmp,b;
	scanf("%d",&t);
	while(t--)
	{
		result=100000;
		scanf("%d",&n);
		for(i=0;i<n;i++)
		{
			scanf("%d",&data[i]);
		}
		left=0;
		while(left<n-1)
		{
			b=0;
			for(i=left;i<n-1;i++)
			{
				if(data[i]>data[i+1])
				{
					if(result>i-left+1)result=i-left+1;
					tmp=data[left];
					if(tmp>data[i]-data[i+1])tmp=data[i]-data[i+1];
					for(j=left;j<=i;j++)
					{
						data[j]-=tmp;
					}
					b=1;
					break;
				}
			}
			if(b==0)
			{
				tmp=data[left];
				if(result>n-left)result=n-left;
				for(j=left;j<n;j++)
				{
					data[j]-=tmp;
				}
			}
			for(i=left;i<n;i++)
			{
				if(data[i]!=0) break;
			}
			left=i;
		}
		printf("%d\n",result);
	}
	return 0;
}