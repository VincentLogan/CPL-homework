#include<stdio.h>
int main()
{
    int n,cache=0,min[n+1],huan=0;
    scanf("%d",&n);
    int old[n+1];
    for(int i=0;i<n;i++)
    {
        scanf("%d",&old[i]);
        if(min[huan]>=old[i])
        {
            min[huan+1]=old[i];
            huan++;
        }
    }
    for(int i=0;i<n-min[huan]-min[huan-1];i++){
        for(int j=i+min[huan]+min[huan-1];j<n;j++)
        {
            if(j-i==old[i]+old[j])
            {
                cache++;
            }
        }
    }
    printf("%d",cache);
    return 0;
}