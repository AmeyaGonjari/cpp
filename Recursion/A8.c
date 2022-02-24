#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
	int data;
	struct node * next;
}NODE,*PNODE,**PPNODE;

void InsertFirst(PPNODE head ,int No)
{
	PNODE newn = NULL;
	newn = (PNODE)malloc(sizeof(NODE));
	newn->data = No;
	newn->next = NULL;

	if(*head == NULL)
	{
		*head = newn;
	}
	else
	{
		newn->next = *head;
		*head = newn;
	}

}

void Display(PNODE head)
{
	if(head != NULL)
	{
		printf("|%d|->",head->data);
		head = head->next;
		Display(head);
	}

}
int Count (PNODE head)
{
	static int iCnt = 0;
	if(head != NULL)
	{	
		iCnt++;
		head = head->next;
		Count(head);
	}
	return iCnt;
}

int main()
{
	PNODE first = NULL;
	int iRet = 0;
	InsertFirst(&first,51);
	InsertFirst(&first,21);
	InsertFirst(&first,11);
	Display(first);
	iRet = Count(first);
	printf("%d\n",iRet );
	return 0;
}