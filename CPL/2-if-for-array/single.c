#include<stdio.h>
int main()
{
    int one[10005];
    int num,j;
    scanf("%d",&num);
    for(int i=0;i<num*2-1;i++)
    {
        scanf("%d",&one[i]);
    }
    for(int b=0;b<num*2-1;b++)
    {
        for(int a=0;a<=num*2-1;a++)
        {
            if(one[b]-one[a]==0&&b!=a)
            {
                break;
            }
            if(a==num*2-2&&one[b]-one[a]!=0)
            {
                printf("%d",one[b]);
                return 0;
            }
        }
    }
}