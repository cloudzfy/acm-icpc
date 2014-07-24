#include <stdio.h>
#include <string.h>
int main()
{
    int i,n,j,k,l=0,a,nsth[13],judge[3],left,right;
    char thing[13][2][3],tmp1[13],tmp2[13],tmp[5];
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        for(a=0;a<3;a++)
        {
            scanf("%s %s %s",tmp1,tmp2,tmp);
            for(j=0;tmp1[j]!=0;j++)
            {
                thing[j][0][a]=tmp1[j];
                thing[j][1][a]=tmp2[j];
            }
            thing[j][0][a]=0;
            thing[j][1][a]=0;
            if(strcmp(tmp,"even")==0) judge[a]=1;
            else if(strcmp(tmp,"up")==0) judge[a]=2;
            else judge[a]=0;
        }
        for(a=0;a<12;a++)
        {
            nsth[a]=1;
        }
        for(j=0;j<12;j++)
        {
            nsth[j]=0;
            for(a=0;a<3;a++)
            {
                left=0;
                right=0;
                for(k=0;thing[k][0][a]!=0;k++)
                {
                    left=left+nsth[thing[k][0][a]-'A'];
                }
                for(k=0;thing[k][1][a]!=0;k++)
                {
                    right=right+nsth[thing[k][1][a]-'A'];
                }
                if(judge[a]==1&&left==right)
                {
                    l=1;
                }
                else if(judge[a]==2&&left<right)
                {
                    l=1;
                }
                else if(judge[a]==0&&left>right)
                {
                    l=1;
                }
                else
                {
                    l=0;
                    break;
                }
            }
            if(l==1) break;
            nsth[j]=2;
            for(a=0;a<3;a++)
            {
                left=0;
                right=0;
                for(k=0;thing[k][0][a]!=0;k++)
                {
                    left=left+nsth[thing[k][0][a]-'A'];
                }
                for(k=0;thing[k][1][a]!=0;k++)
                {
                    right=right+nsth[thing[k][1][a]-'A'];
                }
                if(judge[a]==1&&left==right)
                {
                    l=1;
                }
                else if(judge[a]==2&&left<right)
                {
                    l=1;
                }
                else if(judge[a]==0&&left>right)
                {
                    l=1;
                }
                else
                {
                    l=0;
                    break;
                }
            }
            if(l==1) break;
            nsth[j]=1;
        }
        printf("%c is the counterfeit coin and it is ",'A'+j);
        if(nsth[j]==2) printf("light.\n");
        else printf("heavy.\n");
    }
    return 0;
}