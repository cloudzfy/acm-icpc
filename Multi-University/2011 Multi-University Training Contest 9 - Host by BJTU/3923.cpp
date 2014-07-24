#include<stdio.h>
#define MOD 1000000007
long long p[10002];
long long gcd(long long a,long long b){
	return b?gcd(b,a%b):a;
}
int main(){
	int t,i,q;
	long long count,s,c,k;
	scanf("%d",&t);
	q=0;
	for(i=1;i<=t;i++){
		q++;
		scanf("%I64d %I64d",&c,&s);
		p[0]=1;
		for(k=0;k<s;k++){
			p[k+1]=p[k]*c%(MOD*2*s);
		}
		count=(s&1)?(s*p[s/2+1]):((s/2)*(p[s/2]+p[s/2+1]));
		count%=(MOD*2*s);
		for(k=1;k<=s;k++){
			count+=p[gcd(k,s)];
			count%=(MOD*2*s);
		}
		count/=2*s;
		count%=MOD;
		printf("Case #%d: %I64d\n",q,count);
	}
	return 0;
}