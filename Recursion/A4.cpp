#include<iostream>
using namespace std;

void DisplayI(int iNo)
{
	int iCnt = 1;	
	while(iCnt <= iNo)
	{
		cout<<"Marvellous\n";
		iCnt++;

	}
}

void DisplayR(int iNo)

{
	static int iCnt = 1;
	if(iCnt<=iNo)
	{
		cout<<"Marvellous\n";
		iCnt++;
		DisplayR(iNo);	
	}
}
int main()
{

	DisplayI(5);
	cout<<"--------------------\n";
	DisplayR(5);
	return 0;
}