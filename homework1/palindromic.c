#include<stdio.h>
#include<math.h>
int main()
{
    int digit=1,zhongjianshang;
    long long int left_margin,right_margin,cache=0;
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
            digit=floor(log10(i))+1;
            if(digit==1)
            {
            printf("%d\n",i);
            }
            if(digit%2==0)
            {
                for(int j=0;j<digit/2;j++)
                {
                    zhongjianshang=i;
                    cache=cache*10+zhongjianshang%10;
                    zhongjianshang=zhongjianshang/10;
                }
                if(zhongjianshang==cache)
                {
                    printf("%d\n",i);
                    continue;
                }
            }
            if(digit%2!=0)
            {
                for(int j=0;j<(digit-1)/2;j++)
                {
                    zhongjianshang=i;
                    cache=cache*10+zhongjianshang%10;
                    zhongjianshang=zhongjianshang/10;
                }
                if(zhongjianshang/10==cache)
                {
                    printf("%d\n",i);
                    continue;
                }
            }
        }
    }
    return 0;
}