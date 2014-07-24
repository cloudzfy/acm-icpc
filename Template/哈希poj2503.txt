#include <stdio.h>
#include <string.h>
struct dict
{
	char a[11],b[11];
	struct dict *next;
};
struct dict *ptr[1000000],*p,d[100000];
int hash(char *str)
{
	int h;
	for(h=0;*str;str++)
	{
		h=3*h+(*str-'a');
	}
	return h;
}
int main()
{
	char str[22];
	int num=0,x,i;
	memset(ptr,0,sizeof(ptr));
	while(gets(str)&&str[0]!=0)
	{
		memset(d[num].b,0,sizeof(d[num].b));
		sscanf(str,"%s%s",d[num].a,d[num].b);
		x=hash(d[num].b);
		if(ptr[x]==NULL)
		{
			ptr[x]=&d[num];
			num++;
			continue;
		}
		p=ptr[x];
		while(p!=NULL&&p->next!=NULL) p=p->next;
		p->next=&d[num];
		d[num].next=NULL;
		num++;
	}
	while(scanf("%s",str)!=EOF)
	{
		x=hash(str);
		p=ptr[x];
		if(p==NULL)
		{
			printf("eh\n");
			continue;
		}
		if(strcmp(str,p->b)==0)
		{
			printf("%s\n",p->a);
			continue;
		}
		while(p->next!=NULL)
		{
			if(strcmp(str,p->b)==0) break;
			p=p->next;
		}
		if(strcmp(str,p->b)==0) printf("%s\n",p->a);
		else printf("eh\n");
	}
	return 0;
}