#ifdef STACK_H

#include <iostream>

template <typename t>
stack<t>::stack()
{
	head = nullptr; //initialize
	tail = nullptr;
	stackSize=0;
}
template <typename t>
void stack<t>::push(t data)
{
	node<t> *temp = new node<t>(data);

	if(isEmpty())
	{
		head = temp;
		tail = temp;
	}
	else
	{
		temp->next = head; //temp links to head
		head = temp; //temp becomes new head
	}
	stackSize++;
}
template <typename t>
t stack<t>::pop()
{
	t value = t(); //intializes value to default for the data type
	if(isEmpty())
	{
		value = 0;
		std::cout<<"list already empty";
	}
	else if(head==tail)
	{
		value = head->data; //get data
		delete head;  //free up memory
		head = nullptr; //reinitialize
		tail = nullptr;
	}
	else
	{
		value = head->data; //get data
		node<t> *temp= head;//temp is head
		head=head->next; //next value is now head
		delete temp; //free up memory
	}
	return value;
	stackSize--;
}

template <typename t>
bool stack<t>::isEmpty()
{
	if(head==nullptr)
	{
		return true;
	}
	else
	{
		return false;
	}
}
template <typename t>
t stack<t>::top()
{
	if (head!=nullptr)
		return head->data;
	return t();
}
//Basic Display Function
template<typename t>
void stack<t>::display()
{
	node<t> *current=head;
	while(current!=nullptr)
	{
		std::cout<<current->data<<std::endl;
		current=current->next;
	}
}
template <typename t>
int stack<t>::size()
{
	return stackSize;
}

#endif
