#include<stdio.h>
#include<stdbool.h>
int main()
{
    bool saddle=true;
    int n,max=0,min=0;
    scanf("%d",&n);
    int matrix[n][n];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            scanf("%d",&matrix[i][j]);
        }
    }
    for(int i=0;i<n;i++)
    {
        max=matrix[i][0];
        for(int j=0;j<n;j++)
        {
            if(matrix[i][j]>max)
            {
                max=matrix[i][j];
            }
        }
        for(int z=0;z<n;z++)
        {
            saddle=true;
            if(matrix[i][z]==max)
            {
                for(int j=0;j<n;j++)
                {
                    if(matrix[i][z]>matrix[j][z])
                    {
                        saddle=false;
                        break;
                    }
                }
            if(saddle)
            {
                printf("%d %d",i,z);
                return 0;
            }
            }
        }
    }
    printf("NONE");
    return 0;
}