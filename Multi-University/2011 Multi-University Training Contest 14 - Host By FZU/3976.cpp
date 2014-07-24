//假设N点电势为0，列方程求，高斯消元
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <algorithm>
using namespace std;
#define eps 1e-8
int N;
double A[50][51],x[50];

void gauss_cpivot()
{
	int i,j,k,id;
	for(i=0;i<N;i++)
	{
		for(j=i+1,id=i;j<N;j++)
		{
			if(fabs(A[j][i])>fabs(A[id][i])) id=j;
		}
		if(fabs(A[id][i])<eps)return;
		if(id!=i)
		{
			for(j=i;j<=N;j++)
				swap(A[i][j],A[id][j]);
		}
		for(j=i+1;j<N;j++)
		{
			for(k=N;k>=i;k--)
				A[j][k]-=A[i][k]*A[j][i]/A[i][i];
		}
	}
	for(i=N-1;i>=0;i--)
	{
		x[i]=A[i][N]/A[i][i];
		for(j=i-1;j>=0;j--)
		{
			A[j][N]-=A[j][i]*x[i];
		}
	}
}
int main()
{
	int t,T,M,i,a,b,c;
	scanf("%d",&T);
	for(t=1;t<=T;t++)
	{
		scanf("%d%d",&N,&M);
		memset(A,0,sizeof(A));
		for(i=0;i<M;i++)
		{
			scanf("%d%d%d",&a,&b,&c);
			a--,b--;
			A[a][a]+=1/(double)c;
			A[a][b]-=1/(double)c;
			A[b][a]-=1/(double)c;
			A[b][b]+=1/(double)c;
		}
		for(i=0;i<N;i++)A[i][N-1]=0;
		A[0][N-1]=1;
		A[N-1][N-1]=-1;
		N--;
		gauss_cpivot();
		printf("Case #%d: %.2f\n",t,x[0]);
	}
	return 0;
}