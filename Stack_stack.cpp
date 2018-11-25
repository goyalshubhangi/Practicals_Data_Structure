#include<iostream>
using namespace std;

void show(int stack[],int size,int top)
{
	for(int i=0;i<size;i++)
	{
		cout<<"\nValue at "<<top<<"is"<<stack[top]<<"\n";
		top--;
	}
}

int main()
{
	int size,stack[50], temp[50],data ;
	int top=-1,top1=-1;
	cout<<"\nEnter the size of stack: ";
	cin>>size;
	for(int i=0;i<size;i++)
	{
		top=top+1;
		cout<<"\nEnter value at position "<<top<<":";
		cin>>data;
		stack[top]=data;
	}
	show(stack,size,top);
	for(int i=0;i<size;i++)
	{
		while(top>-1)
		{
		top1++;
		temp[top1]=stack[top];
		top--;
	}
	}

cout<<"\n\tAfter Reversing: ";
	for(int i=0;i<size;i++)
	{
		cout<<"\nValue at "<<top1<<"is"<<temp[top1]<<"\n";
		top1--;
	}
}