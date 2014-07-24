#include <iostream>
#include <stdio.h>
using namespace std;
int main()
{
	int p,e,i,d,tmp,t=0;
	while(scanf("%d %d %d %d",&p,&e,&i,&d)!=EOF)
	{
		t++;
		if(p==-1&&e==-1&&i==-1&&d==-1) break;
		tmp=(5544*p+14421*e+1288*i-d)%(23*28*33);
		if(tmp<=0) tmp=21252-tmp;
		printf("Case %d: the next triple peak occurs in %d days.\n",t,tmp);
	}
	return 0;
}