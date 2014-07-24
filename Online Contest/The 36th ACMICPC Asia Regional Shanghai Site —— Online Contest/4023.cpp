#include <stdio.h>
int num[15];
int main()
{
	int t,T,total,i,turn,bob,alice;
	scanf("%d",&T);
	for(t=1;t<=T;t++)
	{
		total=0;
		for(i=0;i<15;i++)
		{
			scanf("%d",&num[i]);
			total+=num[i];
		}
		turn=0;
		bob=0;
		alice=0;
		for(i=0;i<total;i++)
		{
			if(turn==0)
			{
				if(num[14])
				{
					num[14]--;
					alice+=2;
				}
				else if(num[4])
				{
					num[4]--;
					alice+=2;
				}
				else if(num[5])
				{
					num[5]--;
					alice+=2;
				}
				else if(num[2])
				{
					num[2]--;
					alice++;
				}
				else if(num[3])
				{
					num[3]--;
					alice++;
				}
				else if(num[10])
				{
					num[10]--;
					alice++;
				}
				else if(num[11])
				{
					num[11]--;
					alice++;
				}
				else if(num[12])
				{
					num[12]--;
					alice++;
				}
				else if(num[13])
				{
					num[13]--;
					alice++;
				}
				else if(num[6])
				{
					num[6]--;
					alice++;
				}
				else if(num[7])
				{
					num[7]--;
					alice++;
				}
				else if(num[8])
				{
					num[8]--;
					alice++;
					bob++;
				}
				else if(num[9])
				{
					num[9]--;
					alice++;
					bob++;
				}
				else if(num[0])
				{
					num[0]--;
					alice+=2;
				}
				else i--;
			}
			else
			{
				if(num[14])
				{
					num[14]--;
					bob+=2;
				}
				else if(num[2])
				{
					num[2]--;
					bob+=2;
				}
				else if(num[3])
				{
					num[3]--;
					bob+=2;
				}
				else if(num[4])
				{
					num[4]--;
					bob++;
				}
				else if(num[5])
				{
					num[5]--;
					bob++;
				}
				else if(num[10])
				{
					num[10]--;
					bob++;
				}
				else if(num[11])
				{
					num[11]--;
					bob++;
				}
				else if(num[12])
				{
					num[12]--;
					bob++;
				}
				else if(num[13])
				{
					num[13]--;
					bob++;
				}
				else if(num[8])
				{
					num[8]--;
					bob++;
				}
				else if(num[9])
				{
					num[9]--;
					bob++;
				}
				else if(num[6])
				{
					num[6]--;
					bob++;
					alice++;
				}
				else if(num[7])
				{
					num[7]--;
					bob++;
					alice++;
				}
				else if(num[1])
				{
					num[1]--;
					bob+=2;
				}
				else i--;
			}
			turn=(turn+1)%2;
		}
		printf("Case #%d: ",t);
		if(bob<alice)printf("Alice\n");
		else printf("Bob\n");
	}
	return 0;
}