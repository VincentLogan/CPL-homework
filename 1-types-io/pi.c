#include<stdio.h>
#include<math.h>
int main(){
    double pi,pi_4;
    pi=log(pow(640320,3)+744)*1.0/sqrt(163);
    pi_4=4*atan(1.0/5)-atan(1.0/239);
    printf("%.15f\n%.15f\n",pi,pi_4*4);
    return 0;
}