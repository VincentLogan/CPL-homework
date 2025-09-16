#include<stdio.h>
#include<stdlib.h>
int main()
{
    freopen("marathon.in","r",stdin);
    freopen("marathon.out","w",stdout);
    int n,skip_point=1,save=0,S1,S2,sum=0;
    scanf("%d",&n);
    int coordinate[n][2];
    for(int i=0;i<n;i++)
    {
        fscanf("%d%d",&coordinate[i][0],&coordinate[i][1]);
    }
    for(int i=1;i<n-1;i++)
    {
        S1=abs(coordinate[i-1][0]-coordinate[i+1][0])+abs(coordinate[i-1][1]-coordinate[i+1][1]);
        S2=abs(coordinate[i][0]-coordinate[i-1][0])+abs(coordinate[i][1]-coordinate[i-1][1])+abs(coordinate[i][0]-coordinate[i+1][0])+abs(coordinate[i][1]-coordinate[i+1][1]);;
        if(save<S2-S1)
        {
            save=S2-S1;
            skip_point=i;
        }
    }
    for(int i=0;i<n-1;i++)
    {
        sum+=abs(coordinate[i][0]-coordinate[i+1][0])+abs(coordinate[i][1]-coordinate[i+1][1]);
    }
    printf("%d",sum-save);
    fclose(stdin);
    fclose(stdout);
    return 0;
}