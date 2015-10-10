#ifndef NODE_H
#define NODE_H

template <typename t>
class node
{
public:
	node(t node_data);
	node();
	node* next; //pointer to next value
	t data;
};

#include "node_Implementation.hpp"
#endif 

