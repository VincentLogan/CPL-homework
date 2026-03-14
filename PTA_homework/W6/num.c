#include<stdio.h>
int fun(int m,int n);
 int main( )
  {  int m,n;
    scanf("%d%d",&m,&n);
    if(fun(m,n)==1) printf("Y");
    else printf("N");
   return 0;
    }  


int fun(int m,int n)
{
    do
    {
        if(n==m%10)
        {
            return 1;
        }
        else
        {
            m=m/10;
        }
    } while (m!=0);
    return 0;
}