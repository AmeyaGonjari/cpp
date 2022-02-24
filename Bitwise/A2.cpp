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
	}	

};

class Marvellous:public Bitwise
{ 
public:


	UINT ONbit()
	{	
		int i = 0;
		int iCnt = 0;
		int iResult =0;
		 
	/*	for(i = 1;i<32;i++)
		{
				iResult = iValue1&iMask;

			if(iResult != 0)
			{
				iCnt++;

			}

			iMask = iMask<<1;

		} */

		for(i = 1;i<32;i++)
		{

			if((iValue1&iMask)==iMask)
			{

				iCnt++;
			}
			iMask = iMask<<1;

		}


		return iCnt;

	} 

};

int main()
{
	int iRet = 0;

	Marvellous mobj;

	mobj.Accept();
	
	iRet =mobj.ONbit();

	cout<<" No of On bits are :"<<iRet<<"\n";
	return 0;
}