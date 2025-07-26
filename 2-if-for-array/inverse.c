#include<stdio.h>
int main()
{
    int n,k,a;
    scanf("%d",&n);
    a=n;
    char xulie[20],zancun[20];
    fgets(xulie,n+1,stdin);
    scanf("%d",&k);
    for(int i=k-1;i>=0;i--)
    {
        zancun[i]=xulie[k-i];
    }
    for(int i=k;i<=n;i++)
    {
        zancun[i]=xulie[a];
        a--;
    }
    printf("%s",zancun);
    return 0;
}