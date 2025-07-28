#include<stdio.h>
int main()
{
    int n,num=1;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        for(int a=0;a<=n-i;a++)
        {
            printf("%.2d",num);
            num++;
        }
        printf("\n");
    }
    return 0;
}