#include <stdio.h>
int main()
{
	char a[101],b[101];
	int t,a1,b1,i,j,f[101][101],match[5][5]={5,-1,-2,-1,-3,-1,5,-3,-2,-4,-2,-3,5,-2,-2,-1,-2,-2,5,-1,-3,-4,-2,-1,0};
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d %s",&a1,a);
		scanf("%d %s",&b1,b);
		for(i=0;i<a1;i++)
		{
			switch(a[i])
			{
			case 'A':a[i]=0;break;
			case 'C':a[i]=1;break;
			case 'G':a[i]=2;break;
			case 'T':a[i]=3;break;
			case '-':a[i]=4;break;
			}
		}
		for(i=0;i<b1;i++)
		{
			switch(b[i])
			{
			case 'A':b[i]=0;break;
			case 'C':b[i]=1;break;
			case 'G':b[i]=2;break;
			case 'T':b[i]=3;break;
			case '-':b[i]=4;break;
			}
		}
		f[0][0]=0;
		for(i=1;i<=a1;i++)
		{
			f[0][i]=f[0][i-1]+match[4][a[i-1]];
		}
		for(i=1;i<=b1;i++)
		{
			f[i][0]=f[i-1][0]+match[b[i-1]][4];
		}
		for(i=1;i<=b1;i++)
		{
			for(j=1;j<=a1;j++)
			{
				f[i][j]=f[i-1][j-1]+match[b[i-1]][a[j-1]];
				if(f[i-1][j]+match[b[i-1]][4]>f[i][j])
					f[i][j]=f[i-1][j]+match[b[i-1]][4];
				if(f[i][j-1]+match[4][a[j-1]]>f[i][j])
					f[i][j]=f[i][j-1]+match[4][a[j-1]];
			}
		}
		printf("%d\n",f[b1][a1]);
	}
	return 0;
}