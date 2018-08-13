#include<iostream>
using namespace std;
int main()
{
	int n,fac=1;
	cout<<"Enter the number whose factorial is to be computed:";
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		fac*=i;
	}
		cout<<"Factorial of a number is: "<<fac;
}
