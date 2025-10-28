#include<stdio.h>
#include<stdbool.h>
int main()
{
    bool stop=true;
    int n,answer=1;
    scanf("%d",&n);
    do
    {
        stop=false;
        for(int j=2;j*j<=n;j++)
        {
            if(n%(j*j)==0)
            {
                stop=true;
                n=n/(j*j);
                answer=answer*j;
            }
        }
    }while(stop);
    printf("%d %d",answer,n);
    return 0;
}