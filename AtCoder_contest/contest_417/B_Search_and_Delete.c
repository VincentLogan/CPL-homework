#include<stdio.h>
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    int A[n+1],B[m+1];
    for(int i=0;i<n;i++)
    {
        scanf("%d",&A[i]);
    }
    for(int i=0;i<m;i++)
    {
        scanf("%d",&B[i]);
    }
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(B[i]==A[j])
            {
                A[j]=0;
                break;
            }
        }
    }
    for(int i=0;i<n;i++)
    {
        if(A[i]!=0){
        printf("%d ",A[i]);
        }
    }
    return 0;
}