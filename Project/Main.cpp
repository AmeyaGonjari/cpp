
int main()
{
     int iChoice = 1;
     int iChoice1 = 1;
     int iChoice2 = 1;

     int iPos = 0;
     int iRet = 0;
     int iValue = 0;

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
           scanf("%d",&iChoice1);

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
                                   cout<<"Count of your elements from LinkedList is %d\n",iRet;
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
                                   cin>>iValue;
                                   SLobj3.InsertFirst(iValue);
                                   break;
                    
                                   case 2:

                                   cout<<"Enter your data for Insertion\n";
                                   cin>>iValue;
                                   SLobj3.InsertLast(iValue);
                                   break;

                                   case 3:
                                   cout<<"Enter your data for Insertion\n";
                                   cin>>iValue;
                                   cout<<"Enter your Position\n";
                                   cin>>iPos;
                                   SLobj3.InsertAtPos(iValue,iPos);
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
                                   iRet = SLobj3.Count();
                                   cout<<"Count of your elements from LinkedList is %d\n",iRet;
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
                                   cin>>iValue;
                                   SLobj4.InsertFirst(iValue);
                                   break;
                    
                                   case 2:

                                   cout<<"Enter your data for Insertion\n";
                                   cin>>iValue;
                                   SLobj4.InsertLast(iValue);
                                   break;

                                   case 3:
                                   cout<<"Enter your data for Insertion\n";
                                   cin>>iValue;
                                   cout<<"Enter your Position\n";
                                   cin>>iPos;
                                   SLobj4.InsertAtPos(iValue,iPos);
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
                                   iRet = SLobj4.Count();
                                   cout<<"Count of your elements from LinkedList is %d\n",iRet;
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
                                             cout<<"Count of your elements from LinkedList is %d\n",iRet;
                                             break;
              
                                             case 0:
                                             cout<<"Thankyou for using Generic Doubly LinkedList\n";               
                                             break;
          
                                             default:
                                             cout<<"INVALID DATA\n";

                                        }

                        
                                   }
  
                              }
                              break;

                              case 2:
                              {  
                                    DoublyLL <float> DLobj2;
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
                                             cout<<"Thankyou for using Generic Doubly LinkedList\n";               
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
                                             cin>>iValue;
                                             DLobj3.InsertFirst(iValue);
                                             break;
               
                                             case 2:
                                             cout<<"Enter your data for Insertion\n";
                                             cin>>iValue;
                                             DLobj3.InsertLast(iValue);
                                             break;

                                             case 3:
                                             cout<<"Enter your data for Insertion\n";
                                             cin>>iValue;
                                             cout<<"Enter your Position\n";
                                              cin>>iPos;
                                               DLobj3.InsertAtPos(iValue,iPos);
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
                                             iRet = DLobj3.Count();
                                             cout<<"Count of your elements from LinkedList is %d\n",iRet;
                                             break;
              
                                             case 0:
                                             cout<<"Thankyou for using Generic Doubly LinkedList\n";               
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
                                             cin>>iValue;
                                             DLobj4.InsertFirst(iValue);
                                             break;
               
                                             case 2:
                                             cout<<"Enter your data for Insertion\n";
                                             cin>>iValue;
                                             DLobj4.InsertLast(iValue);
                                             break;

                                             case 3:
                                             cout<<"Enter your data for Insertion\n";
                                             cin>>iValue;
                                             cout<<"Enter your Position\n";
                                              cin>>iPos;
                                               DLobj4.InsertAtPos(iValue,iPos);
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
                                             iRet = DLobj4.Count();
                                             cout<<"Count of your elements from LinkedList is %d\n",iRet;
                                             break;
              
                                             case 0:
                                             cout<<"Thankyou for using Generic Doubly LinkedList\n";               
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
                                             cout<<"Count of your elements from LinkedList is %d\n",iRet;
                                             break;
              
                                             case 0:
                                             cout<<"Thankyou for using Generic Doubly LinkedList\n";               
                                             break;
          
                                             default:
                                             cout<<"INVALID DATA\n";

                                        }

                        
                                   }
  
                              }
                              break;

                              case 2:
                              {  
                                    SinglyCL <int> SCobj2;
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
                                             cout<<"Thankyou for using Generic Doubly LinkedList\n";               
                                             break;
          
                                             default:
                                             cout<<"INVALID DATA\n";

                                        }

                        
                                   }
  
                              }
                              break;
                                 case 3:
                              {                
                                    SinglyCL <int> SCobj3;
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
                                             SCobj3.InsertFirst(iValue);
                                             break;
               
                                             case 2:
                                             cout<<"Enter your data for Insertion\n";
                                             cin>>iValue;
                                             SCobj3.InsertLast(iValue);
                                             break;

                                             case 3:
                                             cout<<"Enter your data for Insertion\n";
                                             cin>>iValue;
                                             cout<<"Enter your Position\n";
                                              cin>>iPos;
                                               SCobj3.InsertAtPos(iValue,iPos);
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
                                             iRet = SCobj3.Count();
                                             cout<<"Count of your elements from LinkedList is %d\n",iRet;
                                             break;
              
                                             case 0:
                                             cout<<"Thankyou for using Generic Doubly LinkedList\n";               
                                             break;
          
                                             default:
                                             cout<<"INVALID DATA\n";

                                        }

                        
                                   }
  
                              }
                              break;
                                 case 4:
                              {  
                                    SinglyCL <int> SCobj4;
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
                                             SCobj4.InsertFirst(iValue);
                                             break;
               
                                             case 2:
                                             cout<<"Enter your data for Insertion\n";
                                             cin>>iValue;
                                             SCobj4.InsertLast(iValue);
                                             break;

                                             case 3:
                                             cout<<"Enter your data for Insertion\n";
                                             cin>>iValue;
                                             cout<<"Enter your Position\n";
                                              cin>>iPos;
                                               SCobj4.InsertAtPos(iValue,iPos);
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
                                             iRet = SCobj4.Count();
                                             cout<<"Count of your elements from LinkedList is %d\n",iRet;
                                             break;
              
                                             case 0:
                                             cout<<"Thankyou for using Generic Doubly LinkedList\n";               
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
                                             cout<<"Count of your elements from LinkedList is %d\n",iRet;
                                             break;
              
                                             case 0:
                                             cout<<"Thankyou for using Generic Doubly LinkedList\n";               
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
                                             cout<<"Thankyou for using Generic Doubly LinkedList\n";               
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
                                             cin>>iValue;
                                             DCobj3.InsertFirst(iValue);
                                             break;
               
                                             case 2:
                                             cout<<"Enter your data for Insertion\n";
                                             cin>>iValue;
                                             DCobj3.InsertLast(iValue);
                                             break;

                                             case 3:
                                             cout<<"Enter your data for Insertion\n";
                                             cin>>iValue;
                                             cout<<"Enter your Position\n";
                                              cin>>iPos;
                                               DCobj3.InsertAtPos(iValue,iPos);
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
                                             iRet = DCobj3.Count();
                                             cout<<"Count of your elements from LinkedList is %d\n",iRet;
                                             break;
              
                                             case 0:
                                             cout<<"Thankyou for using Generic Doubly LinkedList\n";               
                                             break;
          
                                             default:
                                             cout<<"INVALID DATA\n";

                                        }

                        
                                   }
  
                              }
                              break;
                              
                                 case 4:
                              {  
                                    DoublyCL <int> DCobj4;
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
                                             DCobj4.InsertFirst(iValue);
                                             break;
               
                                             case 2:
                                             cout<<"Enter your data for Insertion\n";
                                             cin>>iValue;
                                             DCobj4.InsertLast(iValue);
                                             break;

                                             case 3:
                                             cout<<"Enter your data for Insertion\n";
                                             cin>>iValue;
                                             cout<<"Enter your Position\n";
                                              cin>>iPos;
                                               DCobj4.InsertAtPos(iValue,iPos);
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
                                             iRet = DCobj4.Count();
                                             cout<<"Count of your elements from LinkedList is %d\n",iRet;
                                             break;
              
                                             case 0:
                                             cout<<"Thankyou for using Generic Doubly LinkedList\n";               
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