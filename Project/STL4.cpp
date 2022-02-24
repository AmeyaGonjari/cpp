
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
          
     }
     
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int main()
{
     int iChoice = 1;
     int iChoice1 = 1;
     int iChoice2 = 1;


     int iPos = 0;
     int iRet = 0;
     float fRet = 0.0f;
     char cRet = '\0';
     double dRet = 0.0f;

     int iValue = 0;
     float iValue2 = 0.0f;
     char iValue3 = '\0';
     double iValue4 = 0.0f;
     
     //_________________
     while(iChoice1 != 0)
     {

           cout<<"**************************************************************\n";
           cout<<"Enter your Linked List Choice \n";
           cout<<"1: Singly Linear LinkedList\n";
           cout<<"2: Doubly Linear LinkedList\n";
           cout<<"3: Singly Circular Linear LinkedList\n";
           cout<<"4: Doubly Linear LinkedList\n";
           cout<<"0: Terminate the Program \n";
           cout<<"**************************************************************\n";
           cin>>iChoice1;

          //-------------
          switch(iChoice1)
          {

               case 1:
               {

                    while(iChoice2 != 0)
                    {  

                         cout<<"Enter the Data type for your Singly LinkedList\n";
                         cout<<"1: INTEGER \n";
                         
                         cout<<"2: FLOAT \n";
                         
                         cout<<"3: CHARACTER \n";
                         
                         cout<<"4: DOUBLE \n";

                         cout<<"0: TERMINATE\n";
                         cout<<"----------------------------------------------------------\n";

                         cin>>iChoice2;                 

                         switch(iChoice2)  
                        {    

                           case 1:
                           {   
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
                                   cout<<"Count of your elements from LinkedList is "<<iRet<<"\n";
                                   break;
              
                                   case 0:
                                   cout<<"Thankyou for using Generic Singly LinkedList\n";               
                                   break;
          
                                   default:
                                   cout<<"INVALID DATA\n";
                    
                                   }
                    

                              }

                         }
                         break;

                           case 2:
                           {   
                              SinglyLL <float> SLobj2;
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
                                   cin>>iValue2;
                                   SLobj2.InsertFirst(iValue2);
                                   break;
                    
                                   case 2:

                                   cout<<"Enter your data for Insertion\n";
                                   cin>>iValue2;
                                   SLobj2.InsertLast(iValue2);
                                   break;

                                   case 3:
                                   cout<<"Enter your data for Insertion\n";
                                   cin>>iValue2;
                                   cout<<"Enter your Position\n";
                                   cin>>iPos;
                                   SLobj2.InsertAtPos(iValue2,iPos);
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
                                   fRet = SLobj2.Count();
                                   cout<<"Count of your elements from LinkedList is"<<fRet<<"\n";
                                   break;
              
                                   case 0:
                                   cout<<"Thankyou for using Generic Singly LinkedList\n";               
                                   break;
          
                                   default:
                                   cout<<"INVALID DATA\n";
                    
                                   }
                    

                              }

                         }
                         break;
                           case 3:
                           {   
                              SinglyLL <char> SLobj3;
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
                                   cin>>iValue3;
                                   SLobj3.InsertFirst(iValue3);
                                   break;
                    
                                   case 2:

                                   cout<<"Enter your data for Insertion\n";
                                   cin>>iValue3;
                                   SLobj3.InsertLast(iValue3);
                                   break;

                                   case 3:
                                   cout<<"Enter your data for Insertion\n";
                                   cin>>iValue3;
                                   cout<<"Enter your Position\n";
                                   cin>>iPos;
                                   SLobj3.InsertAtPos(iValue3,iPos);
                                   break;

                                   case 4:
                                   SLobj3.DeleteFirst();
                                   break;
               
                                   case 5:
                                   SLobj3.DeleteLast();
                                   break;

                                   case 6:
                                   cout<<"Enter your Position\n";
                                   cin>>iPos;
                                   SLobj3.DeleteAtPos(iPos);
                                   break;
              
                                   case 7:
                                   cout<<"Elements from  your LinkedList is :\n";
                                   SLobj3.Display();
                                   break;
                    
                                   case 8:
                                   cRet = SLobj3.Count();
                                   cout<<"Count of your elements from LinkedList is"<<cRet<<"\n";
                                   break;
              
                                   case 0:
                                   cout<<"Thankyou for using Generic Singly LinkedList\n";               
                                   break;
          
                                   default:
                                   cout<<"INVALID DATA\n";
                    
                                   }
                    

                              }

                         }
                         break;
                           case 4:
                           {   
                              SinglyLL <double> SLobj4;
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
                                   cin>>iValue4;
                                   SLobj4.InsertFirst(iValue4);
                                   break;
                    
                                   case 2:

                                   cout<<"Enter your data for Insertion\n";
                                   cin>>iValue4;
                                   SLobj4.InsertLast(iValue4);
                                   break;

                                   case 3:
                                   cout<<"Enter your data for Insertion\n";
                                   cin>>iValue4;
                                   cout<<"Enter your Position\n";
                                   cin>>iPos;
                                   SLobj4.InsertAtPos(iValue4,iPos);
                                   break;

                                   case 4:
                                   SLobj4.DeleteFirst();
                                   break;
               
                                   case 5:
                                   SLobj4.DeleteLast();
                                   break;

                                   case 6:
                                   cout<<"Enter your Position\n";
                                   cin>>iPos;
                                   SLobj4.DeleteAtPos(iPos);
                                   break;
              
                                   case 7:
                                   cout<<"Elements from  your LinkedList is :\n";
                                   SLobj4.Display();
                                   break;
                    
                                   case 8:
                                   dRet = SLobj4.Count();
                                   cout<<"Count of your elements from LinkedList is "<<dRet<<"\n";
                                   break;
              
                                   case 0:
                                   cout<<"Thankyou for using Generic Singly LinkedList\n";               
                                   break;
          
                                   default:
                                   cout<<"INVALID DATA\n";
                    
                                 }
                    

                              }

                         }
           
                         break;
           
                        }
                    }
               }
               break;

                   case 2:
               {

                    while(iChoice2 != 0)
                    {  
                         cout<<"Enter the Data type for your Singly LinkedList\n";
                         cout<<"1: INTEGER \n";

                         cout<<"2: FLOAT \n";
                         
                         cout<<"3: CHARACTER \n";
                         
                         cout<<"4: DOUBLE \n";      
                         
                         cout<<"0: TERMINATE\n";
                         
                         cout<<"----------------------------------------------------------\n";

                         cin>>iChoice2;                 

                         switch(iChoice2)  
                         {    

                           case 1:
                           {   
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
                                   cout<<"Count of your elements from LinkedList is "<<iRet<<"\n";
                                   break;
              
                                   case 0:
                                   cout<<"Thankyou for using Generic Singly LinkedList\n";               
                                   break;
          
                                   default:
                                   cout<<"INVALID DATA\n";
                    
                                   }
                    

                              }

                         }
                         break;

                           case 2:
                           {   
                                DoublyLL<float>DLobj2;
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
                                   cin>>iValue2;
                                   DLobj2.InsertFirst(iValue2);
                                   break;
                    
                                   case 2:

                                   cout<<"Enter your data for Insertion\n";
                                   cin>>iValue2;
                                   DLobj2.InsertLast(iValue2);
                                   break;

                                   case 3:
                                   cout<<"Enter your data for Insertion\n";
                                   cin>>iValue2;
                                   cout<<"Enter your Position\n";
                                   cin>>iPos;
                                   DLobj2.InsertAtPos(iValue2,iPos);
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
                                   fRet = DLobj2.Count();
                                   cout<<"Count of your elements from LinkedList is "<<fRet<<"\n";
                                   break;
              
                                   case 0:
                                   cout<<"Thankyou for using Generic Singly LinkedList\n";               
                                   break;
          
                                   default:
                                   cout<<"INVALID DATA\n";
                    
                                   }
                    

                              }

                         }
                         break;
                           case 3:
                           {   
                                 DoublyLL <char> DLobj3;

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
                                   cin>>iValue3;
                                   DLobj3.InsertFirst(iValue3);
                                   break;
                    
                                   case 2:

                                   cout<<"Enter your data for Insertion\n";
                                   cin>>iValue3;
                                   DLobj3.InsertLast(iValue3);
                                   break;

                                   case 3:
                                   cout<<"Enter your data for Insertion\n";
                                   cin>>iValue3;
                                   cout<<"Enter your Position\n";
                                   cin>>iPos;
                                   DLobj3.InsertAtPos(iValue3,iPos);
                                   break;

                                   case 4:
                                   DLobj3.DeleteFirst();
                                   break;
               
                                   case 5:
                                   DLobj3.DeleteLast();
                                   break;

                                   case 6:
                                   cout<<"Enter your Position\n";
                                   cin>>iPos;
                                   DLobj3.DeleteAtPos(iPos);
                                   break;
              
                                   case 7:
                                   cout<<"Elements from  your LinkedList is :\n";
                                   DLobj3.Display();
                                   break;
                    
                                   case 8:
                                   cRet = DLobj3.Count();
                                   cout<<"Count of your elements from LinkedList is "<<cRet<<"\n";
                                   break;
              
                                   case 0:
                                   cout<<"Thankyou for using Generic Singly LinkedList\n";               
                                   break;
          
                                   default:
                                   cout<<"INVALID DATA\n";
                    
                                   }
                    

                              }

                         }
                         break;
                           case 4:
                           {   
                             DoublyLL <double> DLobj4;
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
                                   cin>>iValue4;
                                   DLobj4.InsertFirst(iValue4);
                                   break;
                    
                                   case 2:

                                   cout<<"Enter your data for Insertion\n";
                                   cin>>iValue4;
                                   DLobj4.InsertLast(iValue4);
                                   break;

                                   case 3:
                                   cout<<"Enter your data for Insertion\n";
                                   cin>>iValue4;
                                   cout<<"Enter your Position\n";
                                   cin>>iPos;
                                   DLobj4.InsertAtPos(iValue4,iPos);
                                   break;

                                   case 4:
                                   DLobj4.DeleteFirst();
                                   break;
               
                                   case 5:
                                   DLobj4.DeleteLast();
                                   break;

                                   case 6:
                                   cout<<"Enter your Position\n";
                                   cin>>iPos;
                                   DLobj4.DeleteAtPos(iPos);
                                   break;
              
                                   case 7:
                                   cout<<"Elements from  your LinkedList is :\n";
                                   DLobj4.Display();
                                   break;
                    
                                   case 8:
                                   dRet = DLobj4.Count();
                                   cout<<"Count of your elements from LinkedList is "<<dRet<<"\n";
                                   break;
              
                                   case 0:
                                   cout<<"Thankyou for using Generic Singly LinkedList\n";               
                                   break;
          
                                   default:
                                   cout<<"INVALID DATA\n";
                    
                                }
                    

                            }

                         }
                         break;



                        }
                    }
               }
               break;

                   case 3:
               {

                    while(iChoice2 != 0)
                    {  
                         cout<<"Enter the Data type for your Singly LinkedList\n";
                         cout<<"1: INTEGER \n";

                         cout<<"2: FLOAT \n";
                         
                         cout<<"3: CHARACTER \n";
                         
                         cout<<"4: DOUBLE \n";

                         cout<<"0: TERMINATE\n";
                         
                         cout<<"----------------------------------------------------------\n";
                         cin>>iChoice2;                 

                         switch(iChoice2)  
                         {    

                           case 1:
                           {   
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
                                   cout<<"Count of your elements from LinkedList is "<<iRet<<"\n";
                                   break;
              
                                   case 0:
                                   cout<<"Thankyou for using Generic Singly LinkedList\n";               
                                   break;
          
                                   default:
                                   cout<<"INVALID DATA\n";
                    
                                   }
                    

                              }

                         }
                         break;

                           case 2:
                           {   
                              SinglyCL <float> SCobj2;
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
                                   cin>>iValue2;
                                   SCobj2.InsertFirst(iValue2);
                                   break;
                    
                                   case 2:

                                   cout<<"Enter your data for Insertion\n";
                                   cin>>iValue2;
                                   SCobj2.InsertLast(iValue2);
                                   break;

                                   case 3:
                                   cout<<"Enter your data for Insertion\n";
                                   cin>>iValue2;
                                   cout<<"Enter your Position\n";
                                   cin>>iPos;
                                   SCobj2.InsertAtPos(iValue2,iPos);
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
                                   fRet = SCobj2.Count();
                                   cout<<"Count of your elements from LinkedList is "<<fRet<<"\n";
                                   break;
              
                                   case 0:
                                   cout<<"Thankyou for using Generic Singly LinkedList\n";               
                                   break;
          
                                   default:
                                   cout<<"INVALID DATA\n";
                    
                                   }
                    

                              }

                         }
                         break;
                           case 3:
                           {   
                              SinglyCL <char> SCobj3;
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
                                   cin>>iValue3;
                                   SCobj3.InsertFirst(iValue3);
                                   break;
                    
                                   case 2:

                                   cout<<"Enter your data for Insertion\n";
                                   cin>>iValue3;
                                   SCobj3.InsertLast(iValue3);
                                   break;

                                   case 3:
                                   cout<<"Enter your data for Insertion\n";
                                   cin>>iValue3;
                                   cout<<"Enter your Position\n";
                                   cin>>iPos;
                                   SCobj3.InsertAtPos(iValue3,iPos);
                                   break;

                                   case 4:
                                   SCobj3.DeleteFirst();
                                   break;
               
                                   case 5:
                                   SCobj3.DeleteLast();
                                   break;

                                   case 6:
                                   cout<<"Enter your Position\n";
                                   cin>>iPos;
                                   SCobj3.DeleteAtPos(iPos);
                                   break;
              
                                   case 7:
                                   cout<<"Elements from  your LinkedList is :\n";
                                   SCobj3.Display();
                                   break;
                    
                                   case 8:
                                   cRet = SCobj3.Count();
                                   cout<<"Count of your elements from LinkedList is "<<cRet<<"\n";
                                   break;
              
                                   case 0:
                                   cout<<"Thankyou for using Generic Singly LinkedList\n";               
                                   break;
          
                                   default:
                                   cout<<"INVALID DATA\n";
                    
                                   }
                    

                              }

                         }
                         break;
                           case 4:
                           {   
                              SinglyCL <double> SCobj4;
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
                                   cin>>iValue4;
                                   SCobj4.InsertFirst(iValue4);
                                   break;
                    
                                   case 2:

                                   cout<<"Enter your data for Insertion\n";
                                   cin>>iValue4;
                                   SCobj4.InsertLast(iValue4);
                                   break;

                                   case 3:
                                   cout<<"Enter your data for Insertion\n";
                                   cin>>iValue4;
                                   cout<<"Enter your Position\n";
                                   cin>>iPos;
                                   SCobj4.InsertAtPos(iValue4,iPos);
                                   break;

                                   case 4:
                                   SCobj4.DeleteFirst();
                                   break;
               
                                   case 5:
                                   SCobj4.DeleteLast();
                                   break;

                                   case 6:
                                   cout<<"Enter your Position\n";
                                   cin>>iPos;
                                   SCobj4.DeleteAtPos(iPos);
                                   break;
              
                                   case 7:
                                   cout<<"Elements from  your LinkedList is :\n";
                                   SCobj4.Display();
                                   break;
                    
                                   case 8:
                                   dRet = SCobj4.Count();
                                   cout<<"Count of your elements from LinkedList is "<<dRet<<"\n";
                                   break;
              
                                   case 0:
                                   cout<<"Thankyou for using Generic Singly LinkedList\n";               
                                   break;
          
                                   default:
                                   cout<<"INVALID DATA\n";
                    
                                 }
                
                            }

                         }
                         break;

                        }
                    }
               }
               break;

                   case 4:
               {

                    while(iChoice2 != 0)
                    {  
                         cout<<"Enter the Data type for your Singly LinkedList\n";
                         cout<<"1: INTEGER \n";

                         cout<<"2: FLOAT \n";
                         
                         cout<<"3: CHARACTER \n";
                         
                         cout<<"4: DOUBLE \n";
                         
                         cin>>iChoice2;                 

                         cout<<"0: TERMINATE\n";
                         
                         cout<<"----------------------------------------------------------\n";
                         switch(iChoice2)  
                         {    

                           case 1:
                           {   
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
                                   cout<<"Count of your elements from LinkedList is "<<iRet<<"\n";
                                   break;
              
                                   case 0:
                                   cout<<"Thankyou for using Generic Singly LinkedList\n";               
                                   break;
          
                                   default:
                                   cout<<"INVALID DATA\n";
                    
                                   }
                    

                              }

                         }
                         break;

                           case 2:
                           {   
                               DoublyCL <float> DCobj2;
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
                                   cin>>iValue2;
                                   DCobj2.InsertFirst(iValue2);
                                   break;
                    
                                   case 2:

                                   cout<<"Enter your data for Insertion\n";
                                   cin>>iValue2;
                                   DCobj2.InsertLast(iValue2);
                                   break;

                                   case 3:
                                   cout<<"Enter your data for Insertion\n";
                                   cin>>iValue2;
                                   cout<<"Enter your Position\n";
                                   cin>>iPos;
                                   DCobj2.InsertAtPos(iValue2,iPos);
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
                                   fRet = DCobj2.Count();
                                   cout<<"Count of your elements from LinkedList is "<<fRet<<"\n";
                                   break;
              
                                   case 0:
                                   cout<<"Thankyou for using Generic Singly LinkedList\n";               
                                   break;
          
                                   default:
                                   cout<<"INVALID DATA\n";
                    
                                   }
                    

                              }

                         }
                         break;
                           case 3:
                           {   
                                DoublyCL <char> DCobj3;
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
                                   cin>>iValue3;
                                   DCobj3.InsertFirst(iValue3);
                                   break;
                    
                                   case 2:

                                   cout<<"Enter your data for Insertion\n";
                                   cin>>iValue3;
                                   DCobj3.InsertLast(iValue3);
                                   break;

                                   case 3:
                                   cout<<"Enter your data for Insertion\n";
                                   cin>>iValue3;
                                   cout<<"Enter your Position\n";
                                   cin>>iPos;
                                   DCobj3.InsertAtPos(iValue3,iPos);
                                   break;

                                   case 4:
                                   DCobj3.DeleteFirst();
                                   break;
               
                                   case 5:
                                   DCobj3.DeleteLast();
                                   break;

                                   case 6:
                                   cout<<"Enter your Position\n";
                                   cin>>iPos;
                                   DCobj3.DeleteAtPos(iPos);
                                   break;
              
                                   case 7:
                                   cout<<"Elements from  your LinkedList is :\n";
                                   DCobj3.Display();
                                   break;
                    
                                   case 8:
                                   cRet = DCobj3.Count();
                                   cout<<"Count of your elements from LinkedList is "<<cRet<<"\n";
                                   break;
              
                                   case 0:
                                   cout<<"Thankyou for using Generic Singly LinkedList\n";               
                                   break;
          
                                   default:
                                   cout<<"INVALID DATA\n";
                    
                                   }
                    

                              }

                         }
                         break;
                           case 4:
                           {  

                              DoublyCL <double> DCobj4;
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
                                   cin>>iValue4;
                                   DCobj4.InsertFirst(iValue4);
                                   break;
                    
                                   case 2:

                                   cout<<"Enter your data for Insertion\n";
                                   cin>>iValue4;
                                   DCobj4.InsertLast(iValue4);
                                   break;

                                   case 3:
                                   cout<<"Enter your data for Insertion\n";
                                   cin>>iValue4;
                                   cout<<"Enter your Position\n";
                                   cin>>iPos;
                                   DCobj4.InsertAtPos(iValue4,iPos);
                                   break;

                                   case 4:
                                   DCobj4.DeleteFirst();
                                   break;
               
                                   case 5:
                                   DCobj4.DeleteLast();
                                   break;

                                   case 6:
                                   cout<<"Enter your Position\n";
                                   cin>>iPos;
                                   DCobj4.DeleteAtPos(iPos);
                                   break;
              
                                   case 7:
                                   cout<<"Elements from  your LinkedList is :\n";
                                   DCobj4.Display();
                                   break;
                    
                                   case 8:
                                   dRet = DCobj4.Count();
                                   cout<<"Count of your elements from LinkedList is "<<dRet<<"\n";
                                   break;
              
                                   case 0:
                                   cout<<"Thankyou for using Generic Singly LinkedList\n";               
                                   break;
          
                                   default:
                                   cout<<"INVALID DATA\n";
                    
                              }
                    

                            }

                        }
                         
                        break;

                       
                    
                        }
                    }

               }
               break;

               default :
                          cout<<"Thankyou for using Ameya's Generic LinkedList";

          }

     }
     
     return 0;
}