#include<stdio.h>
#include<stdbool.h>

    char matrix[101][101];
    int up[101][101]={0},down[101][101]={0};
char s[101]; 

inline int readc(){
    int t = 0;
    char c = getchar();
    while (c != '(' && c != ')') c = getchar();
    while (c == '(' || c == ')') s[++t] = c,c = getchar();
    return t;
}
int main()
{
    bool square=true;
    int R,C,sum=0;
    scanf("%d %d",&R,&C);
    for(int i=0;i<R;i++)
    {
        for(int j=0;j<C;j++)
        {
            matrix[i][j] = readc();
        }
    }
    for(int i=0;i<R;i++)
    {
        for(int j=0;j<C-1;j++)
        {
            if(matrix[i][j]=='/'&&matrix[i][j+1]=='\\')
            {
                for(int x=0;;x++)
                {
                    if((i+2*x+1<R&&j-x>=0&&j+x+1<C)&&(matrix[i+x][j-x]=='/'&&matrix[i+x][j+x+1]=='\\'))
                    {
                        down[i][j]++;
                    }
                    else
                    {
                        break;
                    }
                }       
            }
            else if(matrix[i][j]=='\\'&&matrix[i][j+1]=='/')
            {
                for(int x=0;;x++)
                {
                    if((i-2*x-1>=0&&j-x>=0&&j+x+1<C)&&(matrix[i-x][j-x]=='\\'&&matrix[i-x][j+x+1]=='/'))
                    {
                        up[i][j]++;
                    }
                    else
                    {
                        break;
                    }
                }

            }
        }
    }
    for(int i=0;i<R-1;i++)
    {
        for(int j=0;j<C-1;j++)
        {
            if(down[i][j]>0)
            {
                for(int z=0;z<down[i][j];z++)
                {
                    if(up[i+2*z+1][j]>z)
                    {
                        sum++;
                    }
                }
            }
        }
    }
    printf("%d",sum);
    return 0;
}