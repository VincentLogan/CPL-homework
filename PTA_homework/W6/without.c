#include<stdio.h>
int main()
{
    int a[20],b[20],c[201][2]={0};
    int n,m;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
        c[a[i]][1]++;
    }
    scanf("%d",&m);
    for(int i=0;i<m;i++)
    {
        scanf("%d",&b[i]);
        c[b[i]][2]++;
    }
    for(int i=0;i<n;i++)
    {
        if(c[a[i]][2]==0)
        {
            printf("%d ",a[i]);
            c[a[i]][2]=1;
        }
    }
    for(int i=0;i<m;i++)
    {
        if(c[b[i]][1]==0)
        {
            printf("%d ",b[i]);
            c[b[i]][1]=1;
        }
    }
    return 0;
}