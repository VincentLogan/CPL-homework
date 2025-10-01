#include<stdio.h>
int main()
{
    int m,n,a[1000],x,num=0;
    scanf("%d %d",&m,&n);
    for(int i=m;i<=n;i++)
    {
        int sum=1;
        x=0;
        a[0]=1;
        for(int j=2;j<i/a[x];j++)
        {
            if(i%j!=0)
            {
                continue;
            }
            else if(j*j!=i)
            {
                sum+=j+i/j;
                a[++x]=j;
            }
            else
            {
                sum+=j;
                a[++x]=j;
            }
        }
        if(sum==i)
        {
            printf("%d = 1",i);
            for(int j=1;j<=x;j++)
            {
                printf(" + %d",a[j]);
            }
            for(int j=x;j>0;j--)
            {
                printf(" + %d",i/a[j]);
            }
            printf("\n");
            num++;
        }
    }
    if(num==0)
    {
        printf("None");
    }
    return 0;
}