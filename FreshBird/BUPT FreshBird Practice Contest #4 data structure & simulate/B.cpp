#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
int set[20001],xor[20001],n;
int find(int k)
{
	int tmp;
	if(set[k]!=k)
	{
		tmp=set[k];
		set[k]=find(set[k]);
		xor[k]=xor[k]^xor[tmp];
	}
	return set[k];
}

int combine(int p,int q,int v)
{
	int a,b;
	a=find(p);
	b=find(q);
	if(a!=b)
	{
		if(a==n)swap(a,b);
		set[a]=b;
		xor[a]=xor[p]^xor[q]^v;
	}
	else if((xor[p]^xor[q])!=v)return 0;
	return 1;
}
int main()
{
	int times[30];
	int Q,p,q,v,re,fact,i,ans,k,result,flag,x,t=1,silent,total;
	char op[2],str[1000];
	while(scanf("%d%d",&n,&Q)==2)
	{
		if(n==0)break;
		silent=0;
		printf("Case %d:\n",t);
		t++;
		fact=0;
		memset(xor,0,sizeof(xor));
		for(i=0;i<=n;i++)
		{
			set[i]=i;
		}
		while(Q--)
		{
			scanf("%s",op);
			if(silent)
			{
				gets(str);
				continue;
			}
			if(op[0]=='I')
			{
				fact++;
				gets(str);
				re=sscanf(str,"%d%d%d",&p,&q,&v);
				if(re==2) ans=combine(p,n,q);
				else ans=combine(p,q,v);
				if(!ans)
				{
					printf("The first %d facts are conflicting.\n",fact);
					silent=1;
				}
			}
			else
			{
				scanf("%d",&k);
				result=0;
				total=0;
				memset(times,-1,sizeof(times));
				while(k--)
				{
					scanf("%d",&x);
					ans=find(x);
					result=result^xor[x];
					for(i=0;i<total;i++)
					{
						if(times[i]==ans)break;
					}
					if(i==total) times[total++]=ans;
					else times[i]=-1;
				}
				result=result^xor[n];
				flag=1;
				for(i=0;i<total;i++)
				{
					if(times[i]!=-1&&times[i]!=n)
					{
						flag=0;
						break;
					}
				}
				if(flag) printf("%d\n",result);
				else printf("I don't know.\n");
			}
		}
		printf("\n");
	}
	return 0;
}