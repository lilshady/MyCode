#include <queue>
#include <stack>
#include <iostream>
using std::queue;
using std::stack;
using std::cout;
using std::endl;

template <typename T>
bool VerifyStackOrder(queue<T> push_order,queue<T> pop_order)
{
	bool isPossible = false;
	stack<T> data_stack;
	while (!pop_order.empty())
	{   
		
		T data = pop_order.front();
		cout<<"the data now is"<<data<<endl;
		pop_order.pop();
		while (data_stack.empty() || data != data_stack.top())
		{  
			if (push_order.empty())
			{  
				cout<<"break1"<<endl;
			    break;
			}
			cout<<"then we push "<<push_order.front()<<endl;
			data_stack.push(push_order.front());
			push_order.pop();
		}
		if (data != data_stack.top())
		{
			cout<<"break2"<<endl;
		    break;
		}

		data_stack.pop();
	}

	if (data_stack.empty() && pop_order.empty())
		isPossible = true;

	return isPossible;
}

int main()
{  
	queue<int> a;
	queue<int> b;
	for (int i = 1; i<6; ++i)
	{
		a.push(i);
	}
	b.push(4);
	b.push(3);
	b.push(5);
	b.push(1);
	b.push(2);

	cout<<VerifyStackOrder(a,b)<<endl;
	system("pause");
}