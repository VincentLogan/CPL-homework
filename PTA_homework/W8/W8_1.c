#include<stdio.h>
double Fac(int x);

int main()
{
    int n;
    scanf("%d", &n);
    printf("%.14g\n", Fac(n));
    return 0;
}

double Fac(int x)
{
    int n=1;
    if(x>0)
    {
        n=n*x*Fac(x-1);
    }
    else
    {
        return n;
    }
}