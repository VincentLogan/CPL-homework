#include<stdio.h>
#include<math.h>
int main(void)
{
    int p,q;
    float x1,a,b;
    scanf("%d%d",&p,&q);
    a=-1.0*q/2+sqrt(pow(q*1.0/2,2)+pow(p*1.0/3,3));
    b=-1.0*q/2-sqrt(pow(q*1.0/2,2)+pow(p*1.0/3,3));
    x1=cbrt(a)+cbrt(b);
    printf("%.3f",x1);
    return 0;
}