#include <stdio.h>
#include <string.h>
int main()
{
	int t;
	char time1[20],time2[22];
	scanf("%d",&t);
	while(t--)
	{
		scanf("%s",time1);
		time2[0]=time1[5];
		time2[1]=time1[6];
		time2[2]=time1[7];
		time2[3]=time1[8];
		time2[4]=time1[9];
		time2[5]=time1[4];
		time2[6]=time1[0];
		time2[7]=time1[1];
		time2[8]=time1[2];
		time2[9]=time1[3];
		time2[10]=time1[10];
		time2[13]=time1[13];
		time2[14]=time1[14];
		time2[15]=time1[15];
		time2[16]=time1[16];
		time2[17]=time1[17];
		time2[18]=time1[18];
		time2[20]='m';
		if((time1[11]-'0')*10+(time1[12]-'0')>11&&(time1[11]-'0')*10+(time1[12]-'0')<24)
		{
			time2[19]='p';
			if((time1[11]-'0')*10+(time1[12]-'0')==12)
			{
				time2[11]='1';
				time2[12]='2';
			}
			else
			{
				time2[11]=time1[11]-1;
				time2[12]=time1[12]-2;
			}
		}
		else
		{
			time2[19]='a';
			if((time1[11]-'0')*10+(time1[12]-'0')==24||(time1[11]-'0')*10+(time1[12]-'0')==0)
			{
				time2[11]='1';
				time2[12]='2';
			}
			else
			{
				time2[11]=time1[11];
				time2[12]=time1[12];
			}
		}
		time2[21]=0;
		printf("%s\n",time2);
	}
	return 0;
}