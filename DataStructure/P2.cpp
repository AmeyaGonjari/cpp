//Doubly Circular LinkedList

#include<iostream>
using namespace std;

typedef struct node
{
	int data;
	struct node * next;
	struct node * prev;
}NODE,*PNODE,**PPNODE;

class DoublyCL
{
private:
	 PNODE first;
	 PNODE last;
	 int iSize;

public:
	DoublyCL()
	{
		first = NULL;
		last = NULL;
		iSize = 0;
	}

	void Display()
	{	
		PNODE temp = first;
		
		if((first == NULL)&&(last == NULL))
		{
			return;
		}

		do 
		{
			cout<<"|"<<first->data<<"|->";
			first = first->next;
		}
		while(last->next != first);

		cout<<"\n";
	}

	int Count()
	{
		return iSize;
	}

	void InsertFirst(int no)
	{

		PNODE newn = new NODE;
		
		newn->data = no;
		newn->next= NULL;
		newn->prev = NULL;

		if((first == NULL)&&(last == NULL))
		{
			first = newn;
			last = newn;

		}
		else
		{
			newn->next = first;
			newn->prev = last;
			first = newn;
		}

		last->next = first;
		 first->prev = last;
		iSize++;
	}
	void InsertLast(int no)
	{
		PNODE newn = new NODE;
		PNODE temp = first;
		newn->data = no;
		newn->next= NULL;
		newn->prev = NULL;

		if((first == NULL)&&(last == NULL))
		{
			first = newn;
			last = newn;

		}
		else
		{
			last->next = newn;
			newn->prev = last;
			last = newn;
		}

		last->next = first;
		first->prev = last;

		iSize++;
	}
	void InsertAtPos(int no,int iPos)
	{
		PNODE temp = first;
		int  i = 0;
		if((iPos < 1 )&&(iPos > iSize + 1))
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
		newn->data = no;
		newn->next= NULL;
		newn->prev = NULL;

			for(i = 1 ;i< iPos -1;i++)
			{
				temp = temp->next;
			}

			newn->next = temp->next;
			newn->next->prev = newn;
			temp->next = newn;
			newn->prev = temp; 

		}
		iSize++;
	}
	void DeleteFirst()
	{
		PNODE temp = first;

		if((first == NULL)&&(last == NULL))
		{
			return;
		}
		else if(first->next == last->next)
		{
			delete first;
			first = NULL;
			last = NULL;
		}
		else
		{
			first = first->next;
			temp->next->prev = last;
			delete temp;
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
		else if(first->next == last->next)
		{
			delete first;
			first = NULL;
			last = NULL;
		}
		else
		{	
			while(temp -> next != last)
			{
				temp = temp->next;
			}
		
			delete last;
			last = temp;
			last->next = first;
			first->prev = last;
		}
		iSize--;

	}
	void DeleteAtPos(int iPos)
	{
		PNODE temp = first;
		PNODE targated = NULL;
		int  i = 0;
		if((iPos < 1 )&&(iPos > iSize + 1))
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
			for(i = 1 ;i< iPos -1;i++)
			{
				temp = temp->next;
			}
			targated = temp->next;
			temp->next = targated->next;
			targated->next->prev = temp;
			delete targated;

		}
		iSize--;

	}

};

int main()
{
	DoublyCL obj;
	int iRet  = 0;
	obj.InsertFirst(101);
	obj.InsertFirst(51);
	obj.InsertFirst(21);
	obj.InsertFirst(11);
	obj.InsertLast(111);

 	obj.Display();
 	iRet = obj.Count();
 	cout<<"No of Elements present in the LinkedList are : "<<iRet<<"\n";

	obj.DeleteAtPos(3);
	obj.Display();
 	iRet = obj.Count();
 	cout<<"No of Elements present in the LinkedList are : "<<iRet<<"\n";


	obj.InsertAtPos(55,2);
	obj.Display();
 	iRet = obj.Count();
 	cout<<"No of Elements present in the LinkedList are : "<<iRet<<"\n";

 	obj.DeleteFirst();
	obj.Display();
 	iRet = obj.Count();
 	cout<<"No of Elements present in the LinkedList are : "<<iRet<<"\n";

	obj.DeleteLast();
	obj.Display();
 	iRet = obj.Count();
 	cout<<"No of Elements present in the LinkedList are : "<<iRet<<"\n";


	obj.DeleteAtPos(2);
	obj.Display();
 	iRet = obj.Count();
 	cout<<"No of Elements present in the LinkedList are : "<<iRet<<"\n";
	
	
	return 0;
}