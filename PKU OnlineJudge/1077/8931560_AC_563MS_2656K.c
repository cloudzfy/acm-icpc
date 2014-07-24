/*
 * Hash + BFS
 * 经典：八数码
 */

#include <stdio.h>
int schedule[362880],queue[362880];
char result[362880];
int pos[9],finish=0,total=0;
int pack(int *a)
{
	int count,result=0,p[10]={0},num=1,i,j;
	for(i=1;i<9;i++)
	{
		num*=i;
	}
	for(i=0;i<9;i++)
	{
		count=0;
		for(j=1;j<a[i];j++)
		{
			if(p[j]==0) count++;
		}
		p[a[i]]=1;
		result+=count*num;
		if(8>i)num/=(8-i);
	}
	return result;
}

void unpack(int s,int *a)
{
	int num=1,i,p[10]={0},j,temp,count;
	for(i=1;i<9;i++)
	{
		num*=i;
	}
	for(i=0;i<9;i++)
	{
		temp=s/num+1;
		s=s%num;
		if(8>i)num/=(8-i);
		count=0;
		for(j=1;j<10;j++)
		{
			if(p[j]==0)count++;
			if(count==temp) break;
		}
		p[j]=1;
		a[i]=j;
	}
}

void swap(int *a,int *b)
{
	int temp;
	temp=*a;
	*a=*b;
	*b=temp;
}

void bfs()
{
	int pre=0,now=0,temp[9],destination,i,cur,x;
	for(i=0;i<362800;i++)
	{
		schedule[i]=-1;
	}
	destination=pack(pos);
	queue[now++]=0;
	while(now!=pre)
	{
		cur=queue[(pre++)%362880];
		unpack(cur,temp);
		for(i=0;i<9;i++)
		{
			if(temp[i]==9) break;
		}
		if(i>2)
		{
			swap(&temp[i-3],&temp[i]);
			x=pack(temp);
			if(schedule[x]==-1)
			{
				queue[(now++)%362880]=x;
				schedule[x]=cur;
				result[x]='d';
			}
			if(x==destination)
			{
				finish=1;
				return;
			}
			swap(&temp[i-3],&temp[i]);
		}
		if(i<6)
		{
			swap(&temp[i+3],&temp[i]);
			x=pack(temp);
			if(schedule[x]==-1)
			{
				queue[(now++)%362880]=x;
				schedule[x]=cur;
				result[x]='u';
			}
			if(x==destination)
			{
				finish=1;
				return;
			}
			swap(&temp[i+3],&temp[i]);
		}
		if(i%3>0)
		{
			swap(&temp[i-1],&temp[i]);
			x=pack(temp);
			if(schedule[x]==-1)
			{
				queue[(now++)%362880]=x;
				schedule[x]=cur;
				result[x]='r';
			}
			if(x==destination)
			{
				finish=1;
				return;
			}
			swap(&temp[i-1],&temp[i]);
		}
		if(i%3<2)
		{
			swap(&temp[i+1],&temp[i]);
			x=pack(temp);
			if(schedule[x]==-1)
			{
				queue[(now++)%362880]=x;
				schedule[x]=cur;
				result[x]='l';
			}
			if(x==destination)
			{
				finish=1;
				return;
			}
			swap(&temp[i+1],&temp[i]);
		}
	}
}
int main()
{
	int mark,i,x;
	char num[2];
	for(i=0;i<9;i++)
	{
		scanf("%s",num);
		if(num[0]=='x')
		{
			pos[i]=9;
			mark=i;
		}
		else pos[i]=num[0]-'0';
	}
	bfs();
	if(finish==0)printf("unsolvable\n");
	else
	{
		x=pack(pos);
		while(x!=0)
		{
			printf("%c",result[x]);
			x=schedule[x];
		}
		printf("\n");
	}
	return 0;
}