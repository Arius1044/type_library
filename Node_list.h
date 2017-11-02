#include <iostream>
template <typename Type>
struct Node
{

	Type data;
	Node *next;

	Node(Type _data_)
	{
		data = _data_;
		next = NULL;
	}
};

