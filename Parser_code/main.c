#include <stdio.h>
#include <stdlib.h>
#include<string.h>

int r=0,c=0;
char item[50],item[50];
char a[25][25][11]={
{"S","K","$"},
{"S","begin","$"},
{"S","B","C","B","P","1","$"},
{"S","Z","C","Z","D","2","$"},
{"K","int","A","$"},
{"K","while","(","M",")","$"},
{"K","end","F","$"},
{"K","return","B","$"},
{"A","B","C","1","$"},
{"A","main","(",")","$"},
{"B","count","$"},
{"C","=","$"},
{"M","Z","R","1","$"},
{"Z","n","$"},
{"R",">","$"},
{"P","+","$"},
{"D","/","$"},
{"F","while","$"},
{"F","_","$"},
};
char b[140][140][150]={
{"S","int","0"},
{"S","while","0"},
{"S","return","0"},
{"S","end","0"},
{"S","begin","1"},
{"S","count","2"},
{"S","n","3"},
{"K","int","4"},
{"K","while","5"},
{"K","return","7"},
{"K","end","6"},
{"A","count","8"},
{"A","main","9"},
{"B","count","10"},
{"C","=","11"},
{"M","n","12"},
{"Z","n","13"},
{"R",">","14"},
{"P","+","15"},
{"D","/","16"},
{"F","while","17"},
{"F","_","18"},
};

int prod(int x , char str[]);
char stack[10][110];
char queue[10][100];
char *token;
int count_no;
int l=0,i,k,front=0,rear=-1,state=1,r;
char str[50],stp[100];
int main()
{
    int x;
    strcpy(stack[r],"S");
    printf("Enter the string to be parsed\n (with $ at the end )\n");
    while(strcmp(queue[rear],"$")!=0)
    {
        rear++;
        scanf("%s",queue[rear]);
    }
    l1:
    strcpy(stp,queue[front]);
    if((strcmp(stp,")")==0)||(strcmp(stp,"(")==0)||(strcmp(stp,";")==0)||(strcmp(stp,",")==0)||
    (strcmp(stp,"1")==0)||(strcmp(stp,"0")==0))
    {
        printf("%s matched\n",stp);
        front++;
        r++;
        goto l1;
    }
    while(strcmp(stp,"$")!=0)
    {
        for(i=0;i<23;i++)
        {
            strcpy(str,stack[r]);
            strcpy(stp,queue[front]);
            if((strcmp(b[i][0],str)==0)&&(strcmp(b[i][1],stp)==0))
            {
                x=atoi(b[i][2]);
                r=prod(x,str);
            }
            else if((strcmp(str,stp))==0)
            {
                strcpy(item,queue[front]);
                printf("%s matched\n",item);
                front++;
                strcpy(str,queue[front]);
                strcpy(item,stack[r]);
                r++;
                goto l1;
            }
        }
    }
    l2:
    if(strcmp(stack[r],"\0")!=0)
    {
        printf("not correct syntax\n");
    }
    printf("thanks for parsing\n");
    return 0;
}

int prod(int x,char str[])
{
    char stq[100];
    int y=1,count_no=0;
    printf("%s ->",a[x][0]);
    l2 : strcpy(stq,a[x][y]);
    while(strcmp(stq,"$")!=0)
    {
        strcpy(str,stq);
        printf("%s",str);
        strcpy(stack[r],str);
        count_no++;
        r++;y++;
        goto l2;
    }
    if(count_no>r)
    {
        r = count_no-r;
    }
    else
    {
        r = r-count_no;
    }
    printf("\n");
    return r;
}
