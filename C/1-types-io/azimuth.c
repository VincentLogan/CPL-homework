#include<stdio.h>
#include<math.h>
int main()
{
    int Xa,Ya,Xb,Yb;
    double dis=0,d=0,pi=acos(-1);
    scanf("%d %d %d %d",&Xa,&Ya,&Xb,&Yb);
    dis=sqrt(pow(Xa-Xb,2)+pow(Ya-Yb,2));
    Xb=Xb-Xa;
    Yb=Yb-Ya;
    d=atan2(Xb,Yb)/acos(-1)*180;
    d=fmod(d+360,360);
    printf("%.4f %.4f",dis,d);
    return 0;
}