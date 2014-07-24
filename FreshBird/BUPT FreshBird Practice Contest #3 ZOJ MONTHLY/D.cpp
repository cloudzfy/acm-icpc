#include <stdio.h>
char map[40000];
int main()
{
	int t=1,x,y,i,j,tmp;
	while(scanf("%d%d",&x,&y)!=EOF)
	{
		printf("Case #%d:\n",t);
		map[0]='P';
		for(j=1;j<y;j++)
		{
			map[j]='H';
		}
		for(i=1;i<x;i++)
		{
			map[y*i]='H';
		}
		for(i=1;i<x;i++)
		{
			for(j=1;j<y;j++)
			{
				if(i==j) map[i*y+i]='P';
				else if(j>i)
				{
					tmp=j-i;
					do
					{
						if(map[(tmp-1)+i*y]=='P')
						{
							map[i*y+j]='H';
							break;
						}
						else
						{
							map[i*y+j]='P';
						}
						tmp-=(i+1);
					}while(tmp>0);
				}
				else if(j<i)
				{
					tmp=i-j;
					do
					{
						if(map[(tmp-1)*y+j]=='P')
						{
							map[i*y+j]='H';
							break;
						}
						else
						{
							map[i*y+j]='P';
						}
						tmp-=(j+1);
					}while(tmp>0);
				}
			}
		}
		for(i=0;i<x;i++)
		{
			for(j=0;j<y;j++)
			{
				printf("%c",map[i*y+j]);
			}
			printf("\n");
		}
		t++;
	}
	return 0;
}