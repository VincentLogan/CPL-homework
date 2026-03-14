#include<stdio.h>
int main()
{
    int a[8];
    for(int i=0;i<3;i++)
    {
        scanf("%d",&a[5+i]);
    }
    for(int i=0;i<5;i++)
    {
        scanf("%d",&a[i]);
    }
    for(int i=0;i<8;i++)
    {
        printf("%3d",a[i]);
    }
    return 0;
}