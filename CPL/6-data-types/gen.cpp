#include <bits/stdc++.h>

const int N = 100;

inline int rnd(int l,int r){
    return rand() % (r - l + 1) + l;
} 

int main(){
    srand((int)time(0));
    printf("%d %d\n",N,N);
    for (int i = 1;i <= N;i++){
        for (int j = 1;j <= N;j++){
            putchar(rnd(0,1) ? '/' : '\\');
        }
        puts("");
    }
    return 0;
}