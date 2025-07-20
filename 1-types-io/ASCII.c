#include<stdio.h>
int main(void){
    int great;
    int small;
    scanf("%d",&great);
    char zero='A';
    char one=zero+(great-'A');
    char two='a'+(great-'A');
    small=great+('a'-'A');
    printf("%d %c\n%d %c\n",great,one,small,two);
    return 0;
}
