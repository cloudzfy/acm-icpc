#include <stdio.h>
int main()
{
	int t,n,a[50000],i,j,sum,left,right,result,s,f,tmp;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(i=0;i<n;i++)
			scanf("%d",&a[i]);
		result=a[0];
		sum=0;
		left=a[0];
		s=a[0];
		for(i=0;i<n-1;i++)
		{
			sum+=a[i];
			if(sum<left)
			{
				left=sum;
				f=i;
				s=tmp;
			}
			if(sum>=0)
			{
				tmp=i+1;
				sum=0;
			}
		}
		for(i=s;i<=f;i++)
		{
			sum=0;
			left=a[0];
			for(j=0;j<i;j++)
			{
				sum+=a[j];
				if(sum>left) left=sum;
				if(sum<=0) sum=0;
			}
			sum=0;
			right=a[n-1];
			for(j=n-1;j>=i;j--)
			{
				sum+=a[j];
				if(sum>right) right=sum;
				if(sum<=0) sum=0;
			}
			if(left+right>result) result=left+right;
		}
		printf("%d\n",result);
	}
	return 0;
}