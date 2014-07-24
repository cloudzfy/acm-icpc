#include <stdio.h>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;
priority_queue<int,vector<int>,greater<int> > minHeap;
int main()
{
	int N,K,num,result;
	char op[2];
	while(scanf("%d%d",&N,&K)!=EOF)
	{
		while(N--)
		{
			scanf("%s",op);
			if(op[0]=='I')
			{
				scanf("%d",&num);
				minHeap.push(num);
				while((int)minHeap.size()>K)
					minHeap.pop();
			}
			if(op[0]=='Q')
			{
				result=minHeap.top();
				printf("%d\n",result);
			}
		}
		while(!minHeap.empty())
			minHeap.pop();
	}
	return 0;
}