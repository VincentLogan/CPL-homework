#include<stdio.h>
int main()
{
    int N;
    scanf("%d",&N);
    int a[N],b[105]={0};
    for(int i=0;i<N;i++)
    {
        scanf("%d",&a[i]);
        b[a[i]]++;
        if(b[a[i]]>(N+1)/2)
            {
                printf("NO");
                return 0;
            }
    }
    printf("YES");
    return 0;
}