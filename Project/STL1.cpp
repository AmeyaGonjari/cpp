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

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


int main()
{
     int iChoice = 1;
     int iChoice1 = 1;
     int iPos = 0;
     int iRet = 0;
     int iValue = 0;

     while(iChoice1 != 0)
     {
           cout<<"Enter your Linked List Choice \n";
           cout<<"1: Singly Linear LinkedList\n";
           cout<<"2: Doubly Linear LinkedList\n";
           cout<<"3: Singly Circular Linear LinkedList\n";
           cout<<"4: Doubly Linear LinkedList\n";
           cout<<"0: Thankyou for using Ameya's LinkedList \n";
           scanf("%d",iChoice1);

          switch(iChoice1)
          {
    
               case 1:
               
               SinglyLL <int> SLobj1;
               while(iChoice != 0)
               {
                    cout<<"___________________________________________________\n";
                    cout<<"Enter your Choice:\n";
                    cout<<"1 : Insert your data At First \n";
                    cout<<"2 : Insert your data At Last \n";
                    cout<<"3 : Insert your data At Given Position \n";
                    cout<<"4 : Delete your data At First \n";
                    cout<<"5 : Delete your data At Last \n";
                    cout<<"6 : Delete your data At Given Position \n";
                    cout<<"7 : Display the data from your LinkedList \n";
                    cout<<"8 : Count the elements from your LinkedList \n";
                    cout<<"0 : Terminate your LinkedList \n";
                    cout<<"___________________________________________________\n";
                    cin>>iChoice;

                    switch(iChoice)
                    {
                         case 1:
                         cout<<"Enter your data for Insertion\n";
                         cin>>iValue;
                         SLobj1.InsertFirst(iValue);
                         break;
               
                         case 2:
                         cout<<"Enter your data for Insertion\n";
                         cin>>iValue;
                         SLobj1.InsertLast(iValue);
                         break;

                         case 3:
                         cout<<"Enter your data for Insertion\n";
                         cin>>iValue;
                         cout<<"Enter your Position\n";
                         cin>>iPos;
                         SLobj1.InsertAtPos(iValue,iPos);
                         break;

                         case 4:
                         SLobj1.DeleteFirst();
                         break;
               
                         case 5:
                         SLobj1.DeleteLast();
                         break;

                         case 6:
                         cout<<"Enter your Position\n";
                         cin>>iPos;
                         SLobj1.DeleteAtPos(iPos);
                         break;
              
                          case 7:
                         cout<<"Elements from  your LinkedList is :\n";
                         SLobj1.Display();
                         break;
                    
                         case 8:
                         iRet = SLobj1.Count();
                         cout<<"Count of your elements from LinkedList is %d\n",iRet;
                         break;
              
                          case 0:
                         cout<<"Thankyou for using Ameya's LinkedList\n";               
                         break;
          
                          default:
                         cout<<"INVALID DATA\n";

                     }

                }

               SinglyLL <char> SLobj2;
               while(iChoice != 0)
               {
                    cout<<"___________________________________________________\n";
                    cout<<"Enter your Choice:\n";
                    cout<<"1 : Insert your data At First \n";
                    cout<<"2 : Insert your data At Last \n";
                    cout<<"3 : Insert your data At Given Position \n";
                    cout<<"4 : Delete your data At First \n";
                    cout<<"5 : Delete your data At Last \n";
                    cout<<"6 : Delete your data At Given Position \n";
                    cout<<"7 : Display the data from your LinkedList \n";
                    cout<<"8 : Count the elements from your LinkedList \n";
                    cout<<"0 : Terminate your LinkedList \n";
                    cout<<"___________________________________________________\n";
                    cin>>iChoice;

                    switch(iChoice)
                    {
                         case 1:
                         cout<<"Enter your data for Insertion\n";
                         cin>>iValue;
                         SLobj2.InsertFirst(iValue);
                         break;
               
                         case 2:
                         cout<<"Enter your data for Insertion\n";
                         cin>>iValue;
                         SLobj2.InsertLast(iValue);
                         break;

                         case 3:
                         cout<<"Enter your data for Insertion\n";
                         cin>>iValue;
                         cout<<"Enter your Position\n";
                         cin>>iPos;
                         SLobj2.InsertAtPos(iValue,iPos);
                         break;

                         case 4:
                         SLobj2.DeleteFirst();
                         break;
               
                         case 5:
                         SLobj2.DeleteLast();
                         break;

                         case 6:
                         cout<<"Enter your Position\n";
                         cin>>iPos;
                         SLobj2.DeleteAtPos(iPos);
                         break;
              
                          case 7:
                         cout<<"Elements from  your LinkedList is :\n";
                         SLobj2.Display();
                         break;
                    
                         case 8:
                         iRet = SLobj2.Count();
                         cout<<"Count of your elements from LinkedList is %d\n",iRet;
                         break;
              
                          case 0:
                         cout<<"Thankyou for using Ameya's LinkedList\n";               
                         break;
          
                          default:
                         cout<<"INVALID DATA\n";

                     }

                }


               case 2:
               DoublyLL <int> DLobj1;
               while(iChoice != 0)
               {
                    cout<<"___________________________________________________\n";
                    cout<<"Enter your Choice:\n";
                    cout<<"1 : Insert your data At First \n";
                    cout<<"2 : Insert your data At Last \n";
                    cout<<"3 : Insert your data At Given Position \n";
                    cout<<"4 : Delete your data At First \n";
                    cout<<"5 : Delete your data At Last \n";
                    cout<<"6 : Delete your data At Given Position \n";
                    cout<<"7 : Display the data from your LinkedList \n";
                    cout<<"8 : Count the elements from your LinkedList \n";
                    cout<<"0 : Terminate your LinkedList \n";
                    cout<<"___________________________________________________\n";
                    cin>>iChoice;

                    switch(iChoice)
                    {
                         case 1:
                         cout<<"Enter your data for Insertion\n";
                         cin>>iValue;
                         DLobj1.InsertFirst(iValue);
                         break;
               
                         case 2:
                         cout<<"Enter your data for Insertion\n";
                         cin>>iValue;
                         DLobj1.InsertLast(iValue);
                         break;

                         case 3:
                         cout<<"Enter your data for Insertion\n";
                         cin>>iValue;
                         cout<<"Enter your Position\n";
                         cin>>iPos;
                         DLobj1.InsertAtPos(iValue,iPos);
                         break;

                         case 4:
                         DLobj1.DeleteFirst();
                         break;
               
                         case 5:
                         DLobj1.DeleteLast();
                         break;

                         case 6:
                         cout<<"Enter your Position\n";
                         cin>>iPos;
                         DLobj1.DeleteAtPos(iPos);
                         break;
              
                          case 7:
                         cout<<"Elements from  your LinkedList is :\n";
                         DLobj1.Display();
                         break;
                    
                         case 8:
                         iRet = DLobj1.Count();
                         cout<<"Count of your elements from LinkedList is %d\n",iRet;
                         break;
              
                          case 0:
                         cout<<"Thankyou for using Ameya's LinkedList\n";               
                         break;
          
                          default:
                         cout<<"INVALID DATA\n";

                     }

                }

  
               DoublyLL <char> DLobj2;
               while(iChoice != 0)
               {
                    cout<<"___________________________________________________\n";
                    cout<<"Enter your Choice:\n";
                    cout<<"1 : Insert your data At First \n";
                    cout<<"2 : Insert your data At Last \n";
                    cout<<"3 : Insert your data At Given Position \n";
                    cout<<"4 : Delete your data At First \n";
                    cout<<"5 : Delete your data At Last \n";
                    cout<<"6 : Delete your data At Given Position \n";
                    cout<<"7 : Display the data from your LinkedList \n";
                    cout<<"8 : Count the elements from your LinkedList \n";
                    cout<<"0 : Terminate your LinkedList \n";
                    cout<<"___________________________________________________\n";
                    cin>>iChoice;

                    switch(iChoice)
                    {
                         case 1:
                         cout<<"Enter your data for Insertion\n";
                         cin>>iValue;
                         DLobj2.InsertFirst(iValue);
                         break;
               
                         case 2:
                         cout<<"Enter your data for Insertion\n";
                         cin>>iValue;
                         DLobj2.InsertLast(iValue);
                         break;

                         case 3:
                         cout<<"Enter your data for Insertion\n";
                         cin>>iValue;
                         cout<<"Enter your Position\n";
                         cin>>iPos;
                         DLobj2.InsertAtPos(iValue,iPos);
                         break;

                         case 4:
                         DLobj2.DeleteFirst();
                         break;
               
                         case 5:
                         DLobj2.DeleteLast();
                         break;

                         case 6:
                         cout<<"Enter your Position\n";
                         cin>>iPos;
                         DLobj2.DeleteAtPos(iPos);
                         break;
              
                          case 7:
                         cout<<"Elements from  your LinkedList is :\n";
                         DLobj2.Display();
                         break;
                    
                         case 8:
                         iRet = DLobj2.Count();
                         cout<<"Count of your elements from LinkedList is %d\n",iRet;
                         break;
              
                          case 0:
                         cout<<"Thankyou for using Ameya's LinkedList\n";               
                         break;
          
                          default:
                         cout<<"INVALID DATA\n";

                     }

                }

               case 3:
               SinglyCL <int> SCobj1;
               while(iChoice != 0)
               {
                    cout<<"___________________________________________________\n";
                    cout<<"Enter your Choice:\n";
                    cout<<"1 : Insert your data At First \n";
                    cout<<"2 : Insert your data At Last \n";
                    cout<<"3 : Insert your data At Given Position \n";
                    cout<<"4 : Delete your data At First \n";
                    cout<<"5 : Delete your data At Last \n";
                    cout<<"6 : Delete your data At Given Position \n";
                    cout<<"7 : Display the data from your LinkedList \n";
                    cout<<"8 : Count the elements from your LinkedList \n";
                    cout<<"0 : Terminate your LinkedList \n";
                    cout<<"___________________________________________________\n";
                    cin>>iChoice;

                    switch(iChoice)
                    {
                         case 1:
                         cout<<"Enter your data for Insertion\n";
                         cin>>iValue;
                         SCobj1.InsertFirst(iValue);
                         break;
               
                         case 2:
                         cout<<"Enter your data for Insertion\n";
                         cin>>iValue;
                         SCobj1.InsertLast(iValue);
                         break;

                         case 3:
                         cout<<"Enter your data for Insertion\n";
                         cin>>iValue;
                         cout<<"Enter your Position\n";
                         cin>>iPos;
                         SCobj1.InsertAtPos(iValue,iPos);
                         break;

                         case 4:
                         SCobj1.DeleteFirst();
                         break;
               
                         case 5:
                         SCobj1.DeleteLast();
                         break;

                         case 6:
                         cout<<"Enter your Position\n";
                         cin>>iPos;
                         SCobj1.DeleteAtPos(iPos);
                         break;
              
                          case 7:
                         cout<<"Elements from  your LinkedList is :\n";
                         SCobj1.Display();
                         break;
                    
                         case 8:
                         iRet = SCobj1.Count();
                         cout<<"Count of your elements from LinkedList is %d\n",iRet;
                         break;
              
                          case 0:
                         cout<<"Thankyou for using Ameya's LinkedList\n";               
                         break;
          
                          default:
                         cout<<"INVALID DATA\n";

                     }

                }


    

               SinglyCL <char> SCobj2;
               while(iChoice != 0)
               {
                    cout<<"___________________________________________________\n";
                    cout<<"Enter your Choice:\n";
                    cout<<"1 : Insert your data At First \n";
                    cout<<"2 : Insert your data At Last \n";
                    cout<<"3 : Insert your data At Given Position \n";
                    cout<<"4 : Delete your data At First \n";
                    cout<<"5 : Delete your data At Last \n";
                    cout<<"6 : Delete your data At Given Position \n";
                    cout<<"7 : Display the data from your LinkedList \n";
                    cout<<"8 : Count the elements from your LinkedList \n";
                    cout<<"0 : Terminate your LinkedList \n";
                    cout<<"___________________________________________________\n";
                    cin>>iChoice;

                    switch(iChoice)
                    {
                         case 1:
                         cout<<"Enter your data for Insertion\n";
                         cin>>iValue;
                         SCobj2.InsertFirst(iValue);
                         break;
               
                         case 2:
                         cout<<"Enter your data for Insertion\n";
                         cin>>iValue;
                         SCobj2.InsertLast(iValue);
                         break;

                         case 3:
                         cout<<"Enter your data for Insertion\n";
                         cin>>iValue;
                         cout<<"Enter your Position\n";
                         cin>>iPos;
                         SCobj2.InsertAtPos(iValue,iPos);
                         break;

                         case 4:
                         SCobj2.DeleteFirst();
                         break;
               
                         case 5:
                         SCobj2.DeleteLast();
                         break;

                         case 6:
                         cout<<"Enter your Position\n";
                         cin>>iPos;
                         SCobj2.DeleteAtPos(iPos);
                         break;
              
                          case 7:
                         cout<<"Elements from  your LinkedList is :\n";
                         SCobj2.Display();
                         break;
                    
                         case 8:
                         iRet = SCobj2.Count();
                         cout<<"Count of your elements from LinkedList is %d\n",iRet;
                         break;
              
                          case 0:
                         cout<<"Thankyou for using Ameya's LinkedList\n";               
                         break;
          
                          default:
                         cout<<"INVALID DATA\n";

                     }

                }

               

               case 4:  
               DoublyCL <int> DCobj1;
               while(iChoice != 0)
               {
                    cout<<"___________________________________________________\n";
                    cout<<"Enter your Choice:\n";
                    cout<<"1 : Insert your data At First \n";
                    cout<<"2 : Insert your data At Last \n";
                    cout<<"3 : Insert your data At Given Position \n";
                    cout<<"4 : Delete your data At First \n";
                    cout<<"5 : Delete your data At Last \n";
                    cout<<"6 : Delete your data At Given Position \n";
                    cout<<"7 : Display the data from your LinkedList \n";
                    cout<<"8 : Count the elements from your LinkedList \n";
                    cout<<"0 : Terminate your LinkedList \n";
                    cout<<"___________________________________________________\n";
                    cin>>iChoice;

                    switch(iChoice)
                    {
                         case 1:
                         cout<<"Enter your data for Insertion\n";
                         cin>>iValue;
                         DCobj1.InsertFirst(iValue);
                         break;
               
                         case 2:
                         cout<<"Enter your data for Insertion\n";
                         cin>>iValue;
                         DCobj1.InsertLast(iValue);
                         break;

                         case 3:
                         cout<<"Enter your data for Insertion\n";
                         cin>>iValue;
                         cout<<"Enter your Position\n";
                         cin>>iPos;
                         DCobj1.InsertAtPos(iValue,iPos);
                         break;

                         case 4:
                         DCobj1.DeleteFirst();
                         break;
               
                         case 5:
                         DCobj1.DeleteLast();
                         break;

                         case 6:
                         cout<<"Enter your Position\n";
                         cin>>iPos;
                         DCobj1.DeleteAtPos(iPos);
                         break;
              
                          case 7:
                         cout<<"Elements from  your LinkedList is :\n";
                         DCobj1.Display();
                         break;
                    
                         case 8:
                         iRet = DCobj1.Count();
                         cout<<"Count of your elements from LinkedList is %d\n",iRet;
                         break;
              
                          case 0:
                         cout<<"Thankyou for using Ameya's LinkedList\n";               
                         break;
          
                          default:
                         cout<<"INVALID DATA\n";

                     }

                }

    
   
               DoublyCL <char> DCobj2;
               while(iChoice != 0)
               {
                    cout<<"___________________________________________________\n";
                    cout<<"Enter your Choice:\n";
                    cout<<"1 : Insert your data At First \n";
                    cout<<"2 : Insert your data At Last \n";
                    cout<<"3 : Insert your data At Given Position \n";
                    cout<<"4 : Delete your data At First \n";
                    cout<<"5 : Delete your data At Last \n";
                    cout<<"6 : Delete your data At Given Position \n";
                    cout<<"7 : Display the data from your LinkedList \n";
                    cout<<"8 : Count the elements from your LinkedList \n";
                    cout<<"0 : Terminate your LinkedList \n";
                    cout<<"___________________________________________________\n";
                    cin>>iChoice;

                    switch(iChoice)
                    {
                         case 1:
                         cout<<"Enter your data for Insertion\n";
                         cin>>iValue;
                         DCobj2.InsertFirst(iValue);
                         break;
               
                         case 2:
                         cout<<"Enter your data for Insertion\n";
                         cin>>iValue;
                         DCobj2.InsertLast(iValue);
                         break;

                         case 3:
                         cout<<"Enter your data for Insertion\n";
                         cin>>iValue;
                         cout<<"Enter your Position\n";
                         cin>>iPos;
                         DCobj2.InsertAtPos(iValue,iPos);
                         break;

                         case 4:
                         DCobj2.DeleteFirst();
                         break;
               
                         case 5:
                         DCobj2.DeleteLast();
                         break;

                         case 6:
                         cout<<"Enter your Position\n";
                         cin>>iPos;
                         DCobj2.DeleteAtPos(iPos);
                         break;
              
                          case 7:
                         cout<<"Elements from  your LinkedList is :\n";
                         DCobj2.Display();
                         break;
                    
                         case 8:
                         iRet = DCobj2.Count();
                         cout<<"Count of your elements from LinkedList is %d\n",iRet;
                         break;
              
                          case 0:
                         cout<<"Thankyou for using Ameya's LinkedList\n";               
                         break;
          
                          default:
                         cout<<"INVALID DATA\n";

                    }

               }
    
          }

     }
     
     return 0;
}