#ifndef QUEUE_H
#define QUEUE_H

#include "node.h"

template<typename t>
class queue
{
private:
	int x;
	int queueSize;
	node<t> *head;
	node<t> *tail;

public:
	int retX();
	queue();
	void enqueue(t data);
	t dequeue();
	bool isEmpty();
	int size();
	void display();
};

#include "queue_implementation.hpp"
#endif 
