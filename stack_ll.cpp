#include<iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;
struct stack
{
	int data;
	struct stack*next;
}*top,*top1;
int count=0;

void push(int data)
{
	if(top==NULL)
	{
		top=(struct stack*) malloc(sizeof(struct stack));
		top->next=NULL;
		top->data=data;
	}
	else
	{
		struct stack*temp=(struct stack*)malloc(sizeof(struct stack));
		temp->next=top;
		temp->data=data;
		top=temp;
	}
	count++;
}
void pop()
{
	top1=top;
	if(top1==NULL)
	{
		cout<<"\n\nStack underflow\n\n";
	}
	else
		top=top->next;
	cout<<"\n\tElement popped out:"<<top1->data;
	free(top1);
	count--;
}
void display()
{
	top1=top;
	if(top1==NULL)
	{
		cout<<"Stack is empty";
		return;
	}
	while(top1!=NULL)
	{
		cout<<"\n\tElement:"<<top1->data;
		top1=top1->next;
	}
}
int main()
{
	int ch,data;
do
{
	cout<<"\n1.Push\n2.Pop\n3.Display\n4.Exit";
		cout<<"\n Enter your choice";
		cin>>ch;
		switch(ch)
		{
			case 1:
			cout<<"\n\tEnter the element to be inserted:";
			cin>>data;
			push(data);
			break;
			case 2:
			pop();
			break;
			case 3:
			display();
			break;
			case 4:
			break;
			default:
			cout<<"\nWrong Choice!!!";
			break;

		}
}while(ch!=4);
}