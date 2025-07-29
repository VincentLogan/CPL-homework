#include<stdio.h>
int main()
{
    int n_carpet,x0,y0,cache=0;
    int x[10005],y[10005],g[10005],k[10005];
    scanf("%d",&n_carpet);
    for(int i=1;i<=n_carpet;i++)
    {
        scanf("%d%d%d%d",&x[i],&y[i],&g[i],&k[i]);
    }
    scanf("%d%d",&x0,&y0);
    for(int i=1;i<=n_carpet;i++)
    {
        if(x0>=x[i]&&x0<=(x[i]+g[i])&&y0>=y[i]&&y0<=(y[i]+k[i]))
        {
            cache=i;
        }
    }
    if(cache==0)
    {
        cache=-1;
    }
    printf("%d",cache);
    return 0;
}