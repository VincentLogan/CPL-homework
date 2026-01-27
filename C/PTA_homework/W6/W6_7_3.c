#include<stdio.h>
int main()
{
    int n,count=0;
    scanf("%d",&n);
    int a[n],b[105]={0};
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
        b[a[i]]++;
    }
    for(int i=100;i>=0;i--)
    {
        for(int j=0;j<b[i];j++)
        {
            if(count==0)
            {
                printf("%d",i);
                count++;
                continue;
            }
            printf(" %d",i);
        }
    }
    return 0;
}