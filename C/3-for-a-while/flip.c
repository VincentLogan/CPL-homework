#include<stdio.h>
#include<math.h>
int main()
{
    int n;
    scanf("%d",&n);
    int a[n];
    for(int i=0;i<n;i++)
    {
        a[i]=0;
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<n;j++)
        {
            if(j%i==0)
            {
                a[j-1]=fabs(a[j-1]-1);
            }
        }
    }
    for(int i=0;i<n;i++)
    {
        if(a[i]==1)
        {
            printf("%d ",i+1);
        }
    }
    return 0;
}