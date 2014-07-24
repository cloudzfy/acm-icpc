#include <iostream>
#include <cstring>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
priority_queue<int,vector<int>,greater<int>> minHeap;
priority_queue<int,vector<int>,less<int>> maxHeap;

int a[30000],u[30000];
int main()
{
	int m,n,i,j,tmp;
	scanf("%d%d",&m,&n);
	for(i=0;i<m;i++)
	{
		scanf("%d",&a[i]);
	}
	for(j=0;j<n;j++)
	{
		scanf("%d",&u[j]);
	}
	j=0;
	for(i=0;i<m;i++)
	{
		maxHeap.push(a[i]);
		while(maxHeap.size()>j)
		{
			tmp=maxHeap.top();
			maxHeap.pop();
			minHeap.push(tmp);
		}
		while(u[j]==i+1&&j<n)
		{
			tmp=minHeap.top();
			minHeap.pop();
			maxHeap.push(tmp);
			printf("%d\n",tmp);
			j++;
		}
	}
	return 0;
}