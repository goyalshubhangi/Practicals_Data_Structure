#include<iostream>
using namespace std;
struct node
{
	int data;
	node *prev;
	node *next;
	
	int size;
	
}*front,*rear;
node *getNode(int data)
	{
	node *newNode=(node *)malloc(sizeof(node));
	newNode->data=data;
	newNode->prev=newNode->next=NULL;
	}
void insert_front(int data)
{
	node *newNode=getNode(data);
	if(newNode==NULL)
	{
		cout<<"\nOVERFLOW";
	}
	else
	{
		newNode->next=front;
		front->prev=newNode;
		front=newNode;
	}
}
void insert_rear(int data)

{
	node *newNode=getNode(data);
	if(newNode==NULL)
	{
		cout<<"\nOVERFLOW";
	}
	else
	{
		if(rear==NULL)
		{
			front=rear=newNode;
		}else
		{
			newNode->prev=rear;
			rear->next=newNode;
			rear=newNode;
		}
	}
}
void delete_front()
{ 
        node *temp = front; 
        front = front->next;  
        if (front == NULL) 
            rear = NULL; 
        else
            front->prev = NULL; 
        free(temp); 
    } 


void delete_rear()
{ 
        node *temp = rear; 
        rear = rear->prev; 
  
        if (rear == NULL) 
            front = NULL; 
        else
            rear->next = NULL; 
        free(temp); 
 
   }
   void Display()
   {
   		cout<<front->data<<"\n";
   		cout<<rear->data<<"\n";
   	
   } 


int main(int argc, char const *argv[])
{
	int ch,data;
	char choice;

	do{
	cout<<"\n1.Insert at rear\n2.Delete at rear\n3.Insert at front\n4.Delete at front\n5.Display\n6.Exit";
	cin>>ch;
	switch(ch)
	{
		case 1:
		cout<<"\n\tEnter element to be inserted:";
		cin>>data;
		insert_rear(data);
		break;
		case 2:
		delete_rear();
		break;
		case 3:
		cout<<"\n\tEnter element to be inserted:";
		cin>>data;
		insert_front(data);
		break;
		case 4:
		delete_front();
		break;
		case 5:
		Display();
		break;
		case 6:
		break;
	}
	cout<<"\n\tDo you want to continue?(y/n)";
	cin>>choice;
}while(choice=='y'||choice=='Y');
	return 0;
}
