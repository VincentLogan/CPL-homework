#include<stdio.h>
int main()
{
    int n,k,a,b=0;
    char xulie[20],zancun[20];
    scanf("%d%s%d",&n,xulie,&k);
    a=n-1;
    for(int i=k-1;i>=0;i--)
    {
        zancun[b]=xulie[i];
        b++;
    }
    for(int i=k;i<n;i++)
    {
        zancun[i]=xulie[a];
        a--;
    }
    printf("%s",zancun);
    return 0;
}