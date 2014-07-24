#include <stdio.h>
#include <math.h>
int main()
{
	long double l,left,right,mid;
	long long sum=0,length[10000];
	int n,k,i;
	scanf("%d %d",&n,&k);
	for(i=0;i<n;i++)
	{
		scanf("%lf",&l);
		length[i]=l*100;
		sum+=length[i];
	}
	left=0;
	right=sum/k;
	mid=(left+right)/2;
	while(right-left>0.0001)
	{
		mid=(left+right)/2;
		sum=0;
		for(i=0;i<n;i++) sum+=(length[i]/mid);
		if(sum>=k) left=mid;
		else right=mid;
	}
	sum=0;
	mid=floor(mid)+1;
	for(i=0;i<n;i++)
		sum+=(length[i]/mid);
	if(sum<k) mid--;
	printf("%.2f\n",mid/100);
	return 0;
}