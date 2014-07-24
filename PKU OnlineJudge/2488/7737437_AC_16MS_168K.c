#include <stdio.h>
#include <string.h>
int map[26][26],p,q,step[8][2]={{-2,-1},{-2,1},{-1,-2},{-1,2},{1,-2},{1,2},{2,-1},{2,1}},r;
char result1[64];
int result2[64];
int search(int x,int y)
{
	int b,i;
	for(i=0;i<8;i++)
	{
		if(x+step[i][1]<0||x+step[i][1]>=p||y+step[i][0]<0||y+step[i][0]>=q)continue;
		if(map[x+step[i][1]][y+step[i][0]]!=0) continue;
		map[x+step[i][1]][y+step[i][0]]=r;
		r++;
		b=search(x+step[i][1],y+step[i][0]);
		if(b==0)
		{
			map[x+step[i][1]][y+step[i][0]]=0;
			r--;
		}
		else return 1;
	}
	if(r==p*q+1) return 1;
	else return 0;
}

int main()
{
	int b,i,j,t,k;
	scanf("%d",&t);
	for(k=0;k<t;k++)
	{
		scanf("%d%d",&p,&q);
		memset(map,0,sizeof(map));
		map[0][0]=1;
		r=2;
		b=search(0,0);
		printf("Scenario #%d:\n",k+1);
		if(p==1&&q==1) printf("A1\n");
		else if(b==0) printf("impossible\n");
		else
		{
			for(i=0;i<p;i++)
			{
				for(j=0;j<q;j++)
				{
					result1[map[i][j]-1]='A'+j;
					result2[map[i][j]-1]=i+1;
				}
			}
			for(i=0;i<p*q;i++)
				printf("%c%d",result1[i],result2[i]);
			printf("\n");
		}
		printf("\n");
	}
	return 0;
}