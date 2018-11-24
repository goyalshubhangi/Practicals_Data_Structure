#include<iostream>
using namespace std;

int ar[5];
int front=0,rear=-1;
template <class t>
void enque(t data)
{
if(front==4)
{
	cout<<"\nFULL";
}
else
{
	rear++;
	ar[rear]=data;
}
}
template <class t>
void deque()
{
	if(front==-1)
	{
		cout<<"\nEMPTY";

	}
	else
	{
		t data=ar[front];
		front++;
		int j=front-rear+1,m=1;
		if(j>=0)
		{
			for (int i = 0; i <=j; ++i)
			{
				ar[i]=ar[m];
				m++;
			}
			front=front-1;
			rear=rear-1;
			cout<<"Element taken out"<<data;
					}
					else
						cout<<"\nnEMPTY";
	}
}


	void Display()
	{
		if(rear!=-1)
		{
			cout<<"\nQueue id :";
			for (int i = rear;i!=front;--i)
			{
				/* code */cout<<ar[i]<<"\n";
			}
			cout<<ar[front]<< "\n ";
		}
	}



int main(int argc, char const *argv[])
{
	int ch,data;
	char choice;

	do{
	cout<<"\n1.Enqueue\n2.Dequeue\n3.Display\n4.Exit\n";
	cin>>ch;
	switch(ch)
	{
		case 1:
		cout<<"\n\tEnter element to be inserted:";
		cin>>data;
		enque(data);
		break;
		case 2:
		deque();
		break;
		case 3:
		Display();
		break;
		case 4:
		break;
	}
	cout<<"\n\tDo you want to continue?(y/n)";
	cin>>choice;
}while(choice=='y'||choice=='Y');
	return 0;
}