#include<iostream>
using namespace std;

int  SumI(int Arr[],int iSize)
{
	int iSum = 0 , i = 0;
	
	for(i = 0;i<iSize;i++)
	{
		iSum = iSum + Arr[i];
	}

	return iSum;
}

int SumR(int Arr[],int iSize)
{
 	static int iSum = 0 , i = 0;
	
	if(i<iSize)
	{
		iSum = iSum + Arr[i];
		i++;
		SumR(Arr,iSize);
	}


	return iSum;
}

int main()
{
	int ilength = 0,i = 0;
	int * p = NULL;
	int iRet = 0;
	cout<<"Entr number of elements :\n";
	cin>>ilength;

	p = new int[ilength];

	cout<<"Enter the elements\n";
	for(i = 0 ;i < ilength;i++)
	{
		cin>>p[i];

	}

	iRet = SumI(p,ilength);
	cout<<iRet<<"\n";

	cout<<"Entr number of elements :\n";
	cin>>ilength;

	p = new int[ilength];

	cout<<"Enter the elements\n";
	for(i = 0 ;i < ilength;i++)
	{
		cin>>p[i];

	}


	iRet = SumI(p,ilength);
	cout<<iRet<<"\n";

	delete []p;
	return 0;	
}