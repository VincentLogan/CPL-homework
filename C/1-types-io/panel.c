#include<stdio.h>
#include<string.h>
int main()
{
    int W,huan=0,j=0;
    scanf("%d",&W);
    char ID[55]={0},Usernme[55]={0},Email[55]={0},input[155]={0};
    while(getchar()!='\n');
    fgets(input,sizeof(input),stdin);
    for(int i=0;;i++)
    {
        if(input[i+j]!=',')
        {
            ID[i]=input[i+j];
            huan++;
        }
        else
        {
            huan+=1;
            break;
        }
    }
    j=huan;
    for(int i=0;;i++)
    {
        if(input[i+j]!=',')
        {
            Usernme[i]=input[i+j];
            huan++;
        }
        else
        {
            huan+=1;
            break;
        }
    }
    j=huan;
    for(int i=0;;i++)
    {
        if(input[i+j]!='\n'&&input[i+j]!='\0'&&input[i+j]!=0)
        {
            Email[i]=input[i+j];
            huan++;
        }
        else
        {
            huan+=1;
            break;
        }
    }
    // input[strcspn(input,"\n")]='\0';
    // ID=strtok(input,",");
    // Usernme=strtok(NULL,",");
    // // Email=strtok(NULL,",");
    // printf("| ID       | %-s |\n",ID); 
    // printf("| Username | %-s |\n",Usernme); 
    // printf("| Email    | %-s |\n",Email); 
    printf("| ID       | ");
    for(int i=0;i<W;i++)
    {
        if(ID[i]!=0)
        {
        printf("%c",ID[i]);
        }
        else
        printf(" ");
    }
    printf(" |\n| Username | ");
    for(int i=0;i<W;i++)
    {
        if(Usernme[i]!=0)
        {
        printf("%c",Usernme[i]);
        }
        else
        printf(" ");
    }
    printf(" |\n| Email    | ");
    for(int i=0;i<W;i++)
    {
        if(Email[i]!=0)
        {
        printf("%c",Email[i]);
        }
        else
        printf(" ");
    }
    printf(" |");
    return 0;
}