#include <stdio.h>
int main()
{
	int n,h,f[25],d[25],t[25],x[25][3],t1,result[2],backup[25][2],i,j,k,max,sum,m;
	for(;;)
	{
		scanf("%d",&n);
		if(n==0) break;
		scanf("%d",&h);
		for(i=0;i<n;i++)
		{
			scanf("%d",&f[i]);
		}
		for(i=0;i<n;i++)
		{
			scanf("%d",&d[i]);
		}
		for(i=0;i<n-1;i++)
		{
			scanf("%d",&t[i]);
		}
		t1=h*12;
		t[24]=0;
		result[0]=-1;
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				x[j][0]=f[j];
				x[j][1]=0;
				x[j][2]=0;
			}
			for(j=0;j<t1;j++)
			{
				max=0;
				m=-1;
				for(k=0;k<=i;k++)
				{
					if(x[k][0]>max)
					{
						m=k;
						max=x[k][0];
					}
				}
				if(m!=-1)
				{
					x[m][1]+=x[m][0];
					x[m][0]-=d[m];
					x[m][2]++;
				}
				else
					x[0][2]++;
 			}
			sum=0;
			for(j=0;j<n;j++)
				sum+=x[j][1];
			if(result[0]<sum)
			{
				result[0]=sum;
				result[1]=i;
				for(j=0;j<n;j++)
				{
					backup[j][0]=x[j][0];
					backup[j][1]=x[j][2];
				}
			}
			t1-=t[i];
		}
		sum=0;
		printf("%d",backup[0][1]*5);
		for(i=1;i<=n-1;i++)
		{
			printf(", %d",backup[i][1]*5);
		}
		printf("\nNumber of fish expected: %d\n\n",result[0]);
	}
	return 0;
}