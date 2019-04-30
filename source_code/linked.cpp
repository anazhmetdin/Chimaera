#include "linked.h"
#include <iostream>
using namespace std;

linked::linked(read x){
	head = new Node(x);
	tail = head;
}

bool linked::isEmpty()
{
	if (head == NULL){return true;}
	else{return false;}
}

void linked::addToHead(read x)
{
	head = new Node(x, head);
	if (tail == NULL)	{tail = head;}
}

void linked::addToTail(read x)
{
	if (tail != NULL)
	{
		tail->next = new Node(x);
		tail = tail->next;
	}
	else if (tail == NULL){
		tail = new Node(x);
		head = tail;
	}
}
