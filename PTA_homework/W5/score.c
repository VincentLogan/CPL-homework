#include<stdio.h>
int main()
{
    int a[10],n;
    for(int i=0;i<10;i++)
    {
        scanf("%d",&a[i]);
    }
    scanf("%d",&n);
    int b[n];
    for(int i=0;i<n;i++)
    {
        scanf("%d",&b[i]);
        a[b[i]-1]+=10;
    } 
    for(int i=0;i<10;i++)
    {
        printf("%d ",a[i]);
    }
    return 0;
}