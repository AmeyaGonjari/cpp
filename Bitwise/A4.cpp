#include<iostream>
using namespace std;
typedef unsigned int UINT;

class Bitwise
{
public:
	
	UINT iValue1;
	int iMask;

	Bitwise()
	{

	 	iValue1 = 0;
	
		iMask = 0xF00000F;
	}

	void Accept()
	{
	
		cout<<"Enter the Number:\n";
		cin>>iValue1;
	
	}	

};

class Marvellous:public Bitwise
{ 
public:

	UINT Toggle()
	{
		 int iResult = 0;
	
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