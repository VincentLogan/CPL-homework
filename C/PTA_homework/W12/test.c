#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int bracket(char *s,int left,int n[],int px);

int add(int nu[],char cu[],int p1,int p2);

int ride(int nu[],char cu[],int p1,int p2);

int main()
{
    char cul[500];
    int num[500]={0};
    int p1=0,p2=0;
    int cap=64;
    int x=0;
    char *formation=(char*)malloc(64);
    char ch;
    ch=getchar();
    while(ch!='\n'&&ch!=' '){
        *(formation+x++)=ch;
        ch=getchar();
    }
    *(formation+x)='\0';
    int point=0;
    while(*(formation+point)){
        x=0;
        if(*(formation+point)=='('){
            int left=point;
            point=bracket(formation,left,num,p2);
            p2++;
        }
        while(*(formation+point)<=57&&*(formation+point)>=48){
            x=1;
            num[p2]=num[p2]*10+(*(formation+point++)-'0');
        }
        if(x==1)    p2++;
        cul[++p1]=*(formation+point++);
        if(*(formation+point-1)=='\0'){
            p2--;
            p1--;
            break;
        }
    }
    p2=ride(num,cul,p2,p1);
    p1=p2;
    printf("%d",add(num,cul,p2,p1));
}


int bracket(char *s,int left,int n[],int px)
{
    int a[50]={0},pp1=0,pp2=0,z=1;
    char b[50];
    char *po=s+left+1;
    while(1){
        z=0;
        if(*po=='('){
            po=s+bracket(s,po-s,a,pp2);
            pp2++;
            continue;
        }
        while (*po<=57&&*po>=48)
        {
            z=1;
            a[pp2]=a[pp2]*10+(*po-'0');
            po++;
        }
        if(z==1)    pp2++;
        b[++pp1]=*po++;
        if(*(po-1)==')'){
            pp2--;
            pp1--;
            break;
        }
    }
    pp2=ride(a,b,pp2,pp1);
    pp1=pp2;
    n[px]=add(a,b,pp2,pp1);
    return po-s;
}

int ride(int nu[],char cu[],int p1,int p2)
{
    int j=1;
    for(int i=1;i<=p1;i++){
        if(cu[i]=='+'||cu[i]=='-'){
            nu[j]=nu[i];
            cu[j]=cu[i];
            j++;
        }
        else{
            if(cu[i]=='*'){
                nu[j-1]=nu[i-1]*nu[i];
            }
            else if(cu[i]=='/'){
                nu[j-1]=nu[i-1]/nu[i];
            }
            else if(cu[i]=='%'){
                nu[j-1]=nu[i-1]%nu[i];
            }
        }
    }
    return j-1;
}

int add(int nu[],char cu[],int p1,int p2){
    int num=nu[0];
    for(int i=1;i<=p1;i++){
        if(cu[i]=='+'){
            num+=nu[i];
        }
        else{
            num-=nu[i];
        }
    }
    return num;
}