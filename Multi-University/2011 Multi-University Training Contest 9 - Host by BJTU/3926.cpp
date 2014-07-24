#include <stdio.h>
#include <string.h>
int set1[10010],set2[10010],cycle1[10010],cycle2[10010],total1[10010],total2[10010];
int cmp1[10010][2],cmp2[10010][2];
int find1(int k)
{
	int tmp;
	if(set1[k]!=k)
	{
		tmp=set1[k];
		set1[k]=find1(set1[k]);
		cycle1[set1[k]]=(cycle1[k]|cycle1[tmp]);
	}
	return set1[k];
}
int find2(int k)
{
	int tmp;
	if(set2[k]!=k)
	{
		tmp=set2[k];
		set2[k]=find2(set2[k]);
		cycle2[set2[k]]=(cycle2[k]|cycle2[tmp]);
	}
	return set2[k];
}
int main()
{
	int i,j,t,n1,n2,m1,m2,x,y,p,q,flag;
	scanf("%d",&t);
	for(j=1;j<=t;j++)
	{
		printf("Case #%d: ",j);
		scanf("%d%d",&n1,&m1);
		memset(cycle1,0,sizeof(cycle1));
		memset(cycle2,0,sizeof(cycle2));
		memset(total1,0,sizeof(total1));
		memset(total2,0,sizeof(total2));
		memset(cmp1,0,sizeof(cmp1));
		memset(cmp2,0,sizeof(cmp2));
		for(i=1;i<=n1;i++) set1[i]=i;
		for(i=0;i<m1;i++)
		{
			scanf("%d%d",&x,&y);
			p=find1(x);
			q=find1(y);
			if(p!=q)
			{
				set1[p]=q;
				cycle1[q]=(cycle1[p]|cycle1[q]);
			}
			else cycle1[p]=1;
		}
		scanf("%d%d",&n2,&m2);
		for(i=1;i<=n2;i++) set2[i]=i;
		for(i=0;i<m2;i++)
		{
			scanf("%d%d",&x,&y);
			p=find2(x);
			q=find2(y);
			if(p!=q)
			{
				set2[p]=q;
				cycle2[q]=(cycle2[p]|cycle2[q]);
			}
			else cycle2[p]=1;
		}
		if(n1!=n2||m1!=m2)
		{
			printf("NO\n");
			continue;
		}
		for(i=1;i<=n1;i++)
		{
			p=find1(i);
			total1[p]++;
		}
		for(i=1;i<=n2;i++)
		{
			p=find2(i);
			total2[p]++;
		}
		for(i=1;i<=n1;i++)
		{
			cmp1[total1[i]][0]++;
			cmp2[total2[i]][0]++;
			if(cycle1[i])cmp1[total1[i]][1]++;
			if(cycle2[i])cmp2[total2[i]][1]++;
		}
		flag=1;
		for(i=1;i<=n1;i++)
		{
			if(cmp1[i][0]!=cmp2[i][0]||cmp1[i][1]!=cmp2[i][1])
			{
				printf("NO\n");
				flag=0;
				break;
			}
		}
		if(flag)printf("YES\n");
	}
	return 0;
}