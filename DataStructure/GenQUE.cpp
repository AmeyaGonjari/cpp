#include<iostream>
using namespace std;

template <typename T>
struct node
{
     T data;
    struct node *next;
};

template <class T>
class Queue
{
private:

    node<T>* first;
    int iSize;
public:

	 Queue();
	 void Display();
	 int Count();
	 void Enqueue(T no);
	 int Dequeue();
};


template<class T>
	
	Queue<T>::Queue()
	{
		first = NULL;
		iSize = 0;
	}


template<class T>

void Queue <T>:: Display()
{
	node<T>* temp = first;

	while(temp != NULL)
	{ 
		cout<<temp->data<<"\t";
		temp = temp->next;
	}

	cout<<"\n";
}

template<class T>
int Queue <T> :: Count()
{
 	return iSize;
}

template<class T>
void Queue<T> :: Enqueue(T no)
{
	node<T>* newn = new node<T>;
	node<T>* temp = first;
	newn->data = no;
	newn->next = NULL;
	if(first == NULL)
	{
		first = newn;
	}
	else
	{
		while(temp->next != NULL)
		{
			temp = temp->next;
		}
		temp->next = newn;
	}
	iSize++;			
}

template<class T>

int Queue <T> :: Dequeue()
{
		node<T>* temp = first;
		int Val =0 ;
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
	Queue <int> obj;
	int iRet = 0;
	int iRet1 =0;
 	 obj.Enqueue(11);
	 obj.Enqueue(21);
	 obj.Enqueue(51);
	 obj.Enqueue(101);

	 obj.Display();
	 iRet1 = obj.Count();
	cout<<"No  of elemts are:"<<iRet1<<"\n";
 	iRet = obj.Dequeue();
	obj.Display();
	iRet1 = obj.Count();
	cout<<"You have DequeueED ->"<<iRet<<"\n";
	cout<<"No  of elemts are:"<<iRet1<<"\n"; 

	return 0;
}