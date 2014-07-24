#include <stdio.h>
int n,m;
struct node
{
	int up,down,left,right,direction;
}map[5000],backup[5000];
int search(int k)
{
	int result=0,pos=k,direction;
	while(k!=-1)
	{
		result++;
		if(map[k].direction!=-1)direction=map[k].direction;
		if(map[k].direction==0) pos=map[k].right;
		else if(map[k].direction==1) pos=map[k].down;
		else if(map[k].direction==2) pos=map[k].left;
		else if(map[k].direction==3) pos=map[k].up;
		else
		{
			if(direction==0&&map[pos].right!=-1) pos=map[pos].right;
			else if(direction==1&&map[pos].down!=-1) pos=map[pos].down;
			else if(direction==2&&map[pos].left!=-1) pos=map[pos].left;
			else if(direction==3&&map[pos].up!=-1) pos=map[pos].up;
			else pos=-1;
			result--;
		}
		if(map[k].up!=-1)map[map[k].up].down=map[k].down;
		if(map[k].down!=-1)map[map[k].down].up=map[k].up;
		if(map[k].left!=-1)map[map[k].left].right=map[k].right;
		if(map[k].right!=-1)map[map[k].right].left=map[k].left;
		k=pos;
	}
	return result;
}

int main()
{
	int i,j,ans,result,total;
	char str[5001];
	scanf("%d%d",&n,&m);
	result=0;
	for(i=0;i<n;i++)
	{
		scanf("%s",str);
		for(j=0;str[j]!=0;j++)
		{
			if(str[j]=='U') map[i*m+j].direction=3;
			else if(str[j]=='D') map[i*m+j].direction=1;
			else if(str[j]=='L') map[i*m+j].direction=2;
			else if(str[j]=='R') map[i*m+j].direction=0;
			else map[i*m+j].direction=-1;
			if(j>0) map[i*m+j].left=i*m+j-1;
			else map[i*m+j].left=-1;
			if(str[j+1]!=0) map[i*m+j].right=i*m+j+1;
			else map[i*m+j].right=-1;
			if(i>0) map[i*m+j].up=(i-1)*m+j;
			else map[i*m+j].up=-1;
			if(i<n-1) map[i*m+j].down=(i+1)*m+j;
			else map[i*m+j].down=-1;
		}
	}
	for(j=0;j<n*m;j++)
	{
		backup[j].direction=map[j].direction;
		backup[j].up=map[j].up;
		backup[j].down=map[j].down;
		backup[j].left=map[j].left;
		backup[j].right=map[j].right;
	}
	for(i=0;i<n*m;i++)
	{
		if(map[i].direction==-1) continue;
		for(j=0;j<n*m;j++)
		{
			map[j].direction=backup[j].direction;
			map[j].up=backup[j].up;
			map[j].down=backup[j].down;
			map[j].left=backup[j].left;
			map[j].right=backup[j].right;
		}
		ans=search(i);
		if(ans>result)
		{
			result=ans;
			total=1;
		}
		else if(ans==result) total++;
	}
	printf("%d %d\n",result,total);
	return 0;
}