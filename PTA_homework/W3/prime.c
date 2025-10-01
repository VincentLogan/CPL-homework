#include<stdio.h>
#include<stdbool.h>
int main()
{
    int m;
    bool prime=true;
    scanf("%d",&m);
    for(int i=1;;i++)
    {
        for(int j=2;j*j<=m+i;j++)
            {
                if((m+i)%j==0)
                {
                    prime=false;
                    break;
                }
            }
            if(prime)
            {
                printf("%d\n",m+i);
                return 0;
            }
    } 
}