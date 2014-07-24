#include <stdio.h>
#include <math.h>
int main()
{
	double l,n,c,l1,left,right,mid,R;
	for(;;)
	{
		scanf("%lf %lf %lf",&l,&n,&c);
		if(l==-1&&n==-1&&c==-1) break;
		l1=(1+n*c)*l;
		left=0;
		right=l/2;
		mid=(left+right)/2;
		while(right-left>1e-5)
		{
			mid=(left+right)/2;
			R=l*l/8/mid+mid/2;
			if(l1/2-R*asin(l/2/R)<0) right=mid;
			else left=mid;
		}
		printf("%.3lf\n",mid);
	}
	return 0;
}