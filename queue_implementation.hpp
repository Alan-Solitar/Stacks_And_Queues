#ifdef QUEUE_H
#include <iostream>

template<typename t>
queue<t>::queue()
{
	head = nullptr;
	tail = nullptr;
	queueSize = 0;
}

template<typename t>
void queue<t>::enqueue(t data)
{
	node<t> *temp = new node<t>(data);

	
	if (isEmpty())
	{
		head = temp;
		tail = temp;
	}
	else
	{
		tail->next = temp; //previous value will now point to temp
		tail = temp; //now becomes tail
		
	}
	queueSize++;
}

template<typename t>
t queue<t>::dequeue()
{
	t value = t(); //intializes value to default for the data type
	if (isEmpty())
	{
		std::cout << "the queue is empty" << std::endl;
	}
	else if (head == tail)
	{
		value = head-> data; //get data
		delete head; //delete pointer
		head = nullptr; //reinitialize
		tail = nullptr;
	}
	else
	{
		value = head->data; //get data
		node<t> *temp = head; //create pointer to current  head
		head = head->next; //make next the new head
		delete temp; //free up memory
	
	}
	queueSize--; //update size
	return value;
}
template<typename t>
bool queue<t>::isEmpty()
{
	if (head == nullptr)
		return true;
	else
		return false;
}
template < typename t >
int queue<t>::size()
{

	return queueSize;
}
//Basic Display Function
template <typename t>
void queue<t>::display()
{
	node<t> *current = head;
	while (current != nullptr)
	{
		std::cout << current->data <<" ";
		current = current->next;
	}
	std::cout<<"\n"<<std::endl;
}
#endif

