#ifndef LINKED_H
#define LINKED_H
#include "node.h"

class linked
{
public:
    Node* head;
  	Node* tail;

  linked(read x);
  bool isEmpty();
	void addToHead(read x);
	void addToTail(read x);
};

#endif
