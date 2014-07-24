/* HDOJ 2222
 * AC×Ô¶¯»ú
 */
#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <algorithm>
#include <queue>
using namespace std;
char keyword[51],description[1000001];
int total;
struct Trie
{
	Trie *fail,*next[26];
	int end;
	Trie()
	{
		fail=NULL;
		end=0;
		memset(next,0,sizeof(next));
	}
};
void insert(char *str,struct Trie *root)
{
	struct Trie *p=root;
	int index;
	while(*str)
	{
		index=*str-'a';
		if(p->next[index]==NULL)
		{
			p->next[index]=(struct Trie*)malloc(sizeof(struct Trie));
			p=p->next[index];
			p->fail=NULL;
			p->end=0;
			memset(p->next,0,sizeof(p->next));
		}
		else p=p->next[index];
		str++;
	}
	p->end++;
}
void Build_AC_automation(struct Trie *root)
{
	int i;
	struct Trie *cur,*p;
	queue<struct Trie*> q;
	root->fail=NULL;
	q.push(root);
	while(!q.empty())
	{
		cur=q.front();
		q.pop();
		for(i=0;i<26;i++)
		{
			if(cur->next[i]!=NULL)
			{
				if(cur==root)cur->next[i]->fail=root;
				else
				{
					p=cur->fail;
					while(p!=NULL)
					{
						if(p->next[i]!=NULL)
						{
							cur->next[i]->fail=p->next[i];
							break;
						}
						p=p->fail;
					}
					if(p==NULL)cur->next[i]->fail=root;
				}
				q.push(cur->next[i]);
			}
		}
	}
}
int query(struct Trie *root,char *str)
{
	struct Trie *p=root,*tmp;
	int result=0,index;
	while(*str)
	{
		index=*str-'a';
		while(p->next[index]==NULL&&p!=root) p=p->fail;
		p=p->next[index];
		if(p==NULL)p=root;
		tmp=p;
		while(tmp!=root&&tmp->end!=-1)
		{
			result+=tmp->end;
			tmp->end=-1;
			tmp=tmp->fail;
		}
		str++;
	}
	return result;
}
int main()
{
	int T,N,result,i;
	struct Trie *root;
	scanf("%d",&T);
	while(T--)
	{
		root=(struct Trie*)malloc(sizeof(struct Trie));
		root->fail=NULL;
		root->end=0;
		memset(root->next,0,sizeof(root->next));
		scanf("%d",&N);
		total=1;
		result=0;
		for(i=0;i<N;i++)
		{
			scanf("%s",keyword);
			insert(keyword,root);
		}
		Build_AC_automation(root);
		scanf("%s",description);
		result=query(root,description);
		printf("%d\n",result);
	}
	return 0;
}