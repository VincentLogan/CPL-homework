#include<stdio.h>
#include<math.h>
int main(){
    char month[20],weekday[20];
    int year,day,minute,hour,second;
    scanf("%s%d%d%s%d%d%d",month,&day,&year,weekday,&hour,&minute,&second);
    printf("%.3s %.3s %d %.2d:%.2d:%.2d %.4d",weekday,month,day,hour,minute,second,year);
    return 0;
}