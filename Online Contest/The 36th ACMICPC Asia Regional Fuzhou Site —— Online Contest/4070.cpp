#include <stdio.h>
#include <stdlib.h>
int data[100000][2];
int cmp(const void *a,const void *b)
{
    return ((int*)b)[1]-((int*)a)[1];
}
int main()
{
    int t,T,i,N,move,result;
    scanf("%d",&T);
    for(t=1;t<=T;t++)
    {
        scanf("%d",&N);
        for(i=0;i<N;i++)
        {
            scanf("%d%d",&data[i][0],&data[i][1]);
        }
        qsort(data,N,sizeof(data[0]),cmp);
        move=0;
        result=0;
        for(i=0;i<N;i++)
        {
            move+=data[i][0];
            if(move+data[i][1]>result)
                result=move+data[i][1];
        }
        printf("Case %d: %d\n",t,result);
    }
}
