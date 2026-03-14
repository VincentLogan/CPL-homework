#include<stdio.h>

void  hanoi(int n, char from, char to, char aux);

int main()
{
    int n;
    char from,to,aux;
    scanf("%d %c %c %c",&n,&from,&to,&aux);
    hanoi(n,from,to,aux);
    return 0; 
}

void hanoi(int n, char from, char to, char aux)
{
    if(n>0)
    {
        hanoi(n-1,from,aux,to);
        printf("%d: %c -> %c\n",n,from,to);
        hanoi(n-1,aux,to,from);
    }
}