#include<stdio.h>
#include<math.h>
#include<stdbool.h>
int main()
{
    bool depend=false;
    int N,M;
    double huan=0,product=0;
    scanf("%d %d",&N,&M);
    double a[M][N],Q[M][N],q[M][N];
    for(int i=0;i<M;i++)
    {
        for(int j=0;j<N;j++)
        {
            scanf("%lf",&a[i][j]);
            Q[i][j]=a[i][j];
        }
    }
    for(int i=0;i<M;i++)
    {
        for(int j=0;j<i;j++)
        {
            huan=0;
            for(int z=0;z<N;z++)
            {
                huan+=q[j][z]*a[i][z];
            }
            for(int x=0;x<N;x++)
            {
                Q[i][x]-=huan*q[j][x];
            }
        }
        depend=true;
        for(int j=0;j<N;j++)
        {
            if(Q[i][j]>0.000001)
            {
                depend=false;
            }   
        }
        product=0;
        for(int j=0;j<N;j++)
        {
            product+=Q[i][j]*Q[i][j];
        }
        product=sqrt(product);
        for(int j=0;j<N;j++)
        {
            q[i][j]=Q[i][j]/product;
        }
        if(depend==true)
        {
            printf("YES %d",i+1);
            return 0;
        }
    }
    printf("NO\n");
    for(int i=0;i<N;i++)
    {
        if(i==0)
        {
        printf("%.2f",q[M-1][i]);
        }
        else
        {
            printf(" %.2f",q[M-1][i]);
        }
    }
    return 0;
}