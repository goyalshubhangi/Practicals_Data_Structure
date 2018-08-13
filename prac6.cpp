#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
using namespace std;
struct node
{
	int data;
	struct node *next;
}*top;

void push(int x);
int pop();
void display();
int main()
{
	char ch;
	int choice,item,a;
	do
	{
	
	cout<<"\n1. push\n2. pop\n3. display\n4. exit.";
	cout<<"\n Enter your choice:";
	cin>>choice;
	
	switch(choice)
	{
		case 1:
			cout<<"\nEnter data to insert: ";
				cin>>item;
			
			push(item);
			break;
		case 2:
			a=pop();
			cout<<"The deleted item is :"<<a;
			break;
		case 3:
			display();
			break;
			case 4:
			break;
		default:cout<<"\n Wrong choice";
	}
cout<<"\nDo you want to continue(Y/N)";
	cin>>ch;
	
		    	
	}while(ch=='Y'||ch=='y');
}
void push(int x)
{
	struct node *p= (struct node*) malloc(sizeof(struct node));
	if(p==NULL)
	{
		//memory gets full
		exit(0);
	}

	p->data=x;
	if(top == NULL)
	{
		p->next=NULL;
		top=p;
	}
	else
	{
		p->next=top;
		top=p;
	}
}


int pop()
{
		struct  node *p;

	if(top != NULL)
	{
		p=top;
	top=top->next;
		cout<<"\n"<<p->data<<" get popped.";
		free(p);
	}
	else
	{
		cout<<("Underflow!!!!\n");
	}
}

void display()
{
	if (top == NULL)
    {
        cout<<"\nLinked List is Empty	"<<endl;
        return;
    }

    struct node *p;
    p = top;
    cout<<"\nElements of Linked list are: "<<endl;
    while (p != NULL)
    {
        cout<<" "<<p->data<<" -> ";
        p = p->next;
    }
    cout<<"NULL";
}
