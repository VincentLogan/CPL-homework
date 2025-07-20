#include<stdio.h>
#include<math.h>
int main(void)
{
    const double M=77.15,G=6.674e-11;
    double R,m;
    double F;
    scanf("%lf%lf",&m,&R);
    F=G*M*m/pow(R,2);
    printf("%.3e",F);
    return 0;
}