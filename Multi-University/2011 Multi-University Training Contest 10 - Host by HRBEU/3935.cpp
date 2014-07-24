#include <stdio.h>
#include <string.h>
#define INF 1000000
int map[100],tmp[100],bit[65536];
int getNum(int x)
{
	int num=0;
	while(x)
	{
		if(x&1)num++;
		x>>=1;
	}
	return num;
}
int main()
{
	int i,j,x,data,ans,result,turn,n,m,M;
	for(i=0;i<65536;i++)//×¢ÒâÔ¤´¦Àí
	{
		bit[i]=getNum(i);
	}
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		result=INF;
		M=1<<m;
		memset(map,0,sizeof(map));
		for(i=0;i<n;i++)
		{
			for(j=0;j<m;j++)
			{
				scanf("%d",&data);
				map[i]|=(data<<j);
			}
		}
		for(x=0;x<M;x++)
		{
			for(i=0;i<n;i++) tmp[i]=map[i];
			tmp[0]=tmp[0]^((x^(x<<1)^(x>>1))%M);
			ans=bit[x];
			if(n>1)tmp[1]^=x;
			for(i=1;i<n;i++)
			{
				turn=(M-1)^tmp[i-1];
				tmp[i]=tmp[i]^((turn^(turn<<1)^(turn>>1))%M);
				if(i+1<n)tmp[i+1]^=turn;
				ans+=bit[turn];
			}
			if(tmp[n-1]==M-1)
			{
				if(result>ans)result=ans;
			}
		}
		if(result==INF)printf("no solution\n");
		else printf("%d\n",result);
	}
	return 0;
}