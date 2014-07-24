#include <stdio.h>
char map[3][4];
int main()
{
	int first=0,second=0,nextperson,i,j,a,b,win=0,xtwice=0;
	for(i=0;i<3;i++)
	{
		scanf("%s",map[i]);
	}
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			if(map[i][j]=='X')
			{
				first++;
			}
			else if(map[i][j]=='0')
			{
				second++;
			}
		}
	}
	if(first==second+1)
	{
		nextperson=2;
	}
	else if(first==second)
	{
		nextperson=1;
	}
	else
	{
		printf("illegal\n");
		return 0;
	}
	for(i=0;i<3;i++)
	{
		a=0;
		b=0;
		for(j=0;j<3;j++)
		{
			if(map[i][j]=='X')
			{
				a++;
			}
			else if(map[i][j]=='0')
			{
				b++;
			}
		}
		if(a==3)
		{
			if(nextperson==2)
			{
				if((win==1&&xtwice==1)||win==0)
				{
					win=1;
					xtwice=1;
				}
				else
				{
					printf("illegal\n");
					return 0;
				}
			}
			else
			{
				printf("illegal\n");
				return 0;
			}
		}
		else if(b==3)
		{
			if(nextperson==1)
			{
				if(win==0)win=2;
				else
				{
					printf("illegal\n");
					return 0;
				}
			}
			else
			{
				printf("illegal\n");
				return 0;
			}
		}
		a=0;
		b=0;
		for(j=0;j<3;j++)
		{
			if(map[j][i]=='X')
			{
				a++;
			}
			else if(map[j][i]=='0')
			{
				b++;
			}
		}
		if(a==3)
		{
			if(nextperson==2)
			{
				if((win==1&&xtwice==1)||win==0)
				{
					win=1;
					xtwice=1;
				}
				else
				{
					printf("illegal\n");
					return 0;
				}
			}
			else
			{
				printf("illegal\n");
				return 0;
			}
		}
		if(b==3)
		{
			if(nextperson==1)
			{
				if(win==0)win=2;
				else
				{
					printf("illegal\n");
					return 0;
				}
			}
			else
			{
				printf("illegal\n");
				return 0;
			}
		}
	}
	a=0;
	b=0;
	for(j=0;j<3;j++)
	{
		if(map[j][j]=='X')
		{
			a++;
		}
		else if(map[j][j]=='0')
		{
			b++;
		}
	}
	if(a==3)
	{
		if(nextperson==2)
		{
			if((win==1&&xtwice==1)||win==0)
			{
				win=1;
				xtwice=1;
			}
			else
			{
				printf("illegal\n");
				return 0;
			}
		}
		else
		{
			printf("illegal\n");
			return 0;
		}
	}
	if(b==3)
	{
		if(nextperson==1)
		{
			if(win==0)win=2;
				else
				{
					printf("illegal\n");
					return 0;
				}
		}
		else
		{
			printf("illegal\n");
			return 0;
		}
	}
	a=0;
	b=0;
	for(j=0;j<3;j++)
	{
		if(map[j][2-j]=='X')
		{
			a++;
		}
		else if(map[j][2-j]=='0')
		{
			b++;
		}
	}
	if(a==3)
	{
		if(nextperson==2)
		{
			if((win==1&&xtwice==1)||win==0)
			{
				win=1;
				xtwice=1;
			}
			else
			{
				printf("illegal\n");
				return 0;
			}
		}
		else
		{
			printf("illegal\n");
			return 0;
		}
	}
	if(b==3)
	{
		if(nextperson==1)
		{
			if(win==0)win=2;
				else
				{
					printf("illegal\n");
					return 0;
				}
		}
		else
		{
			printf("illegal\n");
			return 0;
		}
	}
	if(win==1)
	{
		printf("the first player won\n");
		return 0;
	}
	if(win==2)
	{
		printf("the second player won\n");
		return 0;
	}
	if(first+second==9)
	{
		printf("draw\n");
		return 0;
	}
	if(nextperson==2)
	{
		printf("second\n");
		return 0;
	}
	if(nextperson==1)
	{
		printf("first\n");
		return 0;
	}
	return 0;
}