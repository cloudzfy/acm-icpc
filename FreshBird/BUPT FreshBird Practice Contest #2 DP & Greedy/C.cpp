#include <iostream>
using namespace std;
int main()
{
	int n,result,i;
	double data,device;
	while(cin>>n)
	{
		cin>>data;
		device=data;
		result=1;
		for(i=1;i<n;i++)
		{
			cin>>data;
			if(device+1<=data)
			{
				result++;
				device=data;
			}
		}
		cout<<result<<endl;
	}
	return 0;
}