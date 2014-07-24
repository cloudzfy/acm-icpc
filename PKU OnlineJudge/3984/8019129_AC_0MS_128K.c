#include <stdio.h>

int maze[5][5],step[5][5];
void mark(int x,int y,int s)
{
	step[x][y]=s;
	if(x<4&&maze[x+1][y]==0&&step[x+1][y]>s) mark(x+1,y,s+1);
	if(y<4&&maze[x][y+1]==0&&step[x][y+1]>s) mark(x,y+1,s+1);
	if(x>0&&maze[x-1][y]==0&&step[x-1][y]>s) mark(x-1,y,s+1);
	if(y>0&&maze[x][y-1]==0&&step[x][y-1]>s) mark(x,y-1,s+1);
}
void find(int x,int y)
{
	int next=0,s=11111;
	if(x<4&&maze[x+1][y]==0&&step[x+1][y]<s)
	{
		s=step[x+1][y];
		next=1;
	}
	if(y<4&&maze[x][y+1]==0&&step[x][y+1]<s)
	{
		s=step[x][y+1];
		next=2;
	}
	if(x>0&&maze[x-1][y]==0&&step[x-1][y]<s)
	{
		s=step[x-1][y];
		next=3;
	}
	if(y>0&&maze[x][y-1]==0&&step[x][y-1]<s)
	{
		s=step[x][y-1];
		next=4;
	}
	if(next==1)
	{
		maze[x+1][y]=2;
		find(x+1,y);
	}
	else if(next==2)
	{
		maze[x][y+1]=2;
		find(x,y+1);
	}
	else if(next==3)
	{
		maze[x-1][y]=2;
		find(x-1,y);
	}
	else if(next==4)
	{
		maze[x][y-1]=2;
		find(x,y-1);
	}
}

void print(int x,int y)
{
	printf("(%d, %d)\n",x,y);
	if(x<4&&maze[x+1][y]==2)
	{
		maze[x+1][y]=-1;
		print(x+1,y);
	}
	else if(y<4&&maze[x][y+1]==2)
	{
		maze[x][y+1]=-1;
		print(x,y+1);
	}
	else if(x>0&&maze[x-1][y]==2)
	{
		maze[x-1][y]=-1;
		print(x-1,y);
	}
	else if(y>0&&maze[x][y-1]==2)
	{
		maze[x][y-1]=-1;
		print(x,y-1);
	}
}
int main()
{
	int i,j;
	for(i=0;i<5;i++)
	{
		for(j=0;j<5;j++)
		{
			scanf("%d",&maze[i][j]);
			step[i][j]=11111;
		}
	}
	mark(0,0,0);
	find(4,4);
	maze[4][4]=2;
	print(0,0);
	return 0;
}