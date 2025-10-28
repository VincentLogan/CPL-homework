#include<stdio.h>
#include<stdbool.h>
int main()
{
    bool x;
    int n,cnt=1,answer=0;
    scanf("%d",&n);
    int a[n],b[n];
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
        b[0]=a[0];
        for(int j=0;j<i;j++)
        {
            x=false;
            for(int z=0;z<cnt;z++)
            {
                if(a[j]==b[z])
                {
                    x=true;   
                }
            }
            if(!x)
            {
                b[cnt]=a[j];
                cnt++;
                answer=j;
            }
        }
    }
    
    printf("%d",answer);
    return 0;
}