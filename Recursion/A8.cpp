#include<iostream>
#include<stdio.h>
using namespace std;

int Strlen(char *str)
{
	int iCnt = 0;
	while(*str != '\0')
	{
		iCnt++;
		str++;
	}
	return iCnt;
}

int CountCap(char *str)
{
	static int iCnt = 0;

	if(*str != '\0')
	{
		if((*str >= 'A')&&(*str <= 'Z'))
		
		{
			iCnt++;		
		}
		str++;
		CountCap(str);
	}
	return iCnt;
}
int main()
{

	char Brr[20];
	char Arr[20];
	int iRet = 0;

	cout<<"Enter String\n";
	scanf("%[^'\n']s",Arr);

	iRet = CountCap(Arr);
	cout<<"Size is "<<iRet;
	return 0;
}