#include<stdio.h>
int main()
{
    long int number,binary=1;
    int count=0;
    scanf("%d",&number);
    if(number<0)
    {
        printf("0");
        return 0;
    }
    while(number>=binary)
    {
        count++;
        binary=binary*2;
    }
    printf("%d\n",32-count);
    return 0;
}