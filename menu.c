
/**************************************************************************************************/
/* Copyright (C)  MSE@USTC   2014-2015                                                            */
/*                                                                                                */
/*  FILE NAME             :  menu.c                                                               */
/*  PRINCIPAL AUTHOR      :  Fengshibing                                                          */
/*  SUBSYSTEM NAME        :  menu                                                                 */
/*  MODULE NAME           :  menu                                                                 */
/*  LANGUAGE              :  C                                                                    */
/*  TARGET ENVIRONMENT    :  ANY                                                                  */
/*  DATE OF FIRST RELEASE :  2014/09/12                                                           */
/*  DESCRIPTION           :  This is a menu program                                               */
/**************************************************************************************************/

/*
 * Revision log:
 *
 * Created by Fengshibing, 2014/09/12
 *
 */

#include<stdio.h>
#include<stdlib.h>

#define LENGTH 1024
#define NUM    10
#define CMD_MAX_LEN 128
typedef struct DataNode
{
    char* cmd;
    char* info;
    void (*handler)();
    struct DataNode* next;
}DataNode;
void help();
static DataNode list[]=
{
    {"help","This is help cmd!",help,&list[1]},
    {"version","Menu program v1.0",NULL,NULL}
};
int main()
{
    char cmd[CMD_MAX_LEN];
    DataNode *p;
    while(1)
    {
	printf("Input a cmd number >");
	scanf("%s",cmd);
	p=list;
	while(p!=NULL)
	{
	    if(!strcmp(p->cmd,cmd))
	    {
		printf("%s - %s\n",p->cmd,p->info);
                if(p->handler==help)
                {
                    p->handler();
                }
		break;
	    }
	    p=p->next;
	}
        if(p==NULL)
        {
            printf("This is a wrong cmd!\n");
	}
    }
	
    return 0;
}

void help()
{
    DataNode *p=list;
    printf("Menu List:\n");
    while(p!=NULL)
    {
        printf("%s - %s\n",p->cmd,p->info);
        p=p->next;
    }

}
