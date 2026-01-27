#include<stdio.h>
#include<math.h>
int main(){
    char name[25],unit,great;
    int pre;
    double frac,factor;
    scanf("%s%d%lf%lf %c",name,&pre,&frac,&factor,&unit);
    great='A'+(unit-'a');
    printf("%.2s: %d (%.5f) | %.5E %.5f %c\n",name,pre,frac,pre+frac,(pre+frac)*factor,great);
    return 0;
}