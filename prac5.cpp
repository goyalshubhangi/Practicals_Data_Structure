#include<iostream>
#include<stdlib.h>
#include<stdio.h>
using namespace std;
template <class t>
struct LL
{
	LL<t> *next;
	t data;
	void insertAtBegin(t item);
	void insertAtLast(t item);
	void deleteFirst();
	void display();
	int search(t x);
	void reverse();
	
};
LL<int> *start=NULL;
LL<int> *last=NULL;
template<class t>
void LL<t>::insertAtBegin(t item)
{
struct LL<int> *T=(struct LL*)malloc(sizeof(struct LL));
T->data=item;
if(start==NULL)	
{
	T->next=T;
	start=T;
	last=T;
}
else
{
T->next=start;
start=T;
last->next=T;
}
 } 
 template<class t>
 void LL<t>::insertAtLast(t item)
 {
 	struct LL *T=(struct LL*)malloc(sizeof(struct LL));
 	T->data=item;
 	if(start==NULL)
 	{
 		T->next=T;
 		start=last=T;
	 }
	 else
	 {
	 
	 last->next=T;
	 last=T;
	 last->next=start;
 }
}
template<class t>
void LL<t>::deleteFirst()
{
	struct LL*T=start;
	if(T==NULL)
	{
		cout<<"\nList is empty";
		
	}
	else
	{
		T=start;
		start=start->next;
		cout<<"\nElement Deleted is="<<T->data;
		last->next=start;
		free(T);
		
	}
}
template <class t>
void LL<t>::display()
{
	struct LL*T;
	T=start;
	while(T->next!=start)
	{
		cout<<T->data<<"->";
		T=T->next;
	}
	cout<<"NULL";
	
}
template <class t>
int LL<t>::search(t x)
{
	struct LL*T;
	T=start;
	while(T->next!=start)
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
void LL<t>:: reverse()
{
	LL<t> *a,*b,*temp;
      a=start;
      b=a->next;
      temp=b->next;
      a->next=NULL;
      while(temp!=start)
      {
           
           b->next=a;
           a=b;
           b=temp;
           temp=temp->next;
    
      }
      b->next=a;
      start->next=b;
      start=start->next;
 }
int main()
{
	LL<int> n1;
	int ch=0;
	int data,x,t;
	while(1)
	{
		cout<<"\n\nMenu:\n";
		cout<<"1. Insert at begin\n";
		cout<<"2. Insert at last\n";
		cout<<"3. display\n";
		cout<<"4. Delete first \n";
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
			case 2:	cout<<"Enter value to be inserted: ";
					cin>>data;
					n1.insertAtLast(data);
					break;
			case 3: n1.display();
					break;
			case 4:n1.deleteFirst();
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
					cout<<"Circular Linked list is reversed.";
					break;
			case 7: break;

			default: cout<<"\n\n\t\t!!!!Wrong choice!!!!\n";
		}
		if(ch==7)
			break;
	}
}

