#include <stdio.h>

int TopDigit(int number);

int main()
{
    int n;
    scanf("%d", &n);
    printf("%d\n", TopDigit(n));
    return 0;
}

int TopDigit(int number)
{
    if(number/10==0)
    {
        return number;
    }
    else
    {
        return TopDigit(number/10);
    }
}