
#include <stdio.h>
#define M 3
#define N 4
int  fun(int a[][N]);

int main()
{
    int x[M][N],i,j,max;
    for(i=0;i<M;i++)
        for(j=0;j<N;j++)
            scanf("%d",&x[i][j]);
    max=fun(x);
    printf("max=%d",max);
    return 0;
}
/* 请在这里填写答案 */
int  fun(int a[][N])
{
    int max=a[0][0];
    for(int i=0;i<M;i++)
    {
        for(int j=0;j<N;j++)
        {
            if(a[i][j]>max)
            {
                max=a[i][j];
            }
        }
    }
    return max;
}