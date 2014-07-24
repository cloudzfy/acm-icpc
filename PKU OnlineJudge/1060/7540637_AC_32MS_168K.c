#include <stdio.h>
#include <string.h>
int main()
{
	int t,f,g,h,x[4][2010],a,b,i,j;
	scanf("%d",&t);
	while(t--)
	{
		memset(x,0,sizeof(int)*8040);
		scanf("%d",&f);
		for(i=f-1;i>=0;i--)
			scanf("%d",&x[0][i]);
		scanf("%d",&g);
		for(i=g-1;i>=0;i--)
			scanf("%d",&x[1][i]);
		scanf("%d",&h);
		for(i=h-1;i>=0;i--)
			scanf("%d",&x[2][i]);
		for(i=f-1;i>=0;i--)
		{
			if(x[0][i]==0) continue;
			for(j=g-1;j>=0;j--)
			{
				if(x[1][j]==0) continue;
				x[3][i+j]=(x[3][i+j]+1)%2;
			}
		}
		for(i=h+f-2;i>=0;i--)
			if(x[3][i]==1) break;
		a=i;
		for(i=h-1;i>=0;i--)
			if(x[2][i]==1) break;
		b=i;
		while(a>=b)
		{
			j=a+1;
			for(i=b;i>=0;i--)
			{
				j--;
				if(x[2][i]==0) continue;
				x[3][j]=(x[3][j]+x[2][i])%2;
			}
			for(i=h+f-2;i>=0;i--)
				if(x[3][i]==1) break;
			a=i;
		}
		printf("%d",a+1);
		for(i=a;i>=0;i--)
			printf(" %d",x[3][i]);
		printf("\n");
	}
	return 0;
}
