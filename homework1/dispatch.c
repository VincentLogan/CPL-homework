#include<stdio.h>
int main()
{
    int n,m,cache=0,zancun,answer=0;
    scanf("%d%d",&m,&n);
    int item_machine[n+1][m+1],item_time[n+1][m+1],order[405]={0},time[21][8005]={0},step[21]={0},start[21]={0};
    //输入顺序
    for(int i=1;i<=n*m;i++)
    {
        scanf("%d",&order[i]);
        cache++;
    }
    //输入工件每个工序的机器item_machine[工件][机器]
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            scanf("%d",&item_machine[i][j]);
        }
    }
    //输入工件每个工序的时间item+_time[工件][时间]
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            scanf("%d",&item_time[i][j]);
        }
    }
    for(int i=1;i<=cache;i++)
    {
        start[order[i]]++;
        zancun=start[order[i]];
        while(zancun-start[order[i]]<item_time[order[i]][step[order[i]]+1]-1)
        {
            if(time[item_machine[order[i]][step[i]+1]][zancun]==0)
            {
                zancun++;
            }
            else
            {
                zancun++;
                start[order[i]]=zancun;
            }
        }
        for(int j=0;j<item_time[order[i]][step[i]+1];j++)
        {
            time[item_machine[order[i]][step[order[i]]+1]][start[order[i]]]=1;
            start[order[i]]++;
        }
        start[order[i]]--;
        step[order[i]]++;
    }
    for(int i=1;i<=n;i++)
    {
        if(answer<(start[i]+item_time[i][m+1]))
        {
            answer=start[i]+item_time[i][m+1];
        }
    }
    printf("%d",answer);
    return 0;
}