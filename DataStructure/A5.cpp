#include<iostream>
using namespace std;

typedef struct node
{
	int data;
	struct node*next;

}NODE,*PNODE;

class Queue
{	
private:
		PNODE first;
		int iSize;
	public:	

	Queue()
	{
		first = NULL;
		iSize = 0;
	}

	 void Display();
	 int Count();
	 void Enqueue(int no);
	 int Dequeue();
};

void Queue :: Display()
{
	PNODE temp = first;

/*
	for(i = 1,PNODE temp = first;i <= iSize i++,temp = temp->next)
	{
		cout<<"|"<<temp->data<<"|->";

	}
	cout<<"\n";

*/

	while(temp != NULL)
	{ 
		cout<<temp->data<<"\t";
		temp = temp->next;
	}

	cout<<"\n";
}

int Queue :: Count()
{
 	return iSize;
} 
void Queue :: Enqueue(int no)
{
	PNODE newn = new NODE;
	PNODE temp = first;
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
int Queue :: Dequeue()
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
	Queue obj;
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