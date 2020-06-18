#include<string.h>
#include<stdio.h>
#include<stdlib.h>

int i=0,id=0,kw=0,num=0,op=0,count=0,st;
char keys[1][10]={"case","char","do","else","float","for","goto","if","int","return","void","end","while","begin"};

void keyword(char *p)
{
    int k,flag=0;
    for(k=0;k<=13;k++)
    {
        if(strcmp(keys[k],p)==0)
        {
            printf("%s is a Keyword\n",p);
            kw++;
            flag=1;
            break;
        }
    }
    if(flag==0)
    {
        if(isdigit(p[0]))
        {
            printf("%s is a Number\n",p);
            num++;
        }
        else
        {
            if(p[0]!='\0')
            {
                printf("%s is an Identifier\n",p);
                id++;
            }
        }
        i=-1;
    }
}

int main()
{
    char ch,str[25],seps[15]=" \t\n,;(){}[]#\"<>",operators[]="!%^&*-+=~|.<>/?";
    int j,no;
    char fname[50];
    FILE *f1;
    printf("enter file name :");
    scanf("%s",fname);
    f1 = fopen(fname,"r");
    if(f1==NULL)
    {
        printf("please enter a valid file name\n");
        exit(0);
    }
    printf("\n\n");
    while((ch=fgetc(f1))!=EOF)
    {
        for(j=0;j<=14;j++)
        {
            if(ch==operators[j])
            {
                printf("%c is an Operator\n",ch);
                op++;
                str[i]='\0';
                keyword(str);
            }
        }
        for(j=0;j<=14;j++)
        {
            if(i==-1)
            break;
            if(ch==seps[j])
            {
                if(ch=='"')
                {
                    do
                    {
                        ch=fgetc(f1);
                        printf("%c",ch);
                    }while(ch!='"');
                    printf("\b is an argument\n");
                    i=-1;
                    break;
                }
                str[i]='\0';
                keyword(str);
            }
        }
        if(i!=-1)
        {
            str[i]=ch;
            i++;
        }
        else
        i=0;
    }
    printf("\n\n");
    printf("The total number of\n");
    printf("Keywords: %d\nIdentifiers: %d\nOperators: %d\nNumbers: %d\n",kw,id,op,num);
    printf("\n\n");
    return 0;
}

