#include<stdio.h>
#include<math.h>
#include<stdbool.h>
int main()
{
    int digit=1,zhongjianshang,huan;
    bool prime=true;
    long int left_margin,right_margin,cache=0;
    scanf("%d %d",&left_margin,&right_margin);
    for(int i=left_margin;i<=right_margin;i++)
    {       
        if(i%2==0||i%3==0||(i%5==0&&i!=5)||(i%7==0&&i!=7))
            {
                continue;
            }
        else
        {
            cache=0;
            zhongjianshang=i;
            prime=true;
            digit=floor(log10(i))+1;
            if(digit==1)
            {
                if(i==5||i==7)
                printf("%d\n",i);
            }
            else if(digit%2==0)
            {
                for(int j=0;j<digit/2;j++)
                {
                    cache=cache*10+zhongjianshang%10;
                    zhongjianshang=zhongjianshang/10;
                }
                if(zhongjianshang==cache)
                {
                    for(int a=3;a*a<=i;a+=2)
                    {
                        if(i%a==0)
                        {
                            prime=false;
                            break;
                        }
                    }
                    if(prime)
                    {
                    printf("%d\n",i);
                    continue;
                    }
                }
            }
            else
            {
                for(int j=0;j<(digit-1)/2;j++)
                {
                    cache=cache*10+zhongjianshang%10;
                    zhongjianshang=zhongjianshang/10;
                }
                if(zhongjianshang/10==cache)
                {
                    for(int a=3;a*a<=i;a+=2)
                    {
                        if(i%a==0)
                        {
                            prime=false;
                            break;
                        }
                    }
                    if(prime)
                    {
                    printf("%d\n",i);
                    continue;
                    }
                }
            }
        }    
        
    }
    return 0;
}