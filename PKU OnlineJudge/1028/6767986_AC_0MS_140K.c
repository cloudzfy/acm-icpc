#include <stdio.h>
#include <string.h>
int main()
{
	char op[8],team[101][71];
	int i=0;
	strcpy(team[0],"http://www.acm.org/");
	team[1][0]=0;
	for(;;)
	{
		scanf("%s",op);
		if(strcmp(op,"QUIT")==0) break;
		if(strcmp(op,"VISIT")==0)
		{
			i++;
			scanf(" %s",team[i]);
			printf("%s\n",team[i]);
			team[i+1][0]=0;
		}
		if(strcmp(op,"BACK")==0)
		{
			if(i==0)
			{
				printf("Ignored\n");
				continue;
			}
			i--;
			printf("%s\n",team[i]);
		}
		if(strcmp(op,"FORWARD")==0)
		{
			if(team[i+1][0]==0)
			{
				printf("Ignored\n");
				continue;
			}
			i++;
			printf("%s\n",team[i]);
		}
	}
	return 0;
}