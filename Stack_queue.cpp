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
int main(){
	int size,stack[50], queue[50],data ;
	int top=-1,front=-1,rear=-1;
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
	front=0;
	while(top>-1)
	{
		rear=rear+1;
		queue[rear]=stack[top];
		top--;
	}

	while(front<=rear)
	{
		top++;
		stack[top]=queue[front];
		front++;
	}
	cout<<"\n\tAfter Reversing: ";
	show(stack,size,top);

}