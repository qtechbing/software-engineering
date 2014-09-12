#include<stdio.h>
#include<stdlib.h>

#define LENGTH 1024
#define NUM    10

typedef struct DataNode
{
	int cmd;
	char info[NUM];
	struct DataNode* next;
}DataNode;

int main()
{
	DataNode *head=NULL,*p=NULL,*q=NULL;
	int i;
	for(i=0;i<NUM;i++)
	{
		p=(DataNode*)malloc(sizeof(DataNode));
		p->cmd=i;
		snprintf(p->info,1000,"This is %d cmd!", i);
		if(head==NULL) /*下面是采用尾插入法创建链表*/
			head=p;
		else
			q->next=p;
		q=p;
	}
	if(q!=NULL)
		q->next=NULL;

	printf("Menu List:\n");
	p=head;
	while(p!=NULL)
	{
		printf("%dth -- %s\n",p->cmd,p->info);
		p=p->next;
	}
	
	while(1)
	{
		int cmd;
		printf("Input a cmd number >");
		scanf("%d",&cmd);
		if(cmd<0||cmd>=NUM)
		{
			printf("This is a wrong cmd number!\n");
			continue;	
		}
		p=head;
		while(p!=NULL)
		{
			if(p->cmd==cmd)
			{
				printf("%d -- %s\n",p->cmd,p->info);
				break;
			}
			p=p->next;
		}
	}
	
	return 0;
}