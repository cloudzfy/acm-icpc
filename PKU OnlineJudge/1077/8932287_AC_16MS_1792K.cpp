/*
 * Hash + A* + 曼哈顿距离
 * 经典：八数码
 * 理解：A*实际上是将BFS中的队列维护成一个优先队列。进而求解。
 */

#include <stdio.h>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
int schedule[362880];
char result[362880];
int pos[9],post[9],finish=0,total=0;
int num[9]={1,1,2,6,24,120,720,5040,40320};

int pack(int *a)
{
	int count,result=0,p[10]={0},i,j;
	for(i=0;i<9;i++)
	{
		count=0;
		for(j=1;j<a[i];j++)
		{
			if(p[j]==0) count++;
		}
		p[a[i]]=1;
		result+=count*num[8-i];
	}
	return result;
}

void unpack(int s,int *a)
{
	int i,p[10]={0},j,temp,count;
	for(i=0;i<9;i++)
	{
		temp=s/num[8-i]+1;
		s=s%num[8-i];
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

struct cmp{
	bool operator() (int a,int b)
	{
		int posa[9],posb[9],resulta=0,resultb=0,i;
		unpack(a,posa);
		unpack(b,posb);
		for(i=0;i<9;i++)
		{
			resulta+=abs(post[posa[i]]%3-i%3)+abs(post[posa[i]]/3-i/3);
			resultb+=abs(post[posb[i]]%3-i%3)+abs(post[posb[i]]/3-i/3);
		}
        return resulta>resultb;
	}
};

priority_queue<int,vector<int>,cmp> q;

void swap(int *a,int *b)
{
	int temp;
	temp=*a;
	*a=*b;
	*b=temp;
}

void bfs()
{
	int temp[9],destination,i,cur,x;
	for(i=0;i<362800;i++)
	{
		schedule[i]=-1;
	}
	destination=pack(pos);
	q.push(0);
	while(!q.empty())
	{
		cur=q.top();
		q.pop();
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
				q.push(x);
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
				q.push(x);
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
				q.push(x);
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
				q.push(x);
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
	char op[2];
	for(i=0;i<9;i++)
	{
		scanf("%s",op);
		if(op[0]=='x')
		{
			pos[i]=9;
			mark=i;
		}
		else pos[i]=op[0]-'0';
		post[pos[i]]=i;
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