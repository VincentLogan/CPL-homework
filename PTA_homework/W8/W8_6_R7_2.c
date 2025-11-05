#include<stdio.h>

void pri(int a[],int n,int x);

int main()
{
    int n,x;
    scanf("%d",&n);
    x=n;
    int a[n];
    for(int i=0;i<n;i++)
    {
        a[i]=0;
    }
    pri(a,n,x);    
}

void pri(int a[],int n,int x)
{
    static int b[7]={0},step=0;
    if(n==1)
    {
        for(int i=0;;i++)
        {
            if(a[i]==0)
            {
                for(int j=0;j<x-1;j++)
                {
                    printf("%d",b[j]);
                }
                printf("%d",i+1);
                printf("\n");
                break;
            }
        }
    }
    else
    {
        for(int i=0;i<x;i++)
        {
            if(a[i]==0)
            {
                b[step++]=i+1;
                a[i]++;
                pri(a,n-1,x);
                a[i]--;
                step--;
            }
        }
    }
}