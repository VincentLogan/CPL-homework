#include<stdio.h>
int main()
{
    int n;
    scanf("%d",&n);
    char before[n][n],later[n][n],zancun[n][n];
    //输入第一个矩阵
    while(getchar()!='\n');
    for(int row=0;row<n;row++)
    {
        for(int column=0;column<n;column++)
        {
            scanf(" %c",&before[row][column]);
        }
    }
    //输入第二个矩阵
    for(int row=0;row<n;row++)
    {
        for(int column=0;column<n;column++)
        {
            scanf(" %c",&later[row][column]);
        }
    }
    //判断是否为情况1
    for(int row=0;row<n;row++)
    {
        for(int column=0;column<n;column++)
        {
            if(before[row][column]==later[column][n-1-row])
            {
                continue;
            }
            else
            {
                goto defeat_one;
            }
        }
    }
    printf("1");
    return 0;
    //判断是否为情况2
    defeat_one:
    for(int row=0;row<n;row++)
    {
        for(int column=0;column<n;column++)
        {
            if(before[row][column]==later[n-1-row][n-1-column])
            {
                continue;
            }
            else
            {
                goto defeat_two;
            }
        }
    }
    printf("2");
    return 0;
    //判断是否为情况3
    defeat_two:    
    for(int row=0;row<n;row++)
    {
        for(int column=0;column<n;column++)
        {
            if(before[row][column]==later[n-1-column][row])
            {
                continue;
            }
            else
            {
                goto defeat_three;
            }
        }
    }
    printf("3");
    return 0;
    //判断是否为情况4
    defeat_three:
    for(int row=0;row<n;row++)
    {
        for(int column=0;column<n;column++)
        {
            if(before[row][column]==later[row][n-1-column])
            {
                continue;
            }
            else
            {
                goto defeat_four;
            }
        }
    }
    printf("4");
    return 0;
    //判断是否为情况五
    defeat_four:
    for(int row=0;row<n;row++)
    {
        for(int column=0;column<n;column++)
        {
            if(before[row][column]==later[n-1-column][n-1-row])
            {
                continue;
            }
            else
            {
                goto defeat_five_one;
            }
        }
    }
    printf("5");
    return 0;
    defeat_five_one:
    for(int row=0;row<n;row++)
    {
        for(int column=0;column<n;column++)
        {
            if(before[row][column]==later[n-1-row][column])
            {
                continue;
            }
            else
            {
                goto defeat_five_two;
            }
        }
    }
    printf("5");
    return 0;
    defeat_five_two:
    for(int row=0;row<n;row++)
    {
        for(int column=0;column<n;column++)
        {
            if(before[row][column]==later[column][row])
            {
                continue;
            }
            else
            {
                goto defeat_five_three;
            }
        }
    }
    printf("5");
    return 0;
    defeat_five_three:
    //判断是否为情况6及7
    for(int row=0;row<n;row++)
    {
        for(int column=0;column<n;column++)
        {
            if(before[row][column]==later[row][column])
            {
                continue;
            }
            else
            {
                goto defeat_six;
            }
        }
    }
    printf("6");
    return 0;
    defeat_six:
    printf("7");
    return 0;
}