#include <stdio.h>
#include <string.h>
int main()
{
	int i,j,n,w,s,x;
	char name[64][16];
	scanf("%d",&n);
	for(i=0;i<n;i++)
		scanf("%s",name[i]);
	scanf("%d,%d",&w,&s);
	s=s%n;
	x=w-2;
	for(i=0;i<n;i++)
	{
		for(j=0;j<s;j++)
		{
			x++;
			if(name[x%n][0]==0)
			{
				j--;
				continue;
			}
		}
		printf("%s\n",name[x%n]);
		name[x%n][0]=0;
	}
	return 0;
}
			