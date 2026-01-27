#include<stdio.h>
int main()
{
    int m,n,a,x,y;
    scanf("%d/%d",&m,&n);
    x=m;
    y=n;
    while(y)
    {
        a=x%y;
        x=y;
        y=a;
    }
    m=m/x;
    n=n/x;
    printf("%d/%d",m,n);
}