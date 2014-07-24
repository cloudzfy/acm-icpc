/* POJ 1681
 * 高斯消元（模板）
 * Memory:376K Time:0MS
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <algorithm>
using namespace std;
#define MAXN 225
char str[15][16];
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
	int T,N,i,j,k,a,b,result;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&N);
		for(i=0;i<N;i++)
		{
			scanf("%s",str[i]);
		}
		memset(A,0,sizeof(A));
		for(i=0;i<N;i++)
		{
			for(j=0;j<N;j++)
			{
				if(str[i][j]!='y')A[i*N+j][N*N]=1;
				A[i*N+j][i*N+j]=1;
				for(k=0;k<4;k++)
				{
					a=i+move[k][0];
					b=j+move[k][1];
					if(a>=0&&a<N&&b>=0&&b<N)
						A[i*N+j][a*N+b]=1;
				}
			}
		}
        result=gaos(N*N,N*N);
		if(result==-1)printf("inf\n");
		else printf("%d\n",result);
	}
	return 0;
}