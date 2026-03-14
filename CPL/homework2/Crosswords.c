#include<stdio.h>
#include<stdbool.h>
bool Horizontal(int R,int C,int m,char b[][m+1]) {
    bool a=false;
    if((C==1||b[R][C-1]=='#')&&b[R][C+1]!='#'&&b[R][C+2]!='#')
    {
        a=true;
    }
    return a;
}
bool Vertical(int R,int C,int m,char b[][m+1]) {
    bool a=false;
    if((R==1||b[R-1][C]=='#')&&b[R+1][C]!='#'&&b[R+2][C]!='#')
    {
        a=true;
    }
    return a;
}
int main(){
    freopen("crosswords.in","r",stdin);     
    freopen("crosswords.out","w",stdout);
    int N,M,sum=0;
    scanf("%d %d",&N,&M);
    char grid[N+1][M+1];
    for(int i=1;i<=N;i++)
    {
        while(getchar()!='\n');
        for(int j=1;j<=M;j++)
        {   
            scanf("%c",&grid[i][j]);
        }
    }
    for(int i=1;i<=N;i++)
    {
        for(int j=1;j<=M;j++)
        {
            if(i>N-2&&j<=M-2)
            {
                if(grid[i][j]!='#'&&Horizontal(i,j,M,grid)==true)
                    {
                        grid[i][j]='!';
                        sum++;
                    }
            }
            else if(j>M-2&&i<=N-2)
            {
                if(grid[i][j]!='#'&&Vertical(i,j,M,grid)==true)
                    {
                        grid[i][j]='!';
                        sum++;
                    }
            }
            else if(i>N-2&&j>M-2)
            {
                break;
            }
            else
            {   
                if(grid[i][j]!='#'&&(Vertical(i,j,M,grid)==true||Horizontal(i,j,M,grid)==true))
                    {
                        grid[i][j]='!';
                        sum++;
                    }
            }
        }
    }
    printf("%d\n",sum);
    for(int i=1;i<=N;i++)
    {
        for(int j=1;j<=M;j++)
        {
            if(grid[i][j]=='!')
            {
                printf("%d %d\n",i,j);
            }
        }
    }
    return 0;
}