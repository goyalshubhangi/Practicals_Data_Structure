
#include<iostream>
#include<stdlib.h>
#include<stdio.h>
using namespace std;

template <class t>
struct node
{
	  node<t>* prev;
	  node<t>* next;
		t data;

	void insertAtBegin(t item);
	void insertAfterX(t item, t x);
	void deleteAfterX(t x);
	void display();
	int search(t x);
	void reverse();
};
node <int> *start=NULL;

template <class t>
void node<t>::insertAtBegin(t item)
{
	struct node<int> *T= (struct node*) malloc(sizeof(struct node));	
	T->data=item;
	T->prev=NULL;
	if(start==NULL)
	{
		T->next=NULL;
		start=T;
	}
	else
	{
	T->next=start;
		start->prev=T;
		start=T;
	}
}

template <class t>
void node<t>::insertAfterX(t item, t x)	
{
	struct node *T= (struct node*) malloc(sizeof(struct node));	
	struct node *p;
	T->data=item;

	//now we'll find x
	p=start;
	while(p!=NULL && p->data!=x)
	{
		//cout<<("\nthis loop runs\n");
		p=p->next;
	}
	if(p->data==x && p->next!=NULL && p->prev!=NULL)
	{
		T->next= p->next;
		T->prev= p;

		p->next=T;
		p->next->next->prev=T;
	}
	else if(p->data==x && p->next==NULL)
	{
		p->next=T;
		T->prev=p;
		T->next=NULL;
	}
	else if(p->data==x && p->prev==NULL)
	{
		p->prev=T;
		T->next=p;
		T->prev=NULL;
		start=T;
	}
}

template <class t>
void node<t>::deleteAfterX(t x)
{
	struct node* T=start;
	while(T->data!=x && T!=NULL)
		T=T->next;
	struct node* temp= T->next;
	T->next=T->next->next;
	T->next->prev=T;
	free(temp);
}

template <class t>
void node<t>::display()
{
	struct node*T;
	T=start;
	while(T!=NULL)
	{
		cout<<T->data<<"->";
		T=T->next;
	}
	cout<<"NULL";
}

template <class t>
int node<t>::search(t x)
{
	struct node*T;
	T=start;
	while(T!=NULL)
	{
		if(T->data==x)
			break;
		T=T->next;
	}
	if(T->data==x)
		return 1;
	else
		return 0;
}

template <class t>
void node<t>:: reverse()
{
	 struct node *temp = NULL;  
     struct node *current = start;
      
     
     while (current !=  NULL)
     {
       temp = current->prev;
       current->prev = current->next;
       current->next = temp;              
       current = current->prev;
     }      
      
     
     if(temp != NULL )
        start = temp->prev;
}

int main()
{
	node<int> n1;
	int ch=0;
	int data,x,t;
	while(1)
	{
		cout<<"\n\nMenu:\n";
		cout<<"1. Insert at begin\n";
		cout<<"2. Insert after x\n";
		cout<<"3. display\n";
		cout<<"4. Delete after element 'x'\n";
		cout<<"5. Search a number\n";
		cout<<"6. Reverse .\n";
		cout<<"7. Exit\n";
		cout<<"Enter your choice: ";
		cin>>ch;

		switch(ch)
		{
			case 1: cout<<"Enter value to be inserted: ";
					cin>>data;
					n1.insertAtBegin(data);
					break;
			case 2: cout<<"Enter value of 'x' after which data will be inserted: ";
					cin>>x;
					cout<<"Enter value to be inserted: ";
					cin>>data;
					n1.insertAfterX(data,x);
					break;
			case 3: n1.display();
					break;
			case 4: cout<<"Enter value of 'x' after which data will be deleted: ";
					cin>>x;
					n1.deleteAfterX(x);
					break;
			case 5: cout<<"Enter no. to search: ";
					cin>>x;
					t=n1.search(x);
					if(t==1)
						cout<<"No. found";
					else
						cout<<"No. not found";
					break;
			case 6: n1.reverse();
					cout<<"Double Linked list is reversed.";
					break;
			case 7: break;

			default: cout<<"\n\n\t\t!!!!Wrong choice!!!!\n";
		}
		if(ch==7)
			break;
	}
}
