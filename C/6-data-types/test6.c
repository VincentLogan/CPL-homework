//超级鸡尾酒 (wine.c)
// #include<stdio.h>
// int main()
// {
//     int n,L,point=0,sum=0;
//     scanf("%d %d",&n,&L);
//     int value[n],content[n];
//     for(int i=0;i<n;i++)
//     {
//         scanf("%d",&value[i]);
//     }
//     for(int i=0;i<n;i++)
//     {
//         scanf("%d",&content[i]);
//     }
//     while(1)
//     {
//         point=0;
//         for(int i=0;i<n;i++)
//         {
//             if(value[i]>=value[point]&&content[i]!=0)
//             {
//                 point=i;
//             }
//         }
//         if(L>content[point])
//         {
//             sum+=content[point]*value[point];
//             L-=content[point];
//             value[point]=0;
//         }
//         else if(L<=content[point])
//         {
//             sum+=L*value[point];
//             printf("%d",sum);
//             return 0;
//         }
//     }
// }


//括号序列 (brackets.c)
// #include<stdio.h>
// int main()
// {
//     int n,point=0;
//     char s[100005];
//     scanf("%d",&n);
//     int answer[n];
//     while(getchar()!='\n');
//     for(int i=0;i<n;i++)
//     {
//         while(1)
//         {
//             scanf("%c",&s[point]);
//             if(s[point]=='\n')
//             {
//                 break;
//             }
//             if(point==0)
//             {
//                 point++;
//                 continue;
//             }
//             else if((s[point]==')'&&s[point-1]=='(')||(s[point]==']'&&s[point-1]=='[')||(s[point]=='}'&&s[point-1]=='{'))
//             {
//                 point--;
//             }
//             else
//             {
//                 point++;
//             }
//         }
//         if(point==0)
//         {
//             answer[i]=1;
//             point=0;
//         }
//         else
//         {
//             answer[i]=0;
//             point=0;
//         }
//     }
//     for(int i=0;i<n;i++)
//     {
//         if(answer[i]==1)
//         {
//             printf("True\n");
//         }
//         else
//         {
//             printf("False\n");
//         }
//     }
//     return 0;
// }

// #include<stdio.h>
// #include<stdbool.h>
// int main()
// {
//     bool square=true;
//     int R,C,sum=0;
//     scanf("%d %d",&R,&C);
//     char matrix[R][C];
//     int up[101][101]={0},down[101][101]={0};
//     while(getchar()!='\n');
//     for(int i=0;i<R;i++)
//     {
//         for(int j=0;j<C;j++)
//         {
//             scanf("%c",&matrix[i][j]);
//         }
//         while(getchar()!='\n');
//     }
//     for(int i=0;i<R;i++)
//     {
//         for(int j=0;j<C-1;j++)
//         {
//             if(matrix[i][j]=='/'&&matrix[i][j+1]=='\\')
//             {
//                 for(int x=0;;x++)
//                 {
//                     if((i+2*x+1<R&&j-x>=0&&j+x+1<C)&&(matrix[i+x][j-x]=='/'&&matrix[i+x][j+x+1]=='\\'))
//                     {
//                         down[i][j]++;
//                     }
//                     else
//                     {
//                         break;
//                     }
//                 }       
//             }
//             else if(matrix[i][j]=='\\'&&matrix[i][j+1]=='/')
//             {
//                 for(int x=0;;x++)
//                 {
//                     if((i-2*x-1>=0&&j-x>=0&&j+x+1<C)&&(matrix[i-x][j-x]=='\\'&&matrix[i-x][j+x+1]=='/'))
//                     {
//                         up[i][j]++;
//                     }
//                     else
//                     {
//                         break;
//                     }
//                 }
//             }
//         }
//     }
//     for(int i=0;i<R-1;i++)
//     {
//         for(int j=0;j<C-1;j++)
//         {
//             if(down[i][j]>0)
//             {
//                 for(int z=0;z<down[i][j];z++)
//                 {
//                     if(up[i+2*z+1][j]>z)
//                     {
//                         sum++;
//                     }
//                 }
//             }
//         }
//     }
//     printf("%d",sum);
//     return 0;
//}

#include<stdio.h>
#include<math.h>
int main()
{
    int n,q,m=1,buddy[32][10000]={0},id=0,apply=0,binary=0,step[32]={0},number[32]={0},start=32,procduce[1000];
    for(int i=0;i<32;i++)
    {
        step[i]=1;
    }
    char order;
    scanf("%d %d",&n,&q);
    start=n;
    buddy[n][0]=1;
    number[n]++;
    for(int i=0;i<q;i++)
    {
        while(getchar()!='\n');
        scanf("%c",&order);
        if(order=='A')
        {
            scanf("%d %d",&id,&apply);
            binary=0;
            while(apply>pow(2,binary))
            {
                binary++;
            } 
            if(binary<start)
            {
                start=binary;
            }
            for(int j=binary;;j++)
            {
                if(buddy[j][0]>0)
                {
                    for(int z=j;z>binary;z--)
                    {
                        buddy[z][0]--;
                        number[z]--;
                        buddy[z][step[z]++]=-1;
                        buddy[z-1][0]+=2;
                        number[z-1]+=2;
                        m++;
                    }
                    buddy[binary][0]--;
                    buddy[binary][step[binary]++]=id;
                    break;
                }
            }
        }
        else if(order=='Q')
        {
            printf("%d\n",m);
            int point;
            point=start;
            for(int z=0;z<m;)
            {
                if(number[point]>0)
                {
                    int num=1;
                    for(int x=0;x<number[point];)
                    {
                        if(buddy[point][num]!=-1)
                        {
                            printf("%d ",buddy[point][num]);
                            num++;
                            x++;
                            z++;
                        }
                        else
                        {
                            num++;
                        }
                    }
                    point++;
                }
            }
            printf("\n");
        }
    }
    return 0;
}