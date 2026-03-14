#include<stdio.h>
#include<math.h>
int main()
{
    int year,month,day;
    scanf("%d%d%d",&year,&month,&day);
    double a,y,m;
    int JDN;
    a=floor((14-month)*1.0/12);
    y=(year+4800-a)*1.0;
    m=month+12*a-3;
    JDN=day+floor((153*m+2)*1.0/5)+365*y+floor(y/4)-floor(y/100)+floor(y/400)-32045;
    printf("%.d\n",JDN);
    return 0;
}
