#include<iostream>
using namespace std;
int main()
{
	int n;
	int f=1,s=0;
	cout<<"Number upto which you want to calculate the fibbonacci:";
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cout<<f+s<<" ";
		int a =f+s;
		f=s;
		s=a;


	}
}