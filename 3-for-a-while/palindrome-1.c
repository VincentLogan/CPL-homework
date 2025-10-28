#include<stdio.h>
int main()
{
    int n;
    scanf("%d",&n);
    char a[n+1];
    while(getchar()!='\n');
    fgets(a,n+1,stdin);
    for(int i=0;i<n;i++)
    {
        if(a[i]=='?')
        {
            a[i]=a[n-i-1];
        }
    }
    for(int i=0;i<n;i++)
    {
        printf("%c",a[i]);
    }
    return 0;
}