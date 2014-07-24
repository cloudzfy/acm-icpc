#include <stdio.h>
struct m
{
    int east,west,south,north,mark;
}map[500][500];
int result,r,c,ent_column,exit_column;
void walk(int x,int y,int direction,int times)
{
    while(1)
    {
        if(direction==0)
        {
            if(x+1<r&&!map[x][y].south)
            {
                x++;
                if(!map[x][y].mark)
                {
                    map[x][y].mark=1;
                    result++;
                }
                direction=1;
            }
			else if(times==0&&y==exit_column&&x==r-1)break;
            else if(y+1<c&&!map[x][y].east)
            {
                y++;
                if(!map[x][y].mark)
                {
                    map[x][y].mark=1;
                    result++;
                }
                direction=0;
            }
            else if(x-1>=0&&!map[x][y].north)
            {
                x--;
                if(!map[x][y].mark)
                {
                    map[x][y].mark=1;
                    result++;
                }
                direction=3;
            }
			else if(times==1&&y==ent_column&&x==0)break;
            else if(y-1>=0&&!map[x][y].west)
            {
                y--;
                if(!map[x][y].mark)
                {
                    map[x][y].mark=1;
                    result++;
                }
                direction=2;
            }
        }
        else if(direction==1)
        {
            if(y-1>=0&&!map[x][y].west)
            {
                y--;
                if(!map[x][y].mark)
                {
                    map[x][y].mark=1;
                    result++;
                }
                direction=2;
            }
            else if(x+1<r&&!map[x][y].south)
            {
                x++;
                if(!map[x][y].mark)
                {
                    map[x][y].mark=1;
                    result++;
                }
                direction=1;
            }
			else if(times==0&&y==exit_column&&x==r-1)break;
            else if(y+1<c&&!map[x][y].east)
            {
                y++;
                if(!map[x][y].mark)
                {
                    map[x][y].mark=1;
                    result++;
                }
                direction=0;
            }
            else if(x-1>=0&&!map[x][y].north)
            {
                x--;
                if(!map[x][y].mark)
                {
                    map[x][y].mark=1;
                    result++;
                }
                direction=3;
            }
			else if(times==1&&y==ent_column&&x==0)break;
        }
        else if(direction==2)
        {
            if(x-1>=0&&!map[x][y].north)
            {
                x--;
                if(!map[x][y].mark)
                {
                    map[x][y].mark=1;
                    result++;
                }
                direction=3;
            }
			else if(times==1&&y==ent_column&&x==0)break;
            else if(y-1>=0&&!map[x][y].west)
            {
                y--;
                if(!map[x][y].mark)
                {
                    map[x][y].mark=1;
                    result++;
                }
                direction=2;
            }
            else if(x+1<r&&!map[x][y].south)
            {
                x++;
                if(!map[x][y].mark)
                {
                    map[x][y].mark=1;
                    result++;
                }
                direction=1;
            }
			else if(times==0&&y==exit_column&&x==r-1)break;
            else if(y+1<c&&!map[x][y].east)
            {
                y++;
                if(!map[x][y].mark)
                {
                    map[x][y].mark=1;
                    result++;
                }
                direction=0;
            }
        }
        else if(direction==3)
        {
            if(y+1<c&&!map[x][y].east)
            {
                y++;
                if(!map[x][y].mark)
                {
                    map[x][y].mark=1;
                    result++;
                }
                direction=0;
            }
            else if(x-1>=0&&!map[x][y].north)
            {
                x--;
                if(!map[x][y].mark)
                {
                    map[x][y].mark=1;
                    result++;
                }
                direction=3;
            }
			else if(times==1&&y==ent_column&&x==0)break;
            else if(y-1>=0&&!map[x][y].west)
            {
                y--;
                if(!map[x][y].mark)
                {
                    map[x][y].mark=1;
                    result++;
                }
                direction=2;
            }
            else if(x+1<r&&!map[x][y].south)
            {
                x++;
                if(!map[x][y].mark)
                {
                    map[x][y].mark=1;
                    result++;
                }
                direction=1;
            }
			else if(times==0&&y==exit_column&&x==r-1)break;
        }
    }
}
int main()
{
    int t,i,j,x;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d%d%d",&r,&c,&ent_column,&exit_column);
		for(i=0;i<r;i++)
		{
			for(j=0;j<c;j++)
			{
				map[i][j].mark=0;
			}
		}
        for(i=0;i<2*r-1;i++)
        {
            if(i%2==0)
            {
                map[i/2][0].west=1;
                for(j=0;j<c-1;j++)
                {
                    scanf("%d",&x);
                    map[i/2][j].east=x;
                    map[i/2][j+1].west=x;
                }
                map[i/2][c-1].east=1;
            }
            else
            {
                for(j=0;j<c;j++)
                {
                    scanf("%d",&x);
                    if(i/2==0)map[i/2][j].north=1;
                    map[i/2][j].south=x;
                    if(i/2+1<r)map[i/2+1][j].north=x;
                }
            }
        }
		result=0;
        walk(0,ent_column,1,0);
        walk(r-1,exit_column,3,1);
        if(result==r*c)printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
