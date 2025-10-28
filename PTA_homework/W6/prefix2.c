#include<stdio.h>
int main()
{
    int n,answer=0;
    scanf("%d",&n);
    int a[n],b[1000000]={0};
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
        if(b[a[i]]==0)
            {
                answer=i;
                b[a[i]]=1;
            }
    }
    printf("%d",answer);
    return 0;
}
