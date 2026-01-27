#include<stdio.h>
int main()
{
    char a[105],b[105];
    int i_a=0,i_b=0;
    scanf("%100s",a);
    scanf("%100s",b);
    while(a[i_a++]!='\0');
    while(b[i_b++]!='\0');
    i_a--;
    i_b--;
    if(i_a>=i_b){
        for(int i=1;i<=i_b;i++){
            a[i_a-i]+=b[i_b-i]-'0';
            if(a[i_a-i]>'9'&&i_a-i>0){
                a[i_a-i-1]++;
                a[i_a-i]-=10;
            }
        }
        i_a--;
        while(i_a){
            if(a[i_a]>'9'){
                a[i_a-1]++;
                a[i_a]-=10;
                i_a++;
            }
            i_a--;
        }
        if(a[0]>'9'){
            printf("1");
            a[0]-=10;
        }
        printf("%s",a);
    }
    else{
        for(int i=1;i<=i_a;i++){
            b[i_b-i]+=a[i_a-i]-'0';
            if(b[i_b-i]>'9'&&i_b-i>0){
                b[i_b-i-1]++;
                b[i_b-i]-=10;
                i_b++;
            }
        }
        while(i_b){
            if(b[i_b]>'9'){
                b[i_b-1]++;
                b[i_b]-=10;
            }
            i_b--;
        }
        if(b[0]>'9'){
            printf("1");
            b[0]-=10;
        }
        printf("%s",b);
    }
    return 0;
}    