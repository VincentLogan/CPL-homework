#include<stdio.h>
#include<stdbool.h>
int main()
{
    bool x;
    int n,cnt=1;
    scanf("%d",&n);
    int a[n],b[1000000]={0};
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
            if(b[a[i]]==0)
            {
                b[a[i]]=1;
                if(i==0)
                {
                printf("%d",a[i]);
                }
                else
                {
                    printf(" %d",a[i]);
                }
            }
    }
    return 0;
}
