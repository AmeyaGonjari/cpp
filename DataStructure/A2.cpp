#include<iostream>
using namespace std;

typedef struct node
{
	int data;
	struct node*next;
}NODE,*PNODE;

class SinglyCL
{
private:
	PNODE first;
	PNODE last;
	int iSize;

public:
	SinglyCL()
	{	
		first = NULL;
		last = NULL;
		iSize = 0;
	}

	void Display()
	{	
		PNODE temp = first;
		if(first == NULL && last == NULL)
		{
			return;
		}

		do
		{
			cout<<"|"<<temp->data<<"|->";
			temp = temp->next;

		}while(temp != last->next);
		cout<<"\n";

	}
	
	int Count()
	{
		return iSize;
	}

	void InsertFirst(int no)
	{
		PNODE newn  = new NODE;
		newn -> data = no;
		newn -> next = NULL;

		if((first == NULL) && (last == NULL))
		{
			first = newn;
			last = newn;
		}
		else
		{
			newn->next=first;
			first = newn;
		}

		last->next = first;
		iSize++;
	}

	void InsertLast(int no)
	{
 		
	PNODE newn  = new NODE;
		newn -> data = no;
		newn -> next = NULL;

		if((first == NULL) && (last == NULL))
		{
			first = newn;
			last = newn;
		}
		else
		{
			last->next = newn;
			last = newn;
		}

		last->next = first;
		iSize++;

	 }

	void InsertAtPos(int no ,int iPos)
	{
		PNODE temp = first;
		int i = 0;

		if((iPos < 1)||(iPos > iSize + 1))
		{
			return;
		}
		if(iPos == 1)
		{
			InsertFirst(no);
		}
		else if(iPos == iSize + 1)
		{
			InsertLast(no);
		}
		else
		{
			PNODE newn = new NODE;
			newn-> data = no;
			newn->next = NULL;

			for(i = 1;i < iPos - 1;i++)
			{
				temp = temp->next;

			}
				 newn->next = temp->next;
				 temp->next = newn;

		}

		iSize++;

	}

	void DeleteFirst()
	{	
		if((first == NULL)&&(last == NULL))
		{
			return;
		}

		else if(first == last)
		{
			delete(first);
			first = NULL;
			last = NULL;
		}
		else
		{
			first = first->next;
			delete last->next;
			last->next = first;

		}

		iSize--;

	}
	void DeleteLast()
	{
		PNODE temp = first;
		if((first == NULL)&&(last == NULL))
		{
			return;
		}

		else if(first == last)
		{
			delete(first);
			first = NULL;
			last = NULL;
		}
		else
		{
			while(temp->next != last)
			{
				temp = temp->next;	
			}

				delete last;
				last = temp;
				last->next  = first;	
		
		}

		iSize--;

	}
	void DeleteAtPos(int iPos)
	{
		PNODE temp = first;
		int i = 0;

		if((iPos < 1)||(iPos > iSize + 1))
		{
			return;
		}
		if(iPos == 1)
		{
			DeleteFirst();
		}
		else if(iPos == iSize)
		{
			DeleteLast();
		}
		else
		{
			for(i = 1;i < iPos - 1;i++)
			{
				temp = temp->next;

			}
			PNODE targated = temp->next;
			temp->next = targated->next;
			delete targated;

		}
		iSize--;
	}
};
int main()
{
	SinglyCL obj;
	int iRet = 0;
	obj.InsertFirst(51);
	obj.InsertFirst(21);
	obj.InsertFirst(11);
	obj.InsertLast(101);
	obj.Display();
	iRet = obj.Count();
	cout<<"No of Elements :"<<iRet<<"\n";
	cout<<"______________________________\n";
	
	obj.DeleteFirst();
	obj.DeleteLast();

	obj.Display();
	iRet = obj.Count();
	cout<<"No of Elements :"<<iRet<<"\n";
	cout<<"______________________________\n";

	obj.InsertAtPos(121,2);
	obj.Display();
	iRet = obj.Count();
	cout<<"No of Elements :"<<iRet<<"\n";
	cout<<"______________________________\n";


	obj.InsertAtPos(151,2);
	obj.Display();
	iRet = obj.Count();
	cout<<"No of Elements :"<<iRet<<"\n";
	cout<<"______________________________\n";

	obj.DeleteAtPos(2);
	obj.Display();
	iRet = obj.Count();
	cout<<"No of Elements :"<<iRet<<"\n";
		cout<<"______________________________\n";

	return 0;
}