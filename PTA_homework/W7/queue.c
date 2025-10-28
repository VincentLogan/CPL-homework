#include<stdio.h>
int main()
{
    int n,queue[20005]={0},get=0,put=0,fetch[10005]={0},sum=0;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        int x;
        scanf("%d",&x);
        if(x==1)
        {
            scanf("%d",&queue[put++]);
        }
        else
        {
            if(get<put)
            {
                fetch[sum++]=queue[get++];
            }
            else
            {
                sum++;
            }
        }
    }
    for(int i=0;i<sum;i++)
    {
        if(fetch[i]!=0)
        {
            printf("%d\n",fetch[i]);
        }
        else
        {
            printf("invalid\n");
        }
    }
    return 0;
}