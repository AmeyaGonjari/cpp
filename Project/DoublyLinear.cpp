//Doubly Circular LinkedList

#include<iostream>
using namespace std;

template <typename T>
 struct node
{
	T data;
	struct node * next;
	struct node * prev;
};

template <class T>
class DoublyCL
{
private:
	 node <T>* first;
	 node <T>* last;
	 int iSize;

public:
	DoublyCL();
	void InsertFirst(T);
	void InsertLast(T);
	void InsertAtPos(T,int);
	void DeleteFirst();
	void DeleteLast();
	void DeleteAtPos(int);
	void Display();
	int Count(); 
	
};
template <class T>
DoublyCL<T>::DoublyCL()
	{
		first = NULL;
		last = NULL;
		iSize = 0;
	}
template <class T>
	void DoublyCL<T>:: Display()
	{	
		node <T>* temp = first;
		
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
template <class T>
	int DoublyCL<T>::Count()
	{
		return iSize;
	}
template <class T>
	void DoublyCL<T>::InsertFirst(T no)
	{

		node <T>* newn = new node <T>;
		
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
	template <class T>
	void DoublyCL<T>::InsertLast(T no)
	{
		node <T>* newn = new node <T>;
		node <T>* temp = first;
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
	template <class T>
	void DoublyCL<T>::InsertAtPos(T no,int iPos)
	{
		node <T>* temp = first;
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

		node <T>* newn = new node <T>;
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
	template <class T>
	void DoublyCL<T>::DeleteFirst()
	{
		node <T>* temp = first;

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
	template <class T>
	void DoublyCL<T>::DeleteLast()
	{

		node <T>* temp = first;

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
	template <class T>
	void DoublyCL<T>::DeleteAtPos(int iPos)
	{
		node <T>* temp = first;
		node <T>* targated = NULL;
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

int main()
{
	DoublyCL <int>obj;
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