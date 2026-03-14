#include<stdio.h>
int main(){
    int cash;
    scanf("%d",&cash);
    int one,five,ten,twenty,fifty;
    fifty=cash/50;
    twenty=(cash-fifty*50)/20;
    ten=(cash-fifty*50-twenty*20)/10;
    five=(cash-fifty*50-twenty*20-ten*10)/5;
    one=cash-fifty*50-twenty*20-ten*10-five*5;
    printf("%d\n%d\n%d\n%d\n%d\n",fifty,twenty,ten,five,one);
    return 0;
}