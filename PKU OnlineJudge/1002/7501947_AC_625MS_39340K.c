#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int num[10000000];

int main()
{
	char str[41],x[9];
	long int n,i,j,k,b=0;
	scanf("%d",&n);
	memset(num,0,10000000);
	for(i=0;i<n;i++)
	{
		scanf("%s",str);
		k=0;
		for(j=0;j<strlen(str);j++)
		{
			if(str[j]=='A'||str[j]=='B'||str[j]=='C'||str[j]=='2') x[k]=2;
			else if(str[j]=='D'||str[j]=='E'||str[j]=='F'||str[j]=='3') x[k]=3;
			else if(str[j]=='G'||str[j]=='H'||str[j]=='I'||str[j]=='4') x[k]=4;
			else if(str[j]=='J'||str[j]=='K'||str[j]=='L'||str[j]=='5') x[k]=5;
			else if(str[j]=='M'||str[j]=='N'||str[j]=='O'||str[j]=='6') x[k]=6;
			else if(str[j]=='P'||str[j]=='R'||str[j]=='S'||str[j]=='7') x[k]=7;
			else if(str[j]=='T'||str[j]=='U'||str[j]=='V'||str[j]=='8') x[k]=8;
			else if(str[j]=='W'||str[j]=='X'||str[j]=='Y'||str[j]=='9') x[k]=9;
			else if(str[j]=='0') x[k]=0;
			else if(str[j]=='1') x[k]=1;
			else continue;
			k++;
		}
		num[1000000*x[0]+100000*x[1]+10000*x[2]+1000*x[3]+100*x[4]+10*x[5]+x[6]]++;
	}
	x[8]=0;
	x[3]='-';
	for(j=0;j<10000000;j++)
	{
		if(num[j]>1)
		{
			i=j;
			x[0]=i/1000000+'0';
			i=i%1000000;
			x[1]=i/100000+'0';
			i=i%100000;
			x[2]=i/10000+'0';
			i=i%10000;
			x[4]=i/1000+'0';
			i=i%1000;
			x[5]=i/100+'0';
			i=i%100;
			x[6]=i/10+'0';
			i=i%10;
			x[7]=i+'0';
			printf("%s %d\n",x,num[j]);
			b=1;
		}
	}
	if(b==0) printf("No duplicates.\n");
	return 0;
}