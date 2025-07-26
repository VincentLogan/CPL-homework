#include<stdio.h>
int main()
{
    int n,k,a,b=0;
    char xulie[20],zancun[20];
    scanf("%d",&n);
    a=n-1;
    while (getchar() != '\n');
    fgets(xulie,sizeof(xulie),stdin);
    scanf("%d",&k);
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