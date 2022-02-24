#include<iostream>
using namespace std;

template <typename T>
struct node
{
     T data;
    struct node<T> *next;
};



template <typename T>
 struct node1
{
     T data;
     struct node1<T>* next;
     struct node1<T> * prev;
};



//////////////////////////////////////////////////////////////
//Singly Linear LinkedList



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



//constructor

 template <class T>
  SinglyLL <T> :: SinglyLL()
    {
        first = NULL;
        size = 0;
    }
  

//Insert First

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
    {}
    
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
/////////////////////////////////////////////////////////////////////////
//Singly Circular
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

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Doubly LinearLinked List

template <class T>
class DoublyLL
{
private:
      node1 <T>* first;
      node1 <T>* last;
      int iSize;

public:
     DoublyLL();
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
DoublyLL<T>::DoublyLL()
     {
          first = NULL;
          last = NULL;
          iSize = 0;
     }
template <class T>
     void DoublyLL<T>:: Display()
     {    
          node1 <T>* temp = first;
          
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
     int DoublyLL<T>::Count()
     {
          return iSize;
     }
template <class T>
     void DoublyLL<T>::InsertFirst(T no)
     {

          node1 <T>* newn = new node1 <T>;
          
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
     void DoublyLL<T>::InsertLast(T no)
     {
          node1 <T>* newn = new node1 <T>;
          node1 <T>* temp = first;
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
     void DoublyLL<T>::InsertAtPos(T no,int iPos)
     {
          node1 <T>* temp = first;
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

          node1 <T>* newn = new node1 <T>;
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
     void DoublyLL<T>::DeleteFirst()
     {
          node1 <T>* temp = first;

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
     void DoublyLL<T>::DeleteLast()
     {

          node1 <T>* temp = first;

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
     void DoublyLL<T>::DeleteAtPos(int iPos)
     {
          node1 <T>* temp = first;
          node1 <T>* targated = NULL;
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
     ///////////////////////////////////////////////////////////////////////////////////
//Doubly Circular
template<class T>
class DoublyCL
{
private:
     node1 <T>* first;
     node1 <T>* last;
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
          void InsertFirst(T no);
          void InsertLast(T no );
          void InsertAtPos(T no ,int iPos );
          void DeleteFirst();
          void DeleteLast();
          void DeleteAtPos(int iPos);
};

// return_value class_name :: Function_Name(Parameter)

 template<class T>
 void DoublyCL<T> :: InsertFirst(T no)
 {
     node1 <T>* newn = new node1 <T>;
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
template<class T>
 void DoublyCL<T> :: InsertLast(T no)
 {
     node1 <T>* newn = new node1 <T>;
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
template<class T>
 void DoublyCL<T> :: Display()
 {   
     node1 <T>* temp = first;
     int i = 0;
     for(i = 1;i<= iSize ;i++)
     {
          cout<<"|"<<temp->data<<"|-> ";
          temp = temp->next;
     }
          cout<<"\n";
 }
template<class T>
  int DoublyCL<T> :: Count()
 {   
     return iSize;
 }

template<class T>

void DoublyCL<T> :: DeleteFirst()
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
template<class T>
void DoublyCL<T> :: DeleteLast()
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
template<class T>
void DoublyCL<T> :: InsertAtPos(T no,int iPos)
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
          node1 <T>* newn = new node1 <T>;
          newn->data = no;
          newn->next = NULL;
          newn->next = NULL;
          node1 <T>* temp = first;

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
template<class T>
void DoublyCL<T> :: DeleteAtPos(int iPos)
{
     node1 <T>* temp = first;
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
          node <T>* targated = temp->next;
          temp->next = targated->next;
          targated->next->prev = temp;
          delete targated;
          iSize--;
          */
     }
     
}

int main()
{
     int iret = 0;

    SinglyLL <int> SLobj1;
    SLobj1.InsertFirst(51);
    SLobj1.InsertFirst(21);
    SLobj1.InsertFirst(11);
    SLobj1.InsertLast(101);
    SLobj1.InsertLast(111);
     SLobj1.InsertFirst(51);
 //   SLobj1.DeleteLast(101);


    SLobj1.Display();
    iret = SLobj1.Count();
    cout<<"Number of elemensts are : "<<iret<<"\n";

    SinglyLL <char> SLobj2;
    
    SLobj2.InsertFirst('A');
    SLobj2.InsertFirst('B');
    SLobj2.InsertFirst('C');
    SLobj2.InsertLast('D');
    SLobj2.Display();
    iret = SLobj2.Count();
    cout<<"Number of elemensts are : "<<iret<<"\n";

cout<<"__________________________________________________________\n";
     
     DoublyLL <int> DLobj1;
    DLobj1.InsertFirst(51);
    DLobj1.InsertFirst(21);
    DLobj1.InsertFirst(11);
    DLobj1.InsertLast(101);
    DLobj1.InsertLast(111);
     DLobj1.Display();
    iret = DLobj1.Count();
    cout<<"Number of elemensts are : "<<iret<<"\n";

    SinglyLL <char> DLobj2;
    
    DLobj2.InsertFirst('A');
    DLobj2.InsertFirst('B');
    DLobj2.InsertFirst('C');
    DLobj2.InsertLast('D');
    DLobj2.Display();
    iret = DLobj2.Count();
    cout<<"Number of elemensts are : "<<iret<<"\n";

cout<<"__________________________________________________________\n";
     


     SinglyCL <int> SCobj1;

    SCobj1.InsertFirst(51);
    SCobj1.InsertFirst(21);
    SCobj1.InsertFirst(11);
    SCobj1.InsertLast(101);
SCobj1.InsertLast(111);
     SCobj1.Display();
    iret = SCobj1.Count();
    cout<<"Number of elemensts are : "<<iret<<"\n";

    SinglyLL <char> SCobj2;
    
    SCobj2.InsertFirst('A');
    SCobj2.InsertFirst('B');
    SCobj2.InsertFirst('C');
    SCobj2.InsertLast('D');
    SCobj2.Display();
    iret = SCobj2.Count();
    cout<<"Number of elemensts are : "<<iret<<"\n";

cout<<"__________________________________________________________\n";
     
     DoublyCL <int> obj;

    obj.InsertFirst(51);
    obj.InsertFirst(21);
    obj.InsertFirst(11);
    obj.InsertLast(101);
    obj.InsertLast(111);
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

cout<<"__________________________________________________________\n";
     
     
     return 0;
}