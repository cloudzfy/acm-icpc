#include <iostream>
using namespace std;
int main()
{
	long long i,j,n,k,result,tmp;
	for(;;)
	{
		cin>>n>>k;
		if(n==0&&k==0) break;
		if(k==0)
		{
			printf("1\n");
			continue;
		}
		result=1;
		tmp=1;
		if(n-k>k) k=n-k;
		j=1;
		for(i=n;i>k;i--)
		{
			if((result*i)%j==0)
			{
				result=result*i/j;
			}
			else
			{
				result*=i;
				tmp*=j;
			}
			if(j<n-k)j++;
			else j=1;
		}
		result/=tmp;
		cout<<result<<endl;
	}
	return 0;
}
