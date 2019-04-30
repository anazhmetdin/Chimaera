#ifndef NODE_H
#define NODE_H
#include <iostream>
#include "read_class.h"
using namespace std;

class Node
{
public:
	read data;
	Node* next;

	Node(read x, Node* ptr = NULL);
};

#endif
