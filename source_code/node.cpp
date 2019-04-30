#include "node.h"
using namespace std;


	Node::Node(read x, Node* ptr)
	{
		data = x;
		next = ptr;
	}
