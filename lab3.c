#include<stdio.h>
#include<ctype.h>
#include<conio.h>
int main()
{
    char a[20];
    int flag,i=1;
    printf("\n Enter an identifier:\t");
    scanf("%s",a);
    if(isalpha(a[0])||a[0]=='_')
    {
        flag=1;
    }
    while(a[i]!='\0')
    {
        if(!isdigit(a[i])&&!isalpha(a[i])&&a[i]!='_')
        {
            flag=0;
            break;
        }
        i++;
    }
    if(flag==1)
    {
        printf("\n %s is valid identifier.",a);
    }
    else{
        printf("\n %s is not an identifier.",a);
    }
    return 0;
}