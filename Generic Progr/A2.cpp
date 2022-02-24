#include<iostream>
using namespace std;

void Swap(float * p,float * q)
{
	float temp;

	temp = *p;
	*p = *q;
	*q = temp;

}
int main()
{
	float x = 0.0f;
	float y = 0.0f;

	cout<<"Enter First Number:\n";
	cin>>x;

	cout<<"Enter second Number:\n";
	cin>>y;
	
	Swap(&x,&y);

	cout<<"Value of X becomes:"<<x<<"\n";
	cout<<"Value of Y becomes:"<<y<<"\n";

	return 0;
}
