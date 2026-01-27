#include<stdio.h>
int main()
{
    int n,relay=0,result=0;
    int student[100005],tuo[100005];
    scanf("%d",&n);
    for(int i=0;i<=n;i++)
    {
        scanf("%d",&student[i]);
    }
    for(int i=0;i<n;i++)
    {
        relay=relay+student[i];
        if(relay<i+1&&student[i+1]!=0)
        {
            result=result+i+1-relay;
            relay=i+1;
        }
    }
    printf("%d",result);
}