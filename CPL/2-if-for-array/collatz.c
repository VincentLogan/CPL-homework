#include<stdio.h>
#include<math.h>
int main()
{
    int n,zancun,j=0,one[10005];
    scanf("%d",&n);
    one[0]=n;
    for(int i=1;;i++)
    {
        if(n==1)
        {
            break;
        }
        else if(n%2==0)
        {
            n=n/2;
            one[i]=n;
            j++;
        }
        else
        {
            n=n*3+1;
            one[i]=n;
            j++;
        }
    }
    zancun=one[0];
    for(int a=1;a<j;a++)
    {
        if(zancun<one[a])
        {
            zancun=one[a];
        }
    }
    printf("%d %d",j,zancun);
    return 0;
}