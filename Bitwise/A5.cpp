#include<iostream>
using namespace std;
typedef unsigned int UINT;

class Bitwise
{
public:
	
	UINT iValue1;
	int iPos1;
	int iPos2;
	UINT iMask1 = 0xFFFFFFFF;
	UINT iMask2 = 0xFFFFFFFF;

	Bitwise()
	{

	 	iValue1 = 0;
		iPos1= 0;
		iPos2= 0;
	}

	void Accept()
	{
	
		cout<<"Enter the Number:\n";
		cin>>iValue1;
	
		cout<<"Enter Start Position:\n";
		cin>>iPos1;

		cout<<"Enter End Position:\n";
		cin>>iPos2;
	}	

};

class Marvellous:public Bitwise
{ 
public:

	UINT ToggleRange()
	{
		UINT iMask = 0;
		UINT iResult =0;

		iMask1 = iMask1<<(iPos1 -1);
		iMask2 = iMask2>>(32 - iPos2);

		iMask = iMask1&iMask2;

		iResult = iValue1^iMask;
	

		return iResult;
	}


};

int main()
{
	int iRet = 0;

	Marvellous mobj;

	mobj.Accept();
	
	iRet =mobj.ToggleRange();

	cout<<"Updated Number is :"<<iRet<<"\n";
	return 0;
}