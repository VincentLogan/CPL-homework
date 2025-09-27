#include<stdio.h>
int main(){
    freopen("cowjog.in","r",stdin);
    freopen("cowjog.out","w",stdout);
    int n,group=0,pos,number=1;
    scanf("%d",&n);
    int position[n][2];
    for(int i=0;i<n;i++)
    {
        scanf("%d %d",&position[i][0],&position[i][1]);
    }
    pos=n;
    while(pos!=0)
    {            
        number=1;
        for(int i=1;i<pos;i++)
        {
            if(position[pos-1][1]<position[pos-1-i][1])
            {
                number++;
            }
            // else if(number==(position[pos-1][0]-position[pos-1-i][0])&&position[pos-1][1]==position[pos-1-i][1])
            // {
            //     number++;
            // }
            else
            {
                break;
            }
        }
        pos=pos-number;
        group++;
    }
    printf("%d",group);
    return 0;
}