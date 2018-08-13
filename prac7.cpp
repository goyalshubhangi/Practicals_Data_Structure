#include<stdlib.h>
#include<iostream>
using namespace std;
//This is stack class, all functions are defined inside this class
template <class t>
class stack
{
	int top;
	public:
		int s[2];
		stack()
		{
			top=-1;
		}
		void push(t item);
		t pop();
};
	template <class t>
	void stack<t>::push(t item)
	{
		if(top>20)
		{
			cout<<("Stack is overflow");
			
		}
		else
		{
			s[++top]=item;
			
		}
	}

	template <class t>
	t stack<t>::pop()
	{
	    if (top < 0)
	    {
	        cout<<("Stack is Underflow");
	        return 0;
	    }
	    else
	    {
	        int y = s[top--];
	        return y;
	    }
	}

int main()
{
	stack<int> obj;
	obj.push(20);
	obj.push(8);
	obj.push(7);

	cout<<obj.pop()<<" popped from Stack\n";
	cout<<obj.pop()<<" popped from Stack\n";
	cout<<obj.pop()<<" popped from Stack\n";
return 0;
}
