#include <stdio.h>
#include <string.h>
long int f[420000][2];
int main()
{
	long int sum,n[6],i,j,k;
	int t=1;
	while(scanf("%d %d %d %d %d %d",&n[0],&n[1],&n[2],&n[3],&n[4],&n[5])!=EOF)
	{
		if(n[0]==0&&n[1]==0&&n[2]==0&&n[3]==0&&n[4]==0&&n[5]==0) break;
		sum=0;
		for(i=0;i<6;i++)
			sum+=(n[i]*(i+1));
		if(sum%2!=0)
		{
			printf("Collection #%d:\n",t);
			printf("Can't be divided.\n\n");
			t++;
			continue;
		}
		for(i=0;i<=sum/2;i++)
		{
			f[i][0]=0;
			f[i][1]=0;
		}
		f[0][0]=1;
		for(i=0;i<6;i++)
		{
			for(j=1;j*2<=n[i];j*=2)
			{
				for(k=j*(i+1);k<=sum/2;k++)
				{
					if(f[k-j*(i+1)][0]==1&&f[k-j*(i+1)][1]==0&&f[k][0]==0)
					{
						f[k][0]=1;
						f[k][1]=1;
					}
				}
				for(k=0;k<=sum/2;k++)
					f[k][1]=0;
			}
			j=n[i]-j+1;
			for(k=j*(i+1);k<=sum/2;k++)
			{
				if(f[k-j*(i+1)][0]==1&&f[k-j*(i+1)][1]==0&&f[k][0]==0)
				{
					f[k][0]=1;
					f[k][1]=1;
				}
			}
			for(k=0;k<=sum/2;k++)
				f[k][1]=0;
		}
		printf("Collection #%d:\n",t);
		if(f[sum/2][0]==0)
			printf("Can't be divided.\n\n");
		else
			printf("Can be divided.\n\n");
		t++;
	}
	return 0;
}