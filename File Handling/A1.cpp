#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<string.h>

using namespace std;

class MarvellousFile
{
public:
    char Fname[30];
    int fd;
    
    MarvellousFile(char * Name)     // Constructor
    {
        cout<<"Inside constructor\n";
        strcpy(Fname,Name);
        fd = open(Fname,O_RDWR);
    }
    
    ~MarvellousFile()   // Desructor
    {
        cout<<"Inside Destructor\n";
        close(fd);
    }
    
    void Disaply()
    {
        int iRet = 0;
        char Buffer[10];
        lseek(fd,0,0);
        
        cout<<"Data from file is : \n";
        while((iRet = read(fd,Buffer,10)) != 0)
        {
            write(1,Buffer,iRet);
        }
        
        cout<<"\n";
    }
    
    int CountCapital()
    {
        int iRet = 0, iCnt = 0, i = 0;
        char Buffer[10];
        lseek(fd,0,0);
        
        while((iRet = read(fd,Buffer,10)) != 0)
        {
            for(i = 0; i < iRet; i++)
            {
                if((Buffer[i] >='A') && (Buffer[i] <= 'Z'))
                {
                    iCnt++;
                }
            }
        }
        return iCnt;
    }

    int CountSmall()
    {
        int iRet = 0, iCnt = 0, i = 0;
        char Buffer[10];
        lseek(fd,0,0);
        
        while((iRet = read(fd,Buffer,10)) != 0)
        {
            for(i = 0; i < iRet; i++)
            {
                if((Buffer[i] >='a') && (Buffer[i] <= 'z'))
                {
                    iCnt++;
                }
            }
        }
        return iCnt;
    }
    
      int CountDigit()
      {
          int iRet = 0, iCnt = 0, i = 0;
          char Buffer[10];
          lseek(fd,0,0);
          
          while((iRet = read(fd,Buffer,10)) != 0)
          {
              for(i = 0; i < iRet; i++)
              {
                  if((Buffer[i] >='0') && (Buffer[i] <= '9'))
                  {
                      iCnt++;
                  }
              }
          }
          return iCnt;
      }
};

int main()
{
    char Name[30];
    int iRet = 0;
    
    cout<<"Enter name of file\n";
    cin>>Name;
    
    MarvellousFile obj(Name);
    
    obj.Disaply();
    
    iRet = obj.CountCapital();
    cout<<"Capital letters are : "<<iRet<<"\n";
    
    iRet = obj.CountSmall();
    cout<<"Small letters are : "<<iRet<<"\n";
    
    iRet = obj.CountDigit();
    cout<<"Digits letters are : "<<iRet<<"\n";
    
    return 0;
}
