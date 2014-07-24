#include <stdio.h>
#include <stdlib.h>
int tape[200000][2];
int cmp(const void *a,const void *b)
{
	if(((int *)a)[0]==((int *)b)[0])
		return ((int *)a)[1]-((int *)b)[1];
	return ((int *)a)[0]-((int *)b)[0];
}
int main()
{
	int result,l,n1,n2,i,start,mark;
	while(scanf("%d%d%d",&l,&n1,&n2)!=EOF)
	{
		for(i=0;i<n1;i++)
		{
			scanf("%d%d",&tape[i][0],&tape[i][1]);
		}
		for(i=n1;i<n1+n2;i++)
		{
			scanf("%d%d",&tape[i][0],&tape[i][1]);
		}
		qsort(tape,n1+n2,sizeof(tape[0]),cmp);
		result=0;
		start=tape[0][0];
		mark=-1;
		for(i=0;i<n1+n2;i++)
		{
			if(mark>=tape[i][0])
				start=mark+1;
			if(i==n1+n2-1)
			{
				if(result<tape[i][1]-start+1)
					result=tape[i][1]-start+1;
			}
			else if(tape[i][1]+1==tape[i+1][0])
				continue;
			else if(tape[i][1]+1<tape[i+1][0])
			{
				if(result<tape[i][1]-start+1)
					result=tape[i][1]-start+1;
				start=tape[i+1][0];
			}
			else if(tape[i][1]+1>tape[i+1][0]&&tape[i][1]<tape[i+1][1])
			{
				if(result<tape[i+1][0]-start)
					result=tape[i+1][0]-start;
				if(start<tape[i][1]+1)
					start=tape[i][1]+1;
			}
			else if(tape[i][1]+1>tape[i+1][0]&&tape[i][1]>=tape[i+1][1])
			{
				if(result<tape[i+1][0]-start)
					result=tape[i+1][0]-start;
				if(start<tape[i+1][1]+1)
					start=tape[i+1][1]+1;
			}
			if(mark<tape[i][1])
				mark=tape[i][1];
		}
		printf("%d\n",result);
	}
	return 0;
}