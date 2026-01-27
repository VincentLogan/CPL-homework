#include<stdio.h>
#include<string.h>
int main()
{
    char a[105];
    fgets(a,sizeof(a),stdin);
    size_t n=strlen(a);
    if(n>0&&a[n-1]=='\n')
    {
        a[n-1]='\0';
        n=n-1;
    }
    printf("%zu\n\"",n);
    for(int i=0;i<20&&a[i]!='\0';i++)
    {
        printf("%c",a[i]);
    }
    printf("\"");
    return 0;
}