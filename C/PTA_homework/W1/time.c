#include<stdio.h>
int main(){
    int hour1,min1,hour2,min2,cha_hour,cha_min;
    scanf("%d %d %d %d",&hour1,&min1,&hour2,&min2);
    cha_hour=hour2-hour1;
    cha_min=min2-min1;
    if(cha_min<0)
    {
        cha_hour--;
        cha_min=60+cha_min;
    }
    printf("%d %d",cha_hour,cha_min);
    return 0;
}
