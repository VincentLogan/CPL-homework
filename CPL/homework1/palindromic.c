#include<stdio.h>
#include<stdbool.h>
int main()
{
    bool prime=true;
    int left_margin,right_margin,cache=0,digit_left,digit_right;
    scanf("%d %d",&left_margin,&right_margin);
        if(left_margin<=5)
        {
            printf("5\n7\n11\n");
        }
        else if(left_margin<=7&&left_margin>5)
        {
            printf("7\n11\n");
        }
        else if(left_margin<=11&&left_margin>7)
        {
            printf("11\n");
        }
        for(int w3=1;w3<=9;w3+=2)
        {
            for(int w2=0;w2<=9;w2++)
            {
                prime=true;
                cache=w3*100+w2*10+w3;
                if(cache<left_margin)
                {
                    continue;
                }
                if(cache>right_margin)
                {
                    return 0;
                }
                for(int j=2;j*j<=cache;j++)
                {
                    if(cache%j==0)
                    {
                        prime=false;
                        break;
                    }
                }
                if(prime)
                {
                    printf("%d\n",cache);
                }
            }
        }
        for(int w5=1;w5<=9;w5+=2)
        {
            for(int w3=0;w3<=9;w3++)
            {
                for(int w1=0;w1<=9;w1++)
                {
                    prime=true;
                    cache=w5*10001+w3*1010+w1*100;
                    if(cache<left_margin)
                    {
                        continue;
                    }
                    if(cache>right_margin)
                    {
                        return 0;
                    }
                for(int j=2;j*j<=cache;j++)
                {
                    if(cache%j==0)
                    {
                        prime=false;
                        break;
                    }
                }
                if(prime)
                {
                    printf("%d\n",cache);
                }
                }
            }
        }
        for(int w7=1;w7<=9;w7+=2)
        {
            for(int w5=0;w5<=9;w5++)
            {
                for(int w3=0;w3<=9;w3++)
                {
                    for(int w1=0;w1<=9;w1++)
                    {
                        prime=true;
                        cache=w7*1000001+w5*100010+w3*10100+w1*1000;
                        if(cache<left_margin)
                        {
                            continue;
                        }
                        if(cache>right_margin)
                        {
                            return 0;
                        }
                        for(int j=2;j*j<=cache;j++)
                        {
                            if(cache%j==0)
                            {
                                prime=false;
                                break;
                            }
                        }
                        if(prime)
                        {
                            printf("%d\n",cache);
                        }
                    }
                }
            }
        }
    return 0;
}