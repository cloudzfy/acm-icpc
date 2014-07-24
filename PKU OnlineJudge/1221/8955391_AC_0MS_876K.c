#include <stdio.h>
#include <string.h>
long long s[301][301];
int main()
{
	int i,j,n;
	memset(s,0,sizeof(s));
	for(i=1;i<=300;i++)
	{
		for(j=i/2+1;j<=i;j++)
		{
			s[i][j]=1;
		}
	}
	for(i=1;i<=300;i++)
	{
		s[0][i]=1;
	}
	for(i=1;i<=300;i++)
	{
		for(j=i/2;j>=1;j--)
		{
			s[i][j]=s[i-2*j][j]+s[i][j+1];
		}
	}
	while(scanf("%d",&n)!=EOF)
	{
		if(n==0) break;
		printf("%d %lld\n",n,s[n][1]);
	}
	return 0;
}