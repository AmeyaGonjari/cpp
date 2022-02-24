#include<iostream>
using namespace std;


//specific function
void Swap(char * p,char * q)
{
	char temp;

	temp = *p;
	*p = *q;
	*q = temp;

}
//Generic function
template<class T>

void SwapX(T * p,T * q)
{
	T temp;

	temp = *p;
	*p = *q;
	*q = temp;

}

int main()
{
	char x = '\0';
	char y = '\0';

	cout<<"Enter First Number:\n";
	cin>>x;

	cout<<"Enter second Number:\n";
	cin>>y;
	
	Swap(&x,&y);
	SwapX(&x,&y);

	cout<<"Value of X becomes:"<<x<<"\n";
	cout<<"Value of Y becomes:"<<y<<"\n";

	return 0;
}
