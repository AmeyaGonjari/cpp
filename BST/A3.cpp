#include<iostream>
using namespace std;

typedef struct node
{
	int data;
	struct node * lChild;
	struct node * rChild;
}NODE,*PNODE,**PPNODE;


void Insert(PPNODE head ,int no)
{
	PNODE newn = new NODE;
	
	newn->data = no;
	newn->lChild = NULL;
	newn->rChild = NULL;

	if(*head == NULL)
	{
		*head = newn;

	}
	else
	{
		PNODE temp = *head;
		
		while(1)                                //Uncondition loop
		{
			if(temp->data == no)
			{	
				cout<<"Duplicate node\n";
				
				delete newn;
				break;

			}
			else if( no < (temp->data ))      //Lahan data
			{
				if(temp->lChild == NULL)
				{
					temp->lChild = newn;
					break;
				}
				else
				{
					temp = temp-> lChild;
				}

			}
			else if(no>(temp->data ))    //motha data
			{

				if(temp->rChild == NULL)
				{
					temp->rChild = newn;
					break;
				}
				else
				{
					temp = temp-> rChild;
				}
			}
		}
	}
}

bool Search(PNODE head,int no)
{
	bool flag = false;

	if(head == NULL)  //tree is empty
	{
		return flag;
	}
	else              // atleast 1 node
	{

		while(head != NULL)
		{

			if(no == head->data)    // node sapadla
			{
				flag = true;
				break;
			}

			else if(no < (head->data))   //left
			{
				head = head->lChild; 

			}

			else if(no >( head->data))  // right
			{
				head = head->rChild;

			}
		}
 		return flag;
	}
}

int Count(PNODE head)
{
	static int iCnt = 0;
	if(head != NULL)
	{
		iCnt++;
		Count(head->lChild);
		Count(head->rChild);
	}

	return iCnt;
} 

int CountLeaf(PNODE head)
{
	static int iCnt = 0;
	if(head != NULL)
	{
		if((head->lChild == NULL)&&(head->rChild == NULL))
		{
			iCnt++;
		}
		CountLeaf(head->lChild);
		CountLeaf(head->rChild);
	}
	return iCnt;
} 
int CountParent(PNODE head)
{
	static int iCnt = 0;
	if(head != NULL)
	{
		if((head->lChild != NULL)||(head->rChild != NULL))
		{
			iCnt++;
		}
		CountParent(head->lChild);
		CountParent(head->rChild);
	}
	return iCnt;
} 

int main()
{
	int no = 0;
	int iRet = 0;
	bool bret = false;
	PNODE first = NULL;

	Insert(&first,51);
	Insert(&first,21);
	Insert(&first,101);
	
	cout<<"Enter number to search\n";
	cin>>no;


	bret = Search(first,no);
	if(bret == true)
	{
		cout<<"Data is there\n"<<iRet;
	}
	else
	{
			cout<<"Data is  not there\n";
	}
	iRet = Count(first);
	cout<<"No of nodes are:"<<iRet<<"\n";
	iRet = CountLeaf(first);
	cout<<"No of nodes are:"<<iRet<<"\n";
	iRet = CountLeaf(first);
	cout<<"No of nodes are:"<<iRet<<"\n";
	iRet = CountParent(first);
	cout<<"No of nodes are:"<<iRet<<"\n";
	return 0;
}