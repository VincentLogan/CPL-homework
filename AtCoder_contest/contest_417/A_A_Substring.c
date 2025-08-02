#include<stdio.h>
int main()
{
    int n,A,B;
    scanf("%d%d%d",&n,&A,&B);
    char string[n+1];
    while(getchar()!='\n');
    fgets(string,n+1,stdin);
    for(int i=A;i<n-B;i++)
    {
        printf("%c",string[i]);
    }
    return 0;
}