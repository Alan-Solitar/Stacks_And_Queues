#ifndef STACK_H
#define STACK_H
#include "node.h"
template <typename t>
class stack
{
private:
	int stackSize;
	node<t> *head;
	node<t> *tail;
public:
	stack();
	void push(t data);
	t pop();
	t top();
	bool isEmpty();
	void display();
	int size();

};

#include "stack_implementation.hpp"

#endif
