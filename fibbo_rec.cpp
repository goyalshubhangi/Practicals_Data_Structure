#include<iostream>
using namespace std;
void fibbo(int f,int s,int n)
{
	if(f+s>n)
		return;
	else
	{
		cout<<f+s<<" ";
		return (fibbo(s,f+s,n));
	}
}
int main()
{
	int n,f=1,s=0;
	cout<<"Number upto which you want to calculate the fibbonacci:";
	cin>>n;
	fibbo(f,s,n);
}