#include<iostream>
using namespace std;

typedef struct  node
{	
	int data;
	struct node *next;
	struct node *prev;
}NODE,*PNODE;

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
		void Display();
		int  Count();
		void InsertFirst(int no);
		void InsertLast(int no );
		void InsertAtPos(int no ,int iPos );
		void DeleteFirst();
		void DeleteLast();
		void DeleteAtPos(int iPos);
};

// return_value class_name :: Function_Name(Parameter)

 void DoublyCL :: InsertFirst(int no)
 {
 	PNODE newn = new NODE;
 	newn->data = no;
 	newn->next = NULL;
 	newn->prev = NULL;

 	if((first == NULL)&&(last == NULL))
 	{
 		first = newn;
 		last = newn;
 	}
 	else
 	{
 		newn->next = first;
 		first->prev = newn;
 		first = newn;
 	}

 	last->next = first;
 	first->prev = last;
 	iSize++;
 }

 void DoublyCL :: InsertLast(int no)
 {
 	PNODE newn = new NODE;
 	newn->data = no;
 	newn->next = NULL;
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

 void DoublyCL :: Display()
 {	
 	PNODE temp = first;
 	int i = 0;
 	for(i = 1;i<= iSize ;i++)
 	{
 		cout<<"|"<<temp->data<<"|-> ";
 		temp = temp->next;
 	}
 		cout<<"\n";
 }

  int DoublyCL :: Count()
 {	
 	return iSize;
 }

void DoublyCL :: DeleteFirst()
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
		first->prev = last;
		last->next = first;
	}
		iSize--;
}
void DoublyCL :: DeleteLast()
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
		last = last->prev;
		delete last->next;
		first->prev = last;
		last->next = first;	
	}
	iSize--;
}
void DoublyCL :: InsertAtPos(int no,int iPos)
{
	if((iPos < 1)||(iPos > iSize+1))
	{
		return;
	}
	 if(iPos == 1)
	{
		InsertFirst(no);
	}
	else if(iPos == iSize+1)
	{
		InsertLast(no);
	}
	else
	{
		PNODE newn = new NODE;
		newn->data = no;
		newn->next = NULL;
		newn->next = NULL;
		PNODE temp = first;

		for(int i = 0;i< iPos -1 ;i++)
		{
			temp = temp->next;
		}

		newn->next = temp->next;
		temp->next->prev = newn;
		temp->next = newn;		
		newn->prev = temp;
		iSize++;
	}
		last->next = first;
		first->prev = last; 

}
void DoublyCL :: DeleteAtPos(int iPos)
{
	PNODE temp = first;
	if((iPos < 1)||(iPos > iSize+1))
	{
		return;
	}
	 if(iPos == 1)
	{
		DeleteFirst();
	}
	else if(iPos == iSize+1)
	{
		DeleteLast();
	}
	else
	{
		for(int i = 1;i< iPos -1 ;i++)
		{
			temp = temp->next;
		}

		temp->next = temp->next->next;
		delete temp->next->prev;
		temp->next->prev = temp;

		iSize--;	
		/*
		PNODE targated = temp->next;
		temp->next = targated->next;
		targated->next->prev = temp;
		delete targated;
		iSize--;
		*/
	}
	
}
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