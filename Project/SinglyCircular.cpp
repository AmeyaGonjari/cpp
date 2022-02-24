#include<iostream>
using namespace std;

template <typename T>
struct node
{
	T data;
	struct node*next;
};

template<class T>
class SinglyCL
{
private:
	node <T>* first;
	node <T>* last;
	int iSize;

public:

	SinglyCL();
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
SinglyCL<T>::SinglyCL()
	{	
		first = NULL;
		last = NULL;
		iSize = 0;
	}

	template <class T>
	void SinglyCL<T>::Display()
	{	
		node <T>* temp = first;
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

template<class T>
	int SinglyCL<T>::Count()
	{
		return iSize;
	}

template<class T>
	void SinglyCL<T>::InsertFirst(T no)
	{
		node <T>* newn  = new node <T>;
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

template<class T>
	void SinglyCL<T>::InsertLast(T no)
	{
 		
	node <T>* newn  = new node <T>;
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

template<class T>
	void SinglyCL<T>::InsertAtPos(T no ,int iPos)
	{
		node <T>* temp = first;
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
			node <T>* newn = new node <T>;
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

template<class T>
	void SinglyCL<T>::DeleteFirst()
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


template<class T>
	void SinglyCL<T>::DeleteLast()
	{
		node <T>* temp = first;
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

template<class T>
	void SinglyCL<T>::DeleteAtPos(int iPos)
	{
		node <T>* temp = first;
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
			node <T>* targated = temp->next;
			temp->next = targated->next;
			delete targated;
		}
		iSize--;
	}
int main()
{
	SinglyCL<int> obj;
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