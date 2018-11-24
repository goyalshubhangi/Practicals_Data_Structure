#include<iostream>
#include <stdio.h>
#include<stdlib.h>
using namespace std;
template <class t>
struct node
{
 t data;
 node<t> *next;
 void createList(t n);
 void deletion();
 void insert_data(t data);
 void Display();
};
struct node<int> *start;

template <class t>

void node<t>::createList(t n)
{
struct node<int> *newNode,*temp;
t data,i;
start=(struct node*)malloc(sizeof(struct node));
if(start==NULL)
{
	cout<<"\nUnable to allocate memory";

}
else
{
	cout<<"\n\tEnter the data of node 1:";
	cin>>data;
	start->data=data;
	start->next=NULL;
	temp=start;
	for(i=2;i<=n;i++)
	{
		newNode=(struct node*)malloc(sizeof(struct node));
		if(newNode==NULL)
		{
			cout<<"\nUnable to allocate memory";

		}
		else
		{
			cout<<"\n\tEnter the data at node"<<i<<":";
			cin>>data;
			newNode->data=data;
			newNode->next==NULL;
			temp->next=newNode;
			temp=temp->next;
		}
	}
cout<<"\n\n\tSINGLY LINKED LIST CREATED";
}
}
template <class t>
void node<t>::Display()
{
	struct node<t> *temp;
	{
		
	};
	if(start==NULL)
	{
		cout<<"\nLinked List is Empty";
	}
	else{
	temp=start;
	while(temp!=NULL)
	{
		cout<<"\nData ="<<temp->data;
		temp=temp->next;
	}
}
}

template <class t>
void node<t>::insert_data(t data)
{
	struct node<t> *p;
	p=(struct node*)malloc(sizeof(struct node));
	if(p==NULL)
	{
		cout<<"\nUnable to allocate memory";

	}
	else
	{
		p->data=data;
		p->next=start;
		start=p;
		cout<<"\n\nData Inserted Successfully";
	}
}
template <class t>
void node<t>::deletion()
{
	struct node<t> *temp = start;
	if(start!=NULL)
	{
		start=start->next;
		free(temp);
		cout<<"\n\nThe List is Modified";
	};
}


int main()
{
	int n,data,ch;
	char choice;
	node<int> n1;
	cout<<"Enter the number of nodes:";
	cin>>n;
	n1.createList(n);
	cout<<"\nData in the list:";
	n1.Display();
	do{
		cout<<"\n1.Insert_at_beginning\n2.Delete\n3.Display\n";
		cout<<"\nEnter your choice:";
		cin>>ch;
		switch(ch)
		{
			case 1:
			cout<<"\nEnter data to be Inserted:";
			cin>>data;
			n1.insert_data(data);
			break;
			case 2:
			n1.deletion();
			break;
			case 3:
			n1.Display();
			break;
			case 4:
			break;
			default:
			cout<<"Invalid Choice";
			break;
		}
		cout<<"\nDo you want to continue?(y/n)";
		cin>>choice;

	}while(choice=='y'||choice=='Y');

}