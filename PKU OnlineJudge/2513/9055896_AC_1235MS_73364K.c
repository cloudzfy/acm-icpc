/* POJ 2513
 * Memory:73364K  Time:1188MS
 * Trie+并查集+欧拉通路
 * By Cloudzfy
 */

#include <stdio.h>
#include <string.h>
#include <malloc.h>
int total;
int num[500000],set[500000];
struct node
{
	int id;
	struct node* next[26];
}*head;
int addnode(char* str)
{
	struct node *p=head,*tmp;
	for(str;*str!=0;str++)
	{
		if(p->next[*str-'a']==NULL)
		{
			tmp=(struct node*)malloc(sizeof(struct node));
			memset(tmp->next,0,sizeof(tmp->next));
			tmp->id=-1;
			p->next[*str-'a']=tmp;
		}
		p=p->next[*str-'a'];
	}
	if(p->id==-1)
	{
		p->id=total++;
		num[p->id]=1;
		set[p->id]=p->id;
	}
	else
	{
		num[p->id]++;
	}
	return p->id;
}

int find(int k)
{
	if(set[k]!=k)
	{
		set[k]=find(set[k]);
	}
	return set[k];
}

int main()
{
	int p,q,root,odd,i;
	char a[11],b[11];
	head=(struct node*)malloc(sizeof(struct node));
	head->id=-1;
	memset(head->next,0,sizeof(head->next));
	total=0;
	while(scanf("%s%s",a,b)!=EOF)
	{
		p=addnode(a);
		q=addnode(b);
		p=find(p);
		q=find(q);
		if(p!=q)
		{
			set[p]=q;
		}
	}
	odd=0;
	root=0;
	for(i=0;i<total;i++)
	{
		if(num[i]%2==1)odd++;
		set[i]=find(i);
		if(set[i]==i)root++;
	}
	if(odd<=2&&root<=1)printf("Possible\n");
	else printf("Impossible\n");
	return 0;
}