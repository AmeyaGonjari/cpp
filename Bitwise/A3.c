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
		iPos1 = 0;
		iPos2 = 0;
		iMask1 = 0x00000001;
		iMask2 = 0x00000001;

		
	}

	void Accept()
	{
	
		cout<<"Enter the Number:\n";
		cin>>iValue1;
	
		cout<<"Enter 1st the Position:\n";
		cin>>iPos1;
	

		cout<<"Enter  2nd the Position:\n";
		cin>>iPos2;
	}	

};

class Marvellous:public Bitwise
{ 
public:

	UINT Toggle()
	{
		 int iResult = 0;
	
		iMask1 = iMask1<<(iPos1 - 1);
		iMask2 = iMask2<<(iPos2 - 1);
	
		iResult = iValue1^iMask1;
		iResult = iValue1^iMask2;


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