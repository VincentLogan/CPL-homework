#include<stdio.h>
int main(){
   int answer[5000]={0},huan=0;
   int n,w=0,cnt=1,a=0;
   scanf("%d",&n);
    a=n;
   do{
    a=a/10;
    cnt++;
   }while(a!=0);
   for(int i=0;i<cnt;i++){
    huan=huan*10+1;
   }
   for(int i=0;;i++){
    w++;
    if(huan/n>=10){
        answer[0]=1;
        cnt--;
        break;
    }
    answer[i]=huan/n;
    if(huan%n==0){
        break;
    }    
    huan=huan%n*10+1;
    cnt++;
   }
   for(int i=0;i<w;i++){
    printf("%d",answer[i]);
   }
   printf(" %d",cnt);
   return 0;
}