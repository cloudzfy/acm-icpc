#include <stdio.h>
#include <string.h>
int main()
{
	int i;
	char m[201],p[27];
	strcpy(p,"VWXYZABCDEFGHIJKLMNOPQRSTU");
	for(;;)
	{
		scanf("%s",m);
		if(strcmp(m,"START")==0)
		{
			getchar();
			for(;;)
			{
				gets(m);
				if(strcmp(m,"END")==0) break;
				for(i=0;m[i]!=0;i++)
				{
					if(m[i]<'A'||m[i]>'Z') continue;
					m[i]=p[m[i]-'A'];
				}
				printf("%s\n",m);
			}
		}
		else if(strcmp(m,"ENDOFINPUT")==0) break;
	}
	return 0;
}