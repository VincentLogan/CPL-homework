#include<stdio.h>
#define NUM 10007
int main()
{
    long long int one[10005],n,j=1,zancun=0,result;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        for(int b=1;b<=i+1;b++)
        {
            j=j*(b%NUM);
        }
        one[i]=j%NUM;
        j=1;
    }
    for(int a=0;a<n;a++)
    {
        zancun=zancun+one[a];
    }
    result=zancun%NUM;
    printf("%d\n",result);
    return 0;
}