#include <stdio.h>
#include <string.h>
char map[200][200];
int m,n,d=0,a=0,step[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
void mark(int x,int y)
{
	map[x][y]=(a%26)+'A';
	a++;
	if(d%4==0&&(map[x+1][y]!=0||x+1>=n))d++;
	else if(d%4==1&&(map[x][y+1]!=0||y+1>=m))d++;
	else if(d%4==2&&(map[x-1][y]!=0||x-1<0)) d++;
	else if(d%4==3&&(map[x][y-1]!=0||y-1<0)) d++;
	if((map[x+1][y]!=0||x+1>=n)&&(map[x][y+1]!=0||y+1>=m)&&(map[x-1][y]!=0||x-1<0)&&(map[x][y-1]!=0||y-1<0)) return;
	mark(x+step[d%4][0],y+step[d%4][1]);
}
int main()
{
	int i,j;
	scanf("%d%d",&m,&n);
	memset(map,0,sizeof(map));
	mark(0,0);
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			printf("   %c",map[j][i]);
		}
		printf("\n");
	}
	return 0;
}