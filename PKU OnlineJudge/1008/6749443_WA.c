#include <stdio.h>
#include <string.h>
int main()
{
	int i,n;
	long int day,year;
	char month[7];
	scanf("%d",&n);
	printf("%d\n",n);
	for(i=0;i<n;i++)
	{
		scanf("%d. %s %d",&day,month,&year);
		if(strcmp(month,"no")==0) day+=20;
		else if(strcmp(month,"zip")==0) day+=40;
		else if(strcmp(month,"zotz")==0) day+=60;
		else if(strcmp(month,"tzec")==0) day+=80;
		else if(strcmp(month,"xul")==0) day+=100;
		else if(strcmp(month,"yoxkin")==0) day+=120;
		else if(strcmp(month,"mol")==0) day+=140;
		else if(strcmp(month,"chen")==0) day+=160;
		else if(strcmp(month,"yax")==0) day+=180;
		else if(strcmp(month,"zac")==0) day+=200;
		else if(strcmp(month,"ceh")==0) day+=220;
		else if(strcmp(month,"mac")==0) day+=240;
		else if(strcmp(month,"kankin")==0) day+=260;
		else if(strcmp(month,"muan")==0) day+=280;
		else if(strcmp(month,"pax")==0) day+=300;
		else if(strcmp(month,"koyab")==0) day+=320;
		else if(strcmp(month,"cumhu")==0) day+=340;
		else if(strcmp(month,"uayet")==0) day+=360;
		day++;
		day+=365*year;
		year=day/260;
		if(day%20==1) strcpy(month,"imix");
		else if(day%20==2) strcpy(month,"ik");
		else if(day%20==3) strcpy(month,"akbal");
		else if(day%20==4) strcpy(month,"kan");
		else if(day%20==5) strcpy(month,"chicchan");
		else if(day%20==6) strcpy(month,"cimi");
		else if(day%20==7) strcpy(month,"manik");
		else if(day%20==8) strcpy(month,"lamat");
		else if(day%20==9) strcpy(month,"muluk");
		else if(day%20==10) strcpy(month,"ok");
		else if(day%20==11) strcpy(month,"chuen");
		else if(day%20==12) strcpy(month,"eb");
		else if(day%20==13) strcpy(month,"ben");
		else if(day%20==14) strcpy(month,"ix");
		else if(day%20==15) strcpy(month,"mem");
		else if(day%20==16) strcpy(month,"cib");
		else if(day%20==17) strcpy(month,"caban");
		else if(day%20==18) strcpy(month,"eznab");
		else if(day%20==19) strcpy(month,"canac");
		else if(day%20==0) strcpy(month,"ahau");
		day=day%13;
		if(day==0) day=13;
		printf("%d %s %d\n",day,month,year);
	}
	return 0;
}