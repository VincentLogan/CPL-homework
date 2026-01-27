#include<stdio.h>
#include<stdlib.h>

int day[100005]={0};

int compare(const void *a,const void *b)
{
    return *(int*)b-*(int*)a;
}

int main(){
    int N,R,M,D,extra_day=0;
    int point_max=0,L=0,point_L=0;
    scanf("%d %d %d %d",&N,&R,&M,&D);
    for(int i=0;i<N;i++)
    {
        scanf("%d",&day[i]);
    }
    qsort(day,N,sizeof(int),compare);
    //for(int i=0;i<N;i++)
    //{
    //    printf("%d ",day[i]);
    //}
    for(int i=0;i<N;i++)
    {
        if(day[i]>=R)
        {
            point_max=i;
        }
        else{
            break;
        }
    }
    //printf("\npoint_max=%d\n",point_max);
    if(point_max+M>N-1){
        printf("-1");
        return 0;
    }
    else{
        point_L=point_max+M;
    }
    L=day[point_L];
    //rintf("point_L=%d\nL=%d\n",point_L,L);
    for(int i=point_max+1;i<=point_L;i++)
    {
        extra_day+=day[i]-L;
    }
    //printf("extra_day=%d\n",extra_day);
    while(extra_day<D&&L>0){
        L--;
        if(L>=day[point_L+1]){
            extra_day+=M;
        }
        else{
            extra_day+=++M;
            point_L++; 
        }
    }
    if(extra_day<D)
    {
        printf("-1");
    }
    else
    {
        printf("%d",L);
    }
    return 0;
}