#include<iostream>
using namespace std;
typedef unsigned int UINT;

class Bitwise
{
public:
	
	UINT iValue1;
	int iPos;
	int iMask;

	Bitwise()
	{

	 	iValue1 = 0;
		iPos = 0;
		iMask = 0x00000001;
	}

	void Accept()
	{
	
		cout<<"Enter the Number:\n";
		cin>>iValue1;
	
		cout<<"Enter the Position:\n";
		cin>>iPos;
	}	

};

class Marvellous:public Bitwise
{ 
public:

	UINT Toggle()
	{
		 int iResult = 0;
		 
		 if((iPos<1)||(iPos>32))
		 {
		 	return 0;

		 }
	
		iMask = iMask<<(iPos - 1);
		iResult = iValue1^iMask; 

		return iResult;

	} 

};

int main()
{
	int iRet = 0;

	Marvellous mobj;

	mobj.Accept();
	
	iRet =mobj.Toggle();

	cout<<"Updated Number is :"<<iRet<<"\n";
	return 0;
}