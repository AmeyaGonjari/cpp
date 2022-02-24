#include<iostream>
using namespace std;

template <typename T>
struct node
{
     T data;
    struct node *next;
};

template <class T>
class SinglyLL
{
private:

    node<T>* first;
    int size;

public :    
SinglyLL();
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
  SinglyLL <T> :: SinglyLL()
    {
        first = NULL;
        size = 0;
    }
  
  template <class T>
    void  SinglyLL<T> ::InsertFirst(T no)
    {
         node<T>* newn = new node<T>;  // newn = (struct node *)malloc(sizeof(NODE))
        
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
        size++;
    }

    template <class T>
    void  SinglyLL<T> ::InsertLast(T no)
    {
     node <T>* newn = new node<T>;  // newn = (struct node *)malloc(sizeof(NODE))
        
        newn->data = no;
        newn->next = NULL;
        
        if(first == NULL)
        {
            first = newn;
        }
        else
        {
             node<T> * temp = first;
            
            while(temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = newn;
        }
        size++;
    }

    template <class T>
    void SinglyLL<T> :: InsertAtPos(T no, int ipos)
    {
        int i = 1;
        if((ipos < 1)&&(ipos > size+1))
        {
            return;
        }
        if(ipos == 1)
        {
            InsertFirst(no);
        }
        else if(ipos == size)
        {

            InsertLast(no);
        }
        else
        {
            node<T>* newn = new node<T>;  
        
            newn->data = no;
            newn->next = NULL;
            node<T> * temp = first;
            
            for(i = 1;i<ipos-1;i++)
            {
                temp = temp->next;

            }

            newn->next = temp->next;
            temp->next = newn;

        }
        size++;
    }

    template <class T>    
    void SinglyLL <T>:: DeleteFirst()
    {
         node<T> * temp = first;
        
        if(first != NULL)
        {
            first = first->next;
            delete temp;
            
            size--;
        }
    }
    
    template <class T>
    void  SinglyLL<T> ::DeleteLast()
    {
         node<T> * temp = first;
        
        if(first == NULL)
        {
            return;
        }
        else if(first->next == NULL)
        {
            delete first;
            first = NULL;
            size--;
        }
        else
        {
            while(temp->next->next != NULL)
            {
                temp = temp->next;
            }
            
            delete temp->next;
            temp->next = NULL;
            size--;
        }
    }

    template <class T>
    void  SinglyLL<T> ::DeleteAtPos(int ipos)
    {

        int i = 1;
        if((ipos < 1)&&(ipos > size+1))
        {
            return;
        }
        if(ipos == 1)
        {
            DeleteFirst();
        }
        else if(ipos == size)
        {

            DeleteLast();
        }
        else
        {
            int i = 0;   
            node<T> * targated = NULL;
            node<T> * temp = first;
            
            for(i = 1;i<ipos-1;i++)
            {
                temp = temp->next;

            }

            targated = temp->next;
            temp->next = targated->next;
            delete targated;

        }
        size--;



    }
    
    template <class T>
    void  SinglyLL<T> ::Display()
    {
         node<T> * temp = first;
        
        while(temp!= NULL)
        {
            cout<<temp->data<<"\t";
            temp = temp->next;
        }
        cout<<"\n";
    }
    
    template <class T>
    int  SinglyLL<T> ::Count()
    {
        return size;
    }


///////////////////////////////////////////////////////////////////

int main()
{
    SinglyLL <int> obj;
    int iret = 0;
    
    obj.InsertFirst(51);
    obj.InsertFirst(21);
    obj.InsertFirst(11);
    obj.InsertLast(101);
    obj.InsertLast(111);
     obj.Display();
    iret = obj.Count();
    cout<<"Number of elemensts are : "<<iret<<"\n";

    obj.InsertAtPos(55,2);
     obj.Display();
    iret = obj.Count();
    cout<<"Number of elemensts are : "<<iret<<"\n";


    obj.DeleteAtPos(2);
     obj.Display();
    iret = obj.Count();
    cout<<"Number of elemensts are : "<<iret<<"\n";


    SinglyLL <char> cobj;
    
    cobj.InsertFirst('A');
    cobj.InsertFirst('B');
    cobj.InsertFirst('C');
    cobj.InsertLast('D');
    cobj.Display();
    iret = cobj.Count();
    cout<<"Number of elemensts are : "<<iret<<"\n";
    
    return 0;
}




