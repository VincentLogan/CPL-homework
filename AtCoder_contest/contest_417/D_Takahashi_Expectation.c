#include<stdio.h>
int main()
{
    int n,Q,mood;
    scanf("%d",&n);
    int present[n+1][3];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<=2;j++)
        {
            scanf("%d",&present[i][j]);
        }
    }
    scanf("%d",&Q);
    int mood_initial[Q+1];
    for(int i=0;i<Q;i++)
    {
        scanf("%d",&mood_initial[i]);
    }
    for(int i=0;i<Q;i++)
    {
        mood=mood_initial[i];
        for(int j=0;j<n;j++)
        {
            if(mood<=present[j][0])
            {
                mood+=present[j][1];
            }
            else if(mood>present[j][0]&&mood-present[j][2]>=0)
            {
                mood=mood-present[j][2];
            }
            else
            {
                mood=0;
            }
        }
        printf("%d\n",mood);
    }
    return 0;
}