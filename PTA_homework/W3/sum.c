#include<stdio.h>
#include<math.h>
int main()
{
    int n;
    double sum=0;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        sum+=-i*1.0/(2*i-1)*pow(-1,i);
    }
    printf("%.3f",sum);
    return 0;
}