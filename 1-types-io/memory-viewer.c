#include<stdio.h>
int main()
{
    unsigned int addr,data;
    char da[10];
    scanf("%u %u",&addr,&data);
    printf("0x%.8x: ",addr);
    sprintf(da,"%.8x",data);
    for(int i=0;i<8;i+=2)
    {
        printf("%.2s ",da+i);
    }
    return 0; 
}