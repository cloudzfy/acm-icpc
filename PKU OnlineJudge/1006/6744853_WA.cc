#include <iostream>
#include <stdio.h>
using namespace std;
int main()
{
	int p,e,i,d,tmp,t=0;
	for(;;)
	{
		t++;
		scanf("%d %d %d %d",&p,&e,&i,&d);
		if(p==-1&&e==-1&&i==-1&&d==-1) break;
		if(p==0||e==0||i==0)
		{
			printf("Case %d: the next triple peak occurs in %d days.\n",t,21252-d);
			continue;
		}
		tmp=(5544*p+14421*e+1288*i-d)%(23*28*33);
		if(tmp<0) tmp=21252-tmp;
		printf("Case %d: the next triple peak occurs in %d days.\n",t,tmp);
	}
	return 0;
}