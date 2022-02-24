#include<iostream>
using namespace std;


template<typename T>
 struct node
{
	int data;
	struct node*next;

};


template<class T>
class Stack
{	
private:
		node<T>* first;
		int iSize;

	public:	
	
	 Stack();
	 void Display();
	 int Count();
	 void Push(T no);
	 int POP();
};
template<class T>

	Stack<T>::Stack()
	{
		first = NULL;
		iSize = 0;
	}

template<class T>

void Stack<T> :: Display()
{
	node<T>* temp = first;

	while(temp != NULL)
	{ 
		cout<<"|"<<temp->data<<"|"<<"\n";
		temp = temp->next;
	}
	cout<<"\n";
}
template<class T>

int Stack <T>:: Count()
{
 	return iSize;
} 

template<class T>

void Stack<T> :: Push(T no)
{
	node<T>* newn = new node<T>;
	newn->data = no;
	newn->next = NULL;

	if(first == NULL)
	{
		first = newn;
	}
	else
	{
		newn->next = first;
		first = newn;
	}
	iSize++;
}

template<class T>

int Stack<T> :: POP()
{
		node<T>* temp = first;
		int Val =0;

		 if(first != NULL)
		 {
		 		Val = temp->data;
		 		first= first->next;
		 		delete(temp);

		 		iSize--;
		 }

		 return Val;
}

int main()
{
	Stack <int>obj;
	int iRet = 0;
	int iRet1 =0;

 	 obj.Push(101);
	 obj.Push(51);
	 obj.Push(21);
	 obj.Push(11);

	 obj.Display();
	 iRet1 = obj.Count();
	cout<<"No  of elemts are:"<<iRet1<<"\n";
	
	iRet = obj.POP();

	obj.Display();
	iRet1 = obj.Count();
	cout<<"You have POPED ->"<<iRet<<"\n";
	cout<<"No  of elemts are:"<<iRet1<<"\n"; 

	return 0;
}