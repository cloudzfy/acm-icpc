#include <stdio.h>
#include <string.h>

int main()
{
	int size=0;
	char word[81];
	while(scanf("%s",word)!=EOF)
	{
		if(strcmp("<br>",word)==0)
		{
			printf("\n");
			size=0;
		}
		else if(strcmp("<hr>",word)==0)
		{
			if(size!=0) printf("\n");
			printf("--------------------------------------------------------------------------------\n");
			size=0;
		}
		else
		{
			if(size!=0)
			{
				if(strlen(word)+size<=79)
				{
					printf(" %s",word);
					size+=(strlen(word)+1);
				}
				else
				{
					printf("\n%s",word);
					size=strlen(word);
				}
			}
			else
			{
				printf("%s",word);
				size=strlen(word);
			}
		}
	}
	printf("\n");
	return 0;
}