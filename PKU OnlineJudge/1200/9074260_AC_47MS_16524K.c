/* POJ 1200
 * 特别简单的一道Hash
 * 认真看题即可
 */
#include <stdio.h>
#include <string.h>
char str[16000001];
char hash[16000000];
int main()
{
	int x[26],total;
	int n,nc,i,j,key,pow,result;
	memset(hash,0,sizeof(hash));
	memset(x,-1,sizeof(x));
	scanf("%d%d",&n,&nc);
	scanf("%s",str);
	result=0;
	total=0;
	for(i=n-1;str[i]!=0;i++)
	{
		key=0;
		pow=1;
		for(j=i;j>i-n;j--)
		{
			if(x[str[j]-'a']==-1)x[str[j]-'a']=total++;
			key+=(x[str[j]-'a'])*pow;
			pow*=nc;
		}
		if(!hash[key])
		{
			hash[key]=1;
			result++;
		}
	}
	printf("%d\n",result);
	return 0;
}