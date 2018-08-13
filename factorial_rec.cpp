#include<iostream>
using namespace std;

int fact(int n)
{
	if(n==1)
	return(1);
	else
	{
		return(n*fact(n-1));
	}
}
int main()
{
	int f=1,n,fac;
	cout<<"Enter the number whose factorial is to be computed:";
	cin>>n;
	fac=fact(n);
	cout<<"Factorial of a number is: "<<fac;
	
}
