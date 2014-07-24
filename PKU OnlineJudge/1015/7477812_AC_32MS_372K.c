#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
	int queue[30],path[30][1000],f[30][1000],n,m,p[300],d[300],t=1,result1,result2,i,j,k,l,tmp,b;
	for(;;)
	{
		scanf("%d %d",&n,&m);
		if(n==0&&m==0) break;
		memset(f,-1,sizeof(f));
		memset(path,-1,sizeof(path));
		for(i=0;i<n;i++)
		{
			scanf("%d %d",&p[i],&d[i]);
			if(f[1][400+p[i]-d[i]]<p[i]+d[i])
			{
				f[1][400+p[i]-d[i]]=p[i]+d[i];
				path[1][400+p[i]-d[i]]=i;
			}
		}
		for(i=2;i<=m;i++)
		{
			for(j=0;j<n;j++)
			{
				if(p[j]-d[j]<=0)
				{
					for(k=400-20*i;k<=400+20*i;k++)
						if(f[i-1][k]!=-1&&f[i-1][k]+p[j]+d[j]>f[i][k+p[j]-d[j]]&&j!=path[i-1][k])
						{
							tmp=k;
							b=0;
							for(l=i-1;l>1;l--)
							{
								if(j==path[l-1][tmp-p[path[l][tmp]]+d[path[l][tmp]]])
								{
									b=1;
									break;
								}
								tmp=tmp-p[path[l][tmp]]+d[path[l][tmp]];
							}
							if(b==0)
							{
								f[i][k+p[j]-d[j]]=f[i-1][k]+p[j]+d[j];
								path[i][k+p[j]-d[j]]=j;
							}
						}
				}
				else
				{
					for(k=400+20*i;k>=400-20*i;k--)
						if(f[i-1][k]!=-1&&f[i-1][k]+p[j]+d[j]>f[i][k+p[j]-d[j]]&&j!=path[i-1][k])
						{
							tmp=k;
							b=0;
							for(l=i-1;l>1;l--)
							{
								if(j==path[l-1][tmp-p[path[l][tmp]]+d[path[l][tmp]]])
								{
									b=1;
									break;
								}
								tmp=tmp-p[path[l][tmp]]+d[path[l][tmp]];
							}
							if(b==0)
							{
								f[i][k+p[j]-d[j]]=f[i-1][k]+p[j]+d[j];
								path[i][k+p[j]-d[j]]=j;
							}
						}
				}
			}
		}
		for(i=0;i<=m*20;i++)
		{
			if(f[m][400+i]!=-1||f[m][400-i]!=-1) break;
		}
		if(f[m][400+i]>=f[m][400-i])
		{
			queue[m-1]=path[m][400+i];
			tmp=400+i;
		}
		else
		{
			queue[m-1]=path[m][400-i];
			tmp=400-i;
		}
		for(i=m-1;i>0;i--)
		{
			queue[i-1]=path[i][tmp-p[queue[i]]+d[queue[i]]];
			tmp=tmp-p[queue[i]]+d[queue[i]];
		}
		for(i=0;i<m;i++)
		{
			for(j=i+1;j<m;j++)
			{
				if(queue[i]>queue[j])
				{
					tmp=queue[i];
					queue[i]=queue[j];
					queue[j]=tmp;
				}
			}
		}
		result1=0;
		result2=0;
		for(i=0;i<m;i++)
		{
			result1+=p[queue[i]];
			result2+=d[queue[i]];
		}
		printf("Jury #%d\n",t);
		printf("Best jury has value %d for prosecution and value %d for defence:\n",result1,result2);
		for(i=0;i<m;i++)
		{
			printf(" %d",queue[i]+1);
		}
		printf("\n\n");
		t++;
	}
	return 0;
}