#include <stdio.h>
int main()
{
	int i,j,t=1,n,a[10000][2],result;
	for(;;)
	{
		scanf("%d",&a[0][0]);
		if(a[0][0]==-1) break;
		for(n=1;;n++)
		{
			scanf("%d",&a[n][0]);
			if(a[n][0]==-1) break;
		}
		result=1;
		a[0][1]=1;
		for(i=1;i<n;i++)
		{
			a[i][1]=1;
			for(j=0;j<i;j++)
			{
				if(a[j][0]>=a[i][0]&&a[j][1]+1>a[i][1])
					a[i][1]=a[j][1]+1;
				if(a[i][1]>result) result=a[i][1];
			}
		}
		printf("Test #%d:\n",t);
		printf("  maximum possible interceptions: %d\n\n",result);
		t++;
	}
	return 0;
}