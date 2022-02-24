#include<iostream>
using namespace std;

template <class T>

typedef struct node
{
	int data;
	struct node*next;

}NODE,*PNODE;

class Stact
{	
private:
		PNODE first;
		int iSize;
	public:	

	Stact()
	{
		first = NULL;
		iSize = 0;
	}

	 void Display();
	 int Count();
	 void Push(int no);
	 int POP();
};

void Stact :: Display()
{
	PNODE temp = first;

	while(temp != NULL)
	{ 
		cout<<temp->data<<"\t";
		temp = temp->next;
	}

	cout<<"\n";
}

int Stact :: Count()
{
 	return iSize;
} 


void Stact :: Push(int no)
{
	PNODE newn = new NODE;
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

int Stact :: POP()
{
		PNODE temp = first;
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
	Stact obj;
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