#include <stdio.h>
#include <string.h>
char map[100][101];
int set[10001];

int tree(int k)
{
	if(set[k]!=k)
	{
		set[k]=tree(set[k]);
	}
	return set[k];
}

int main()
{
	int m,n,result,total,i,j,p,q;;
	while(scanf("%d%d",&m,&n)!=EOF)
	{
		if(m==0) break;
		total=1;
		for(i=0;i<m;i++)
		{
			scanf("%s",map[i]);
		}
		for(i=0;i<m*n;i++)
		{
			set[i]=i;
		}
		for(i=0;i<m;i++)
		{
			for(j=0;j<n;j++)
			{
				if(map[i][j]=='@')
				{
					if(i>0&&map[i-1][j]=='@')
					{
						p=tree(i*n+j);
						q=tree(i*n+j-n);
						if(p!=q)
						{
							set[p]=q;
						}
					}
					if(i<m-1&&map[i+1][j]=='@')
					{
						p=tree(i*n+j);
						q=tree(i*n+j+n);
						if(p!=q)
						{
							set[p]=q;
						}
					}
					if(j>0&&map[i][j-1]=='@')
					{
						p=tree(i*n+j);
						q=tree(i*n+j-1);
						if(p!=q)
						{
							set[p]=q;
						}
					}
					if(j<n-1&&map[i][j+1]=='@')
					{
						p=tree(i*n+j);
						q=tree(i*n+j+1);
						if(p!=q)
						{
							set[p]=q;
						}
					}
					if(i<m-1&&j<n-1&&map[i+1][j+1]=='@')
					{
						p=tree(i*n+j);
						q=tree(i*n+j+n+1);
						if(p!=q)
						{
							set[p]=q;
						}
					}
					if(i>0&&j<n-1&&map[i-1][j+1]=='@')
					{
						p=tree(i*n+j);
						q=tree(i*n+j-n+1);
						if(p!=q)
						{
							set[p]=q;
						}
					}
					if(i<m-1&&j>0&&map[i+1][j-1]=='@')
					{
						p=tree(i*n+j);
						q=tree(i*n+j+n-1);
						if(p!=q)
						{
							set[p]=q;
						}
					}
					if(i>0&&j>0&&map[i-1][j-1]=='@')
					{
						p=tree(i*n+j);
						q=tree(i*n+j-n-1);
						if(p!=q)
						{
							set[p]=q;
						}
					}
				}
			}
		}
		result=0;
		for(i=0;i<m;i++)
		{
			for(j=0;j<n;j++)
			{
				if(map[i][j]=='*') continue;
				if(set[i*n+j]==i*n+j) result++;
			}
		}
		printf("%d\n",result);
	}
	return 0;
}