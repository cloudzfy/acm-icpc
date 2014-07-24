#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <algorithm>
using namespace std;
#define MAXN 30
char map[5][6];
int A[MAXN][MAXN+1];
int move[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
int gaos(int r,int c)
{
	int i=0,j=0,k,l,id,cnt;
	while(i<r&&j<c)
	{
		id=i;
		for(k=i+1;k<r;k++)
		{
			if(abs(A[k][j])>abs(A[id][j]))
				id=k;
		}
		if(A[id][j]!=0)
		{
			for(k=j;k<c+1;k++)
				swap(A[id][k],A[i][k]);
			for(k=i+1;k<r;k++)
			{
				if(A[k][j]!=0)
				{
					for(l=j;l<c+1;l++)
						A[k][l]=A[k][l]^A[i][l];
				}
			}
			i++;
		}
		j++;
	}
	for(k=i;k<r;k++)
	{
		if(A[k][c]!=0)return -1;//无解
	}
	cnt=A[r-1][c];
	for(i=r-2;i>=0;i--)
	{
		for(j=i+1;j<r;j++)
		{
			A[i][c]^=(A[i][j]&&A[j][c]);;
		}
		cnt+=A[i][c];
	}
    return cnt;//无穷解
}
int main()
{
	int t,T,i,j,k,a,b;
	scanf("%d",&T);
	for(t=1;t<=T;t++)
	{
		for(i=0;i<5;i++)
		{
			for(j=0;j<6;j++)
			{
				scanf("%d",&map[i][j]);
			}
		}
		memset(A,0,sizeof(A));
		for(i=0;i<5;i++)
		{
			for(j=0;j<6;j++)
			{
				if(map[i][j]!=0)A[i*6+j][30]=1;
				A[i*6+j][i*6+j]=1;
				for(k=0;k<4;k++)
				{
					a=i+move[k][0];
					b=j+move[k][1];
					if(a>=0&&a<5&&b>=0&&b<6)
						A[i*6+j][a*6+b]=1;
				}
			}
		}
		gaos(30,30);
		printf("PUZZLE #%d\n",t);
		for(i=0;i<5;i++)
		{
			printf("%d",A[i*6][30]);
			for(j=1;j<6;j++)
			{
				printf(" %d",A[i*6+j][30]);
			}
			printf("\n");
		}
	}
	return 0;
}