#include<stdio.h>
int main()
{
    int max=0,huan=0;
    do{
        scanf("%d",&huan);
        if(huan>max)
        {
            max=huan;
        }
    }while(huan>=0);
    printf("%d",max);
    return 0;
}